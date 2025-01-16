# Arduino bazirani sistem za prenos i spremanje senzorskih podataka u realnom vremenu

## Opis projekta
Ovaj projekat implementira sistem za prenos podataka prikupljenih sa senzora za temperaturu i vlažnost zraka. Podaci se očitavaju pomoću senzora **DHT11**, prikazuju na **OLED displeju**, te šalju putem **Bluetooth HC05** modula na mobilni uređaj. Također, sistem omogućava prenos izmjerenih podataka na bazu podataka koja se nalazi na lokalnom serveru putem **Ethernet shield** modula. Projekat uključuje i korištenje **VLC (Visible Light Communication)** tehnologije. Kada se podaci unesu u bazu, **LED dioda** zasvijetli na 10 sekundi, dok **fotorezistor** detektuje svjetlost sa diode i pokreće **WiFi ESP8266** modul koji šalje e-mail obavijest.

Poruka u e-mailu sadrži: _Senzor je očitao temperaturu i vlažnost. Vrijednosti su unijete u lokalnu bazu. Provjerite očitanje bluetooth -a._

## Ciljevi i funkcionalnosti
1. **Prikupljanje podataka** o temperaturi i vlažnosti zraka.
2. **Prikaz podataka** na OLED displeju u realnom vremenu.
3. **Prenos podataka** na mobilni uređaj putem Bluetooth modula HC05.
4. **Slanje podataka** na lokalni server putem Ethernet shield modula.
5. **Skladištenje podataka** u bazi podataka za kasniju analizu.
6. **Aktivacija LED diode** nakon uspješnog unosa podataka u bazu.
7. **Detekcija svjetlosti** pomoću fotorezistora i automatsko slanje e-mail obavijesti putem WiFi ESP8266 modula.

## Kako se koristi
### Potreban hardver:
- **Arduino Mega 2560**
- **DHT11** senzor za temperaturu i vlažnost
- **OLED displej** (128x64 px)
- **HC05 Bluetooth modul**
- **Ethernet shield**
- **ESP8266 WiFi modul**
- **LED dioda**
- **Fotorezistor**
- Mobilni uređaj sa Bluetooth podrškom
- Lokalni server sa bazom podataka (**MySQL**)

### Potrebne biblioteke:
Sljedeće Arduino biblioteke treba instalirati:
- `DHT.h`: Za rad sa DHT11 senzorom za očitavanje temperature i vlažnosti zraka.
- `SPI.h`: Omogućava komunikaciju sa uređajima putem SPI protokola (koristi se za Ethernet shield).
- `SoftwareSerial.h`: Omogućava korištenje dodatnih serijskih portova za komunikaciju.
- `Wire.h`: Za I2C komunikaciju sa uređajima kao što su OLED displeji.
- `Adafruit_GFX` i `Adafruit_SSD1306`: Za rad sa OLED displejima.
- `ESP8266WiFi`: Za upravljanje WiFi modulom ESP8266.
- `Ethernet.h`: Omogućava rad sa Ethernet shieldom i povezivanje putem LAN mreže.
- `ESP_Mail_Client.h`: Za slanje e-mail obavijesti putem SMTP protokola.

### Korištenje:
1. Postavite potrebne komponente prema dijagramu ožičenja (vidi sliku ispod).
   ![Cirkit_shema](https://github.com/user-attachments/assets/97a414ea-088a-4aec-9c05-139d463e0b69)
3. Povežite **Arduino Mega** s računarom putem kabla.
4. Učitajte kod na Arduino pomoću **Arduino IDE-a**.
5. Otvorite aplikaciju na mobilnom uređaju koja može primati Bluetooth podatke.
6. Konfigurišite lokalni server za prijem podataka putem **Ethernet veze**.
7. Provjerite **Bluetooth vezu** sa mobilnim uređajem i **Ethernet konekciju** sa serverom.
8. Kada **LED dioda** zasvijetli nakon unosa podataka u bazu, **fotorezistor** će detektovati svjetlost i aktivirati **WiFi ESP8266** modul koji šalje e-mail obavijest.

## Upute za instalaciju
1. Preuzmite i instalirajte **Arduino IDE** sa [zvanične stranice](https://www.arduino.cc/en/software).
2. Dodajte potrebne biblioteke putem **Arduino Library Managera**.
3. Učitajte kod u **Arduino Mega**.
4. Povežite sve komponente prema priloženom dijagramu ožičenja.
5. Konfigurišite lokalni server i bazu podataka (pomoću **XAMPP**).
6. Konfigurišite **SMTP postavke** za slanje e-mail obavijesti pomoću **WiFi ESP8266** modula.

## Slike 
<figure>
  <img src="https://github.com/user-attachments/assets/3d25e486-8305-498a-944f-0a984150282d" alt="BMT-BLOKSHEMA" width="400">
  <figcaption>Slika 1: Blok dijagrama povezivanja komponenti</figcaption>
</figure>

<figure>
  <img src="https://github.com/user-attachments/assets/e270ae53-9a43-47c1-9f4c-dceff649e15c" alt="praktična implementacija" width="400">
  <figcaption>Slika 2: Praktična implementacija sistema</figcaption>
</figure>


