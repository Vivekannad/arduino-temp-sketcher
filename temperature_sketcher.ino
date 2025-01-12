#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8  // Pin connected to the DS18B20

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);  // Start Serial communication
}

void loop() {
  sensors.requestTemperatures();  // Request temperature readings from the sensor

  Celsius = sensors.getTempCByIndex(0);  // Get temperature in Celsius
  Fahrenheit = sensors.toFahrenheit(Celsius);  // Convert Celsius to Fahrenheit

  Serial.print("Temperature: ");
  Serial.print(Celsius);
  Serial.print(" °C / ");
  Serial.print(Fahrenheit);
  Serial.println(" °F");

  delay(1000);  // Wait for 1 second before the next reading
}
