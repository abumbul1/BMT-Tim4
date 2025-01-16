#include <DHT.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <Ethernet.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// Pin na kojem je DHT senzor
DHT dht(7, DHT11);
SoftwareSerial mySerial(9, 10); // RX, TX

// MAC adresa i IP adresa za Ethernet shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // MAC adresa shielda (unikatna za vaš uređaj)
IPAddress ip(100, 100, 129, 22);                     // Statička IP adresa za Arduino
IPAddress server(100, 100, 129, 70);                 // IP adresa servera sa PHP skriptom

// Ethernet klijent
EthernetClient client;

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(8,OUTPUT);

  dht.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
// Pokretanje Ethernet konekcije
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Greška pri pokretanju Ethernet konekcije. Provjerite kablove.");
    Ethernet.begin(mac, ip); // Koristi statičku IP ako DHCP nije dostupan
  }
}
int blkontrola=0;
void loop() {
  // Čekaj nekoliko sekundi između očitavanja
  delay(2000);  


  // Deklaracija varijabli za temperaturu i vlažnost
  float temperatura;
  float vlaznost;


  // Očitavanje podataka sa senzora
  temperatura = dht.readTemperature();
  vlaznost = dht.readHumidity();
 // Serial.print(temperatura);
 


  // Provjera da li su podaci ispravno očitani
  if (isnan(temperatura) || isnan(vlaznost)) {
    mySerial.println("Greška pri očitavanju podataka sa senzora!");
    return;
  }
  if (client.connect(server, 80)) { // Povezivanje na server, port 80

  // Serial.println("Povezano na server.");
  
    client.print("GET /INSERT.php?temperatura=");
    client.print(temperatura);
    client.print("&vlaga=");
    client.print(vlaznost);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.println();
    client.stop();

  // Ispisivanje podataka
  
  mySerial.println("Podaci o okruženju:");

  mySerial.print("Temperatura: ");
  mySerial.print(temperatura);
  mySerial.println("°C");


  mySerial.print("Vlažnost: ");
  mySerial.print(vlaznost);
  mySerial.println("%");


  mySerial.println("--------------------------");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperatura);
  display.println("°C");
  display.setCursor(0, 10);  
  display.print("Vlaga: ");
  display.print(vlaznost);
  display.println(" %");
  display.display();
  delay(5000);
   }
  digitalWrite(8,HIGH);
  delay(10000);
  digitalWrite(8,LOW);

}
