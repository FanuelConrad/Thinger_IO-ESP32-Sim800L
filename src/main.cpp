#define _DISABLE_TLS_

// Select your modem:
#define TINY_GSM_MODEM_SIM800

// uncomment line for debug
#define _DEBUG_

// Can be installed from Library Manager or https://github.com/vshymanskyy/TinyGSM
#include <TinyGsmClient.h>
#include <ThingerTinyGSM.h>

HardwareSerial Serial4(2);

#define USERNAME "LCSolutions"
 #define DEVICE_ID "ESP32"
 #define DEVICE_CREDENTIAL "pn5mjoqsyow3bVJ9"

// use your own APN config
#define APN_NAME "safaricom"
#define APN_USER "saf"
#define APN_PSWD "data"

// set your cad pin (optional)
#define CARD_PIN "2535"

#define LED_BUILTIN 13

ThingerTinyGSM thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL, Serial4);
// ThingerESP32OTA ota(thing);

void setup() {
  // uncomment line for debug
   Serial.begin(115200);

  Serial4.begin(115200);

  // set APN (you can remove user and password from call if your apn does not require them)
  thing.setAPN(APN_NAME, APN_USER, APN_PSWD);

  // set PIN (optional)
  // thing.setPIN(CARD_PIN);

  // resource input example (i.e, controlling a digitalPin);
  pinMode(LED_BUILTIN, OUTPUT);

  thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}