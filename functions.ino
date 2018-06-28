void sigfoxConfig() {
  Serial.begin(9600);
  Serial.println("Starting Sigfox-module...");

  if (!akeru.begin())
  {
    Serial.println("TD1208 KO");
    while (1);
  }
}

void temperaturesensor() {

}

void sigfoxSend() {
  String p = akeru.toHex(255);
  String t = akeru.toHex(255);

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

    // Wait for 24 hours.
    for (int second = 0; second < 86400; second++)
    {
    delay(1000);
    }
  */
}


void waitaDay() {
  long waitTime = 86400000;
  unsigned long startT, endT;
  startT = millis();
  while (endT - startT <= waitTime) {
    endT = millis();
  }
}

