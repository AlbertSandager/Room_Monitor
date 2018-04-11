void sigfoxConfig() {
  Serial.begin(9600);
  Serial.println("Starting Sigfox-module...");

  if (!akeru.begin())
  {
    Serial.println("TD1208 KO");
    while (1);
  }
}


void bmp280Config() {
  Serial.begin(9600);
  Serial.println(F("Starting BMP280..."));

  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}


void sigfoxSend() {
  String p = akeru.toHex(bmp.readPressure());
  String t = akeru.toHex(bmp.readTemperature());

  String msg = p + t; // Put everything together

  if (akeru.sendPayload(msg))
  {
    Serial.println("Message sent!");
  }

  /*
    // Wait for 10 minutes
    for (int second = 0; second < 600; second++)
    {
      delay(1000);
    }
  */

  // Wait for 24 hours.
  for (int second = 0; second < 86400; second++)
  {
    delay(1000);
  }


}
