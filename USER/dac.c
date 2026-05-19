// dac.c - 新建DAC驱动文件
#include "dac.h"
#include "stm32f10x.h"

void MYDAC_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    DAC_InitTypeDef DAC_InitStructure;

    // 开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

    // PA4配置为模拟输入（DAC_OUT1）
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // DAC配置
    DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;  // 不使用触发
    DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
    DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_1, &DAC_InitStructure);

    // 使能DAC通道1
    DAC_Cmd(DAC_Channel_1, ENABLE);
}

// 设置DAC输出电压：value范围0-4095对应0-3.3V
void DAC_SetValue(u16 value)
{
    if(value > 4095) value = 4095;
    DAC_SetChannel1Data(DAC_Align_12b_R, value);
}