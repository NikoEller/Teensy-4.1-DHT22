#include "DHT.h" //DHT Bibliothek laden

#define DHTPIN 14 //Der Sensor wird an PIN 14 angeschlossen    

#define DHTTYPE DHT22    // Es handelt sich um den DHT22 Sensor

DHT dht(DHTPIN, DHTTYPE); //Der Sensor wird ab jetzt mit „dth“ angesprochen



void setup() {
  Serial.begin(9600); //Serielle Verbindung starten

  dht.begin(); //DHT11 Sensor starten
}

void loop() {
  
}
