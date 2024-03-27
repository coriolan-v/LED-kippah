// Seed XIAO nrf52840

#include <bluefruit.h>

// OTA DFU service
BLEDfu bledfu;

// Uart over BLE service
BLEUart bleuart;

// Function prototypes for packetparser.cpp
uint8_t readPacket(BLEUart *ble_uart, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t *data, const uint32_t numBytes);

// Packet buffer
extern uint8_t packetbuffer[];

int ledStatus = 1;

void setup(void) {
  Serial.begin(115200);
  //while ( !Serial ) delay(10);   // for nrf52840 with native usb

  Serial.println(F("LED Kippah with BLE control"));
  Serial.println(F("-------------------------------------------"));

  initBLE();

  setupLED();
}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
/**************************************************************************/
void loop(void) {

  animation(ledStatus);

  readBLE();
}





