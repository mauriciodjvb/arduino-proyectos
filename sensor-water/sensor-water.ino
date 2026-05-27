
int leds [] = {8,9,10};
int water = A0;
float valor = 0;
int nivel = 0;
int buz = 4;

void led(){
 valor = analogRead(water);
 nivel = map(valor,0,1023,0,300);
  for(int i = 0; i < 3; i++){
    digitalWrite(leds[i], LOW); 
  }

 if(nivel > 200){
  digitalWrite(leds[2], HIGH);  
  tone(buz, 4000);
} else if(nivel > 100){
  digitalWrite(leds[1], HIGH);  
  noTone(buz);
} else {
  digitalWrite(leds[0], HIGH);  
  noTone(buz);
}



}

void setup() {
  pinMode(buz,OUTPUT);
 for(int i = 0; i < 3; i++){
  pinMode(leds[i],OUTPUT);
 }
 Serial.begin(9600);

}

void loop() {
led();
Serial.print("Nivel: ");
Serial.println(nivel);
delay(200);



}
