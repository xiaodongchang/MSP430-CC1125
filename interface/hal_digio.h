//*****************************************************************************
//! @file       hal_digio.h
//! @brief      HAL digital IO functionality
//!
//! Revised     $Date: 2012-11-22 13:38:18 +0100 (to, 22 nov 2012) $
//! Revision    $Revision: 8830 $
//
//  Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//****************************************************************************/
#ifndef HAL_DIGIO_H
#define HAL_DIGIO_H


/******************************************************************************
* If building with a C++ compiler, make all of the definitions in this header
* have a C binding.
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
* INCLUDES
*/
#include <hal_types.h>


/******************************************************************************
* CONSTANTS AND DEFINES
*/
enum {
    HAL_DIGIO_INPUT,
    HAL_DIGIO_OUTPUT
};

enum {
    HAL_DIGIO_INT_FALLING_EDGE = 0,
    HAL_DIGIO_INT_RISING_EDGE
};

#define HAL_DIGIO_OK       0
#define HAL_DIGIO_ERROR  (~0)


/******************************************************************************
 * TYPEDEFS
 */
typedef struct {
    uint8 port;     // port number
    uint8 pin;      // pin number
    uint8 pin_bm;   // pin bitmask
    uint8 dir;      // direction (input or output)
    uint8 initval;  // initial value
} digioConfig;


/******************************************************************************
 * GLOBAL FUNCTIONS
 */
uint8 halDigioConfig(const digioConfig* p);
uint8 halDigioEnableResistor(const digioConfig* p);
uint8 halDigioDisableResistor(const digioConfig* p);
uint8 halDigioClear(const digioConfig* p);
uint8 halDigioToggle(const digioConfig* p);
uint8 halDigioSet(const digioConfig* p);
uint8 halDigioGet(const digioConfig* p);

uint8 halDigioIntConnect(const digioConfig *p, ISR_FUNC_PTR func);
uint8 halDigioIntEnable(const digioConfig *p);
uint8 halDigioIntDisable(const digioConfig *p);
uint8 halDigioIntClear(const digioConfig *p);
uint8 halDigioIntSetEdge(const digioConfig *p, uint8 edge);


/******************************************************************************
* Mark the end of the C bindings section for C++ compilers.
******************************************************************************/
#ifdef  __cplusplus
}
#endif
#endif // #ifndef HAL_DIGIO_H
