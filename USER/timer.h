#ifndef __PWM_H
#define __PWM_H

#include "sys.h"   // u16/u8 类型等
#include "stm32f10x.h"

// ==========================
// PWM 输出初始化
// ==========================
void PWM_Init(void);

// ==========================
// TIM2 定时器初始化
// arr : 自动重装载值
// psc : 预分频值
// ==========================
void TIM2_Init(u16 arr, u16 psc);

// ==========================
// 设置 PWM 占空比
// val : 比例值 0~ARR
// ==========================
void PWM_SetCompare(u16 val);

#endif