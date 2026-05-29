#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN , DHTTYPE);
int leds [] = {8,9};
int buz = 4;

void sensor(){
  float temp = dht.readTemperature();
  float humedad = dht.readHumidity();
     if(temp > 25 ){
    digitalWrite(leds[0], HIGH);
    tone(buz,4000);

  }else if(temp < 25){
    digitalWrite(leds[1], HIGH);
    noTone(buz);

  }    
  

 
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  Serial.println("----------");
  delay(2000);
}

void setup(){
  pinMode(buz,OUTPUT);

  for(int i = 0; i < 2;i++){
    pinMode(leds[i],OUTPUT);

  }

 Serial.begin(9600);
 dht.begin();
}
void loop(){
  sensor();


}