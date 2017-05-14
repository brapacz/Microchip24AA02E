#include "Microchip24AA02E.h"

Microchip24AA02E::Microchip24AA02E(const byte device_address) {
  this->device_address = device_address;
  Wire.begin();
}

const void Microchip24AA02E::readMac48(mac48 mac_address)  const {
  readMac48(mac_address, readDeviceAddress());
}

const void Microchip24AA02E::readMac64(mac64 mac_address)  const {
  readMac64(mac_address, readDeviceAddress());
}

const void Microchip24AA02E::readMac48(mac48 mac_address, const byte device_address) const {
  int offset = 0;
  for (int address = 0xFA; address <= 0xFF; address++) {
    mac_address[offset] = readRegister(address, device_address);
    offset++;
  }
}

const void Microchip24AA02E::readMac64(mac64 mac_address, const byte device_address) const {
  int offset = 0;
  for (int address = 0xF8; address <= 0xFF; address++) {
    mac_address[offset] = readRegister(address, device_address);
    offset++;
  }
}

const byte Microchip24AA02E::readDeviceAddress() const {
  return this->device_address;
}

const byte Microchip24AA02E::readRegister(const byte registry_address, const byte device_address) const {
  Wire.beginTransmission(device_address);
  Wire.write(registry_address);  // register to read
  Wire.endTransmission();

  Wire.requestFrom(device_address, (byte)1); // read a byte
  while (!Wire.available()) { }
  return Wire.read();
}


