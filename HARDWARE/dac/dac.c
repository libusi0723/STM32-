// dac.c - 修改为使用 PA5 (DAC_OUT2)
#include "dac.h"
#include "stm32f10x.h"

void MYDAC_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    DAC_InitTypeDef DAC_InitStructure;

    // 开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

    // 【修改点 1】PA5 配置为模拟输入（DAC_OUT2）
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; // 模拟输入是必须的，防止数字电路干扰
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // DAC配置
    DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;  
    DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
    DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
    
    // 【修改点 2】初始化 DAC 通道 2
    DAC_Init(DAC_Channel_2, &DAC_InitStructure);

    // 【修改点 3】使能 DAC 通道 2
    DAC_Cmd(DAC_Channel_2, ENABLE);
}

// 设置DAC输出电压：value范围0-4095对应0-3.3V
void DAC_SetValue(u16 value)
{
    if(value > 4095) value = 4095;
    
    // 【修改点 4】向 通道 2 的右对齐12位寄存器写入数据
    DAC_SetChannel2Data(DAC_Align_12b_R, value);
}