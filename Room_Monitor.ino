#include <Akeru.h>

#define TX 5
#define RX 4

Akeru akeru(RX, TX);

void setup() {

  sigfoxConfig();

}

void loop() {

  sigfoxSend();
  waitaDay();

}


