void sigfoxConfig() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Starting...");

  // Check TD1208 communication
  if (!akeru.begin())
  {
    Serial.println("TD1208 KO");
    while (1);
  }

  //akeru.echoOn(); // uncomment this line to see AT commands
}


void sigfoxSend() {
  int sensorValue = analogRead(A0);

  // Trace on serial console
  Serial.println(sensorValue);

  // convert to hexadecimal before sending
  String data = akeru.toHex(sensorValue);

  // Send in the mighty internet!
  // akeru.sendPayload() returns 0 if message failed.
  if (akeru.sendPayload(data))
  {
    Serial.println("Message sent !");
  }

  // Wait for 10 minutes.
  // Note that delay(600000) will block the Arduino (bug in delay()?)
  for (int second = 0; second < 600; second++)
  {
    delay(1000);
  }
}


void bmp280Config(){
    Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  
  if (!bmp.begin()) {  
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}


void bmp280Values(){
      Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); // this should be adjusted to your local forcase
    Serial.println(" m");
    
    Serial.println();
    delay(2000);
}


