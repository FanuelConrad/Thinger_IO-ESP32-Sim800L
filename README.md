<p align="center">
  <a href="" rel="noopener">
 <img  src="Images/1654417801058.jpg" alt="Project logo"></a>
</p>

<h3 align="center">Thinger.IO ESP32 Sim800L</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/kylelobo/The-Documentation-Compendium.svg)](https://github.com/FanuelConrad/Thinger_IO-ESP32-Sim800L/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/pulls)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center">

 Connect to [Thinger.io](https://thinger.io/) via ESP32 and GSM Sim800L
    <br>
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](../TODO.md)
- [Contributing](#contributing)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

The project shows an easy way to use GSM Sim800L to connect your ESP32 to the [Thinger.io](https://thinger.io/) IoT platform. This project is specifically designed for the Arduino IDE/Platformio, so you can easily configure your environment and start connecting your ESP32 within minutes.

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See [deployment](#deployment) for notes on how to deploy the project on a live system.

### Prerequisites

[TinyGSM](https://github.com/vshymanskyy/TinyGSM) library

```
#include <TinyGsmClient.h>
```

[ThingerTinyGSM](https://github.com/thinger-io/Arduino-Library) library

```
#include <ThingerTinyGSM.h>
```

### Installing

Upload the code below to the ESP32

```
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
```

Connect the pins as shown below
ESP32 | Sim800L
---------|---
 Rx 2 | Tx
 Tx 2 | Rx

End with an example of getting some data out of the system or using it for a little demo.

## 🔧 Running the tests <a name = "tests"></a>

Explain how to run the automated tests for this system.

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## 🎈 Usage <a name="usage"></a>

Add notes about how to use the system.

## 🚀 Deployment <a name = "deployment"></a>

Add additional notes about how to deploy this on a live system.

## ⛏️ Built Using <a name = "built_using"></a>

- [Thinger.io](https://thinger.io/) - IoT Platform
- [PlatformIO](https://platformio.org/) - Integreted Development Environment (IDE)
- [Arduino](https://www.arduino.cc/) - Framework

## ✍️ Authors <a name = "authors"></a>

- [@FanuelConrad](https://github.com/FanuelConrad) - Idea & Initial work

## ✍️ Contributing <a name = "contributing"></a>

- [@Ega](https://community.thinger.io/u/ega/summary)

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- [Thinger.io community](https://community.thinger.io/)
