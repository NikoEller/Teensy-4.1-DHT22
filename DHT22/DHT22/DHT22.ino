#include "DHT.h" //DHT Bibliothek laden
#include <SD.h>
#include <SPI.h>

#define DHTPIN 14 //Der Sensor wird an PIN 14 angeschlossen    

#define DHTTYPE DHT22    // Es handelt sich um den DHT22 Sensor

DHT dht(DHTPIN, DHTTYPE); //Der Sensor wird ab jetzt mit „dth“ angesprochen
Sd2Card card;
SdVolume volume;
SdFile root;
File myFile;
const int chipSelect = BUILTIN_SDCARD;
const int buildInLEDPin = 13;


const String fileName = "data.txt";





void setup() {
  Serial.begin(9600); //Serielle Verbindung starten
  sdCardSetup();
  dht.begin(); //DHT11 Sensor starten
}

void sdCardSetup(){
    Serial.println("Initializing SD card...");

  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop() {
  
  delay(2000); //Zwei Sekunden Vorlaufzeit bis zur Messung (der Sensor ist etwas träge)

  
  float Luftfeuchtigkeit = dht.readHumidity(); //die Luftfeuchtigkeit auslesen und unter „Luftfeutchtigkeit“ speichern
  
  float Temperatur = dht.readTemperature();//die Temperatur auslesen und unter „Temperatur“ speichern
  
  Serial.println(Temperatur);
  Serial.println(Luftfeuchtigkeit); //die Dazugehörigen Werte anzeigen

}
