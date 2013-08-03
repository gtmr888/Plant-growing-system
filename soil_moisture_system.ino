


//parts:
//x2 arduino soil moisture sensor(hygrometer)
//x1 Arduino uno
//x1 relay
//x1 water pump
//x1 DHT11 humidity and temp sensor 
//requires the Dht library sorry i couldn't provide a linl

//reads moisture, temp, and humidity to the serial port.
//waters the plants if both the moisture sensor reads "dry".


//initialize library
#include<DHT.h>
//pin for reading 
#define DHTPIN 12
// this library requires to give the model # of sensor DHT11 or DHT22
#define DHTTYPE DHT11
//initialize object parameters : TYPE object(pin#, model#);
DHT dht(DHTPIN, DHTTYPE);
int moist = 0;
int moist2 = 1;
int dry = 700;
int wet = 300;
int maxh = 600;
int minh = 500;
float hum = 2;
float temp = 3;
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(13,OUTPUT);
}

void loop() {
  moist = analogRead(A0);
  moist2 = analogRead(A1);
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("moist:");
  Serial.println(moist);
  delay(1000);
  Serial.print("moist2:");
  Serial.println(moist2);
  

  
if (moist >= dry && moist2 >= dry) {

    digitalWrite(13,HIGH);
  }
  
 else {
   digitalWrite(13,LOW);
 }
delay(1000);
if (isnan(hum) || isnan(temp)) {
  Serial.println("failed");
}
else {
Serial.print("humidity:");
Serial.print(hum);
Serial.print("%\t");
Serial.print("Temperature:");
Serial.print(temp);
Serial.println("C");
delay(1000);
}
}
