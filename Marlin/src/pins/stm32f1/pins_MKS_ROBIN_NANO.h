/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F103VET6) board pin assignments
 * https://github.com/makerbase-mks/MKS-Robin-Nano-V1.X/tree/master/hardware
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME "MKS Robin Nano"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_JTAG

//
// Thermocouples
//
//#define TEMP_0_CS_PIN                     PE5   // TC1 - CS1
//#define TEMP_0_CS_PIN                     PE6   // TC2 - CS2

//#define LED_PIN                           PB2

<<<<<<< HEAD
#include "pins_MKS_ROBIN_NANO_common.h"

#if HAS_TFT_LVGL_UI && FAN1_PIN != PB0 && HEATER_1_PIN != PB0
  #define BOARD_INIT() OUT_WRITE(PB0, LOW)
=======
//
// SD Card
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#define SDIO_SUPPORT
#define SDIO_CLOCK                       4500000  // 4.5 MHz
#define SD_DETECT_PIN                       PD12
#define ONBOARD_SD_CS_PIN                   PC11

//
// LCD / Controller
//
#define BEEPER_PIN                          PC5

/**
 * Note: MKS Robin TFT screens use various TFT controllers.
 * If the screen stays white, disable 'LCD_RESET_PIN'
 * to let the bootloader init the screen.
 */

// Shared FSMC Configs
#if HAS_FSMC_TFT
  #define DOGLCD_MOSI                       -1    // prevent redefine Conditionals_post.h
  #define DOGLCD_SCK                        -1

  #define FSMC_CS_PIN                       PD7   // NE4
  #define FSMC_RS_PIN                       PD11  // A0

  #define TOUCH_CS_PIN                      PA7   // SPI2_NSS
  #define TOUCH_SCK_PIN                     PB13  // SPI2_SCK
  #define TOUCH_MISO_PIN                    PB14  // SPI2_MISO
  #define TOUCH_MOSI_PIN                    PB15  // SPI2_MOSI

  #define TFT_RESET_PIN                     PC6   // FSMC_RST
  #define TFT_BACKLIGHT_PIN                 PD13

  #define LCD_USE_DMA_FSMC                        // Use DMA transfers to send data to the TFT
  #define FSMC_CS_PIN                       PD7
  #define FSMC_RS_PIN                       PD11
  #define FSMC_DMA_DEV                      DMA2
  #define FSMC_DMA_CHANNEL               DMA_CH5

  #define TOUCH_BUTTONS_HW_SPI
  #define TOUCH_BUTTONS_HW_SPI_DEVICE          2

  #define TFT_BUFFER_SIZE                  14400
#endif

// XPT2046 Touch Screen calibration
#if EITHER(TFT_LVGL_UI_FSMC, TFT_480x320)
  #ifndef XPT2046_X_CALIBRATION
    #define XPT2046_X_CALIBRATION          17880
  #endif
  #ifndef XPT2046_Y_CALIBRATION
    #define XPT2046_Y_CALIBRATION         -12234
  #endif
  #ifndef XPT2046_X_OFFSET
    #define XPT2046_X_OFFSET                 -45
  #endif
  #ifndef XPT2046_Y_OFFSET
   #define XPT2046_Y_OFFSET                  349
  #endif
#elif ENABLED(TFT_CLASSIC_UI)
  #ifndef XPT2046_X_CALIBRATION
    #define XPT2046_X_CALIBRATION          12149
  #endif
  #ifndef XPT2046_Y_CALIBRATION
    #define XPT2046_Y_CALIBRATION          -8746
  #endif
  #ifndef XPT2046_X_OFFSET
    #define XPT2046_X_OFFSET                 -35
  #endif
  #ifndef XPT2046_Y_OFFSET
    #define XPT2046_Y_OFFSET                 256
  #endif
#elif ENABLED(TFT_320x240)
  #ifndef XPT2046_X_CALIBRATION
    #define XPT2046_X_CALIBRATION         -12246
  #endif
  #ifndef XPT2046_Y_CALIBRATION
    #define XPT2046_Y_CALIBRATION           9453
  #endif
  #ifndef XPT2046_X_OFFSET
    #define XPT2046_X_OFFSET                 360
  #endif
  #ifndef XPT2046_Y_OFFSET
    #define XPT2046_Y_OFFSET                 -22
  #endif
#endif

#define HAS_SPI_FLASH                          1
#if HAS_SPI_FLASH
  #define SPI_FLASH_SIZE               0x1000000  // 16MB
  #define W25QXX_CS_PIN                     PB12
  #define W25QXX_MOSI_PIN                   PB15
  #define W25QXX_MISO_PIN                   PB14
  #define W25QXX_SCK_PIN                    PB13
>>>>>>> faae900747 (TFT Refactoring (#19192))
#endif
