#ifndef __DAC_H
#define __DAC_H

#include "stm32f10x.h"

void MYDAC_Init(void);
void DAC_SetValue(u16 value);

#endif