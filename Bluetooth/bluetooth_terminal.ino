#include <DHT.h>
#include <SoftwareSerial.h>


// Pin na kojem je DHT senzor
DHT dht(7, DHT11);
SoftwareSerial mySerial(9, 10); // RX, TX


void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  dht.begin();
}


void loop() {
  // Čekaj nekoliko sekundi između očitavanja
  delay(2000);  


  // Deklaracija varijabli za temperaturu i vlažnost
  float temperatura;
  float vlaznost;


  // Očitavanje podataka sa senzora
  temperatura = dht.readTemperature();
  vlaznost = dht.readHumidity();


  // Provjera da li su podaci ispravno očitani
  if (isnan(temperatura) || isnan(vlaznost)) {
    mySerial.println("Greška pri očitavanju podataka sa senzora!");
    return;
  }


  // Ispisivanje podataka
  mySerial.println("Podaci o okruženju:");
  mySerial.print("Temperatura: ");
  mySerial.print(temperatura);
  mySerial.println("°C");


  mySerial.print("Vlažnost: ");
  mySerial.print(vlaznost);
  mySerial.println("%");


  mySerial.println("--------------------------");
}

