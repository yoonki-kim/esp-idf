// Copyright 2010-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enable early entropy source for RNG
 *
 * Uses the SAR ADC to feed entropy into the HWRNG. The ADC is put
 * into a test mode that reads an internal reference voltage and
 * constantly feeds the LSB of data into the HWRNG. Consult the
 * SoC Technical Reference Manual for more information.
 *
 * Can also be used from app code early during operation, if true
 * random numbers are required before WiFi stack is initialised.
 * Call this function from app code only if WiFi/BT are not yet
 * enabled and I2S and ADC are not in use.
 *
 * Call bootloader_random_disable() when done.
 */
void bootloader_random_enable(void);

/**
 * @brief Disable early entropy source for RNG
 *
 * Disables SAR ADC source and resets the I2S hardware.
 *
 */
void bootloader_random_disable(void);

/**
 * @brief Fill buffer with 'length' random bytes
 *
 * @param buffer Pointer to buffer
 * @param length This many bytes of random data will be copied to buffer
 */
void bootloader_fill_random(void *buffer, size_t length);

#ifdef __cplusplus
}
#endif
