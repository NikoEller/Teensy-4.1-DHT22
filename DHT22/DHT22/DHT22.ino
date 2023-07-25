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


const char fileName[] = "data.txt";
float humidity, temperature;




void setup() {
  Serial.begin(9600); //Serielle Verbindung starten
  sdCardSetup();
  dht.begin(); //DHT11 Sensor starten

  //removes the data if there is already one
  SD.remove(fileName);


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
  
  delay(2000); //delay 2 secounds for the sensor

  humidity = dht.readHumidity(); //read humidity
  
  temperature = dht.readTemperature();//die Temperatur auslesen und unter „Temperatur“ speichern
  
  saveData(temperature,humidity);

}


void saveData(float temperature,float humidity){

  char dataChar[13] = "";

  char tempBuffer[5];
  dtostrf(temperature,4,2,tempBuffer);

  char humidityBuffer[5];
  dtostrf(humidity,4,2,humidityBuffer);

  strcat(dataChar,tempBuffer);
  strcat(dataChar, " - ");
  strcat(dataChar,humidityBuffer);

  Serial.println(dataChar);
  myFile = SD.open(fileName, FILE_WRITE);
  //if there was no problem opening the file => wirte to it
  if (myFile) {
    Serial.print("writing to");
    Serial.println(fileName);
    myFile.println(dataChar);
    //colse the file
    myFile.close();
  } else {
    //if the file couldn't be opend => print error message
    Serial.print("error oppening the file :");
    Serial.println(fileName); 
  }
}
