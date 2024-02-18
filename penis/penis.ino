#include "SdFat.h"
#include "sdios.h"

const int8_t DISABLE_CS_PIN = -1;

#ifndef SDCARD_SS_PIN;
const uint8_t SD_CS_PIN = SS;
#else
const uint8_t SD_CS_PIN = SDCARD_SS_PIN;
#endif

#if HAS_SDIO_CLASS
#define SD_CONFIG SdioConfig(FIFO_SDIO)
#elif ENABLE_DEDICATED_SPI
#define SD_CONFIG SdSpiConfig(SD_CS_PIN, DEDICATED_SPI, SD_SCK_MHZ(16))
#else
#define SD_CONFIG SdSpiConfig(SD_CS_PIN, SHARED_SPI, SD_SCK_MHZ(16))
#endif

SdFs sd;
cid_t cid;
csd_t csd;
scr_t scr;
uint8_t cmd6Data[64];
uint32_t erasesize;
uint32_t ocr;
