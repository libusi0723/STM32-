#ifndef __WAVE_H
#define __WAVE_H

#include "sys.h"
//#define TABLE_SIZE 256
extern u8 wave_type;
extern u16 freq;
extern u8 amplitude;
//extern u16
	
//sine_table[TABLE_SIZE];
	
//void Sine_Table_Init(void);
void Wave_Update(void);
void TIM2_Freq_Update(void); 

#endif