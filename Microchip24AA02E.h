#ifndef Microchip24AA02E_H
#define Microchip24AA02E_H

#include <Arduino.h>
#include <Wire.h>

#define Microchip24AA02E_DEFAULT_DEVICE_ADDRESS 0x50

typedef byte mac48[6];
typedef byte mac64[8];

class Microchip24AA02E {
  public:
    Microchip24AA02E(const byte = Microchip24AA02E_DEFAULT_DEVICE_ADDRESS);
    const void readMac48(mac48) const;
    const void readMac48(mac48, const byte) const;

    const void readMac64(mac64) const;
    const void readMac64(mac64, const byte) const;

    const byte readDeviceAddress() const;
  private:
    const byte readRegister(const byte, const byte) const;
    byte device_address;
};

extern Microchip24AA02E MacReader;
#endif
