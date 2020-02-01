const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pin = 2; pin < 5; pin++) {
    pinMode(pin, 1);
    digitalWrite(pin, 0);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  const int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  float temperature = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  if (temperature >= baselineTemp+2) digitalWrite(2, 1);
  if (temperature >= baselineTemp+4) digitalWrite(3, 1);
  if (temperature >= baselineTemp+6) digitalWrite(4, 1);

  delay(1);
  
}
