#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"
#include "led.h"

#include "wave.h"
#include "lcd_ui.h"
#include "dac.h"

// ?函数声明（必须在这里）
void Key_Process(void);
void TIM2_Init(u16 arr, u16 psc);

int main(void)
{
    delay_init();
    uart_init(9600);
  
    KEY_Init();
   
  //  PWM_Init();
   TIM2_Init(99,71);
   MYDAC_Init();
 // Sine_Table_Init();

	    LCD_Init();
	

    while(1)
    {
        Key_Process();
        LCD_Update();
			 
      
    }
}

// ?函数定义（必须在 main 外面）
void Key_Process(void)
{
    u8 key = KEY_Scan(0);

    switch(key)
    {
        case KEY0_PRES:
				   
            wave_type++;
            if(wave_type > 2) wave_type = 0;
				     
            break;

        case KEY1_PRES:
				
					  
            freq += 100;
            if(freq > 2000) freq = 1;
			      TIM2_Freq_Update();  // ！！！重要：修改频率后更新定时器节拍
            break;

        case WKUP_PRES:
            amplitude += 10;
            if(amplitude > 100) amplitude = 10; 
		//	Sine_Table_Init();   // ！！！重要：修改幅值后必须重新计算正弦表 
            break;
    }
}