# Microchip24AA02E_library

Library for 2K I2C Serial EEPROMs with EUI-48™ or EUI-64™ Node Identity for Arduino. Supported packaging: 24AA02E48, 24AA025E48, 24AA02E64, 24AA025E64.

## Usage

```
#include "Microchip24AA02E.h"

mac48 mac;

void setup() {
  Serial.begin(9600);  // start serial for output
  while(!Serial) {}    // Wait for serial port
  Serial.println("Retrieving MAC address");
}

void loop() {
  MacReader.readMac48(mac);
  for (int i = 0; i < sizeof(mac) / sizeof(mac[0]); i++) {
    Serial.print(mac[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}
```

## Development

### Update keywords:

```
./build-keywords.sh
```

## Resources

* Datasheet: http://www.farnell.com/datasheets/2243909.pdf
