#include <SPI.h>
#include <LoRa.h>

int counter = 0;
float sensor_read_pin=A0;
void setup() {
  pinMode(sensor_read_pin, INPUT); //initialize ldr sensor as INPUT
    
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");
  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {


  int data=analogRead(sensor_read_pin);
    Serial.print("ldr reading=");
    Serial.println(data);
  // send packet
  LoRa.beginPacket();
  LoRa.print(data);
//  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
