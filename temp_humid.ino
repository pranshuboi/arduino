#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHT temperature, humidity test");
dht.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
delay(10000);
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);
if (isnan(h) || isnan(t) || isnan(f))
{
  Serial.println("failed to read from DHT sensor!");
  return;
}
float hif = dht.computeHeatIndex(f,h);
float hic = dht.computeHeatIndex(t,h,false);

Serial.print("Humidity : ");
Serial.print(h);
Serial.print("%\t");
Serial.print("Temperature : ");
Serial.print(t);
Serial.print(" degrees Celsius\t");
Serial.print(f);
Serial.print(" degrees Fahrenheit\t");
Serial.print("Heat Index: ");
Serial.print(hic);
Serial.print(" degrees Celsius\t");
Serial.print(hif);
Serial.println(" degrees Fahrenheit\t");
}
