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

#if NOT_TARGET(__STM32F1__)
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif


//
// Limit Switches
//
#define X_MIN_PIN                          PE6  //DIAG->R15
#define Y_MIN_PIN                          PE4  //DIAG->R18
#define Z_MIN_PIN                          PE2  //DIAG->R21


#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_PIN                     PE1
#else
  #define Z_MAX_PIN                          PE1
#endif

//
// Steppers
//
#define X_DIR_PIN                           PE7
#define X_STEP_PIN                          PE8
#define X_ENABLE_PIN                        PE9

#define Y_DIR_PIN                           PE10
#define Y_STEP_PIN                          PE11
#define Y_ENABLE_PIN                        PE12

#define Z_DIR_PIN                           PE13
#define Z_STEP_PIN                          PE14
#define Z_ENABLE_PIN                        PE15

#define E0_DIR_PIN                          PA5
#define E0_STEP_PIN                         PA6
#define E0_ENABLE_PIN                       PA7

#define X_HARDWARE_SERIAL               Serial1 //uasrt2
#define Y_HARDWARE_SERIAL               Serial1
#define Z_HARDWARE_SERIAL               Serial1
#define E0_HARDWARE_SERIAL              Serial1


//
// Heaters / Fans
//
#define HEATER_0_PIN                        PC5
#define HEATER_BED_PIN                      PC6

#define FAN_PIN                             PB6     // G_FAN Cooling Nozzle Fan
#define FAN1_PIN                            PB8     // E_FAN Extruder - Heatsink
#define FAN2_PIN                            PA12    // M_FAN Motherboard Fan
#define FAN3_PIN                            PC7     // P_FAN Hepa Fan


//
// Temperature Sensors
//
#define TEMP_BED_PIN                        PC0
#define TEMP_0_PIN                          PC1

#undef STM32_FLASH_SIZE
#define STM32_FLASH_SIZE 512
#define FLASH_EEPROM_EMULATION
#define EEPROM_PAGE_SIZE uint16(0x800) // 2KB
#define EEPROM_START_ADDRESS uint32(0x08000000 + STM32_FLASH_SIZE * 1024 - 2 * EEPROM_PAGE_SIZE)
#undef E2END
#define E2END (EEPROM_PAGE_SIZE - 1) // 2KB