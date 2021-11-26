/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor1;
VL53L0X sensor2;
VL53L0X sensor3;

#define shutdown1 A3
#define shutdown2 A2
#define shutdown3 A1

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  pinMode(shutdown1, OUTPUT);
  pinMode(shutdown2, OUTPUT);
  pinMode(shutdown3, OUTPUT);
  
  // reset all VL53
  digitalWrite (shutdown1, LOW);
  digitalWrite (shutdown2, LOW);
  digitalWrite (shutdown3, LOW);

  // init 1 sensor
  digitalWrite (shutdown1, HIGH);
  delay (100);  /// some wait
  sensor1.setAddress(45);
  delay (100);  /// some wait
  sensor1.setTimeout(500);
  if (!sensor1.init())
  {
    Serial.println("Failed to detect and initialize sensor 1!");
    while (1) {}
  }


  // init 2 sensor
  digitalWrite (shutdown2, HIGH);
  delay (100);  /// some wait
  sensor2.setAddress(46);
  delay (100);  /// some wait
  sensor1.setTimeout(500);
  if (!sensor2.init())
  {
    Serial.println("Failed to detect and initialize sensor 2!");
    while (1) {}
  }

  // init 3 sensor
  digitalWrite (shutdown3, HIGH);
  delay (100);  /// some wait
  sensor3.setAddress(47);
  delay (100);  /// some wait
  sensor3.setTimeout(500);
  if (!sensor3.init())
  {
    Serial.println("Failed to detect and initialize sensor 2!");
    while (1) {}
  }

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor1.startContinuous();
  sensor2.startContinuous();
  sensor3.startContinuous();
}

void loop()
{
  Serial.print(sensor1.readRangeSingleMillimeters()); Serial.print("  ");
  
  Serial.print(sensor2.readRangeSingleMillimeters()); Serial.print("  ");
 
  Serial.print(sensor3.readRangeSingleMillimeters()); Serial.println("  ");
 
  Serial.println("-----");
  delay (100);

}
