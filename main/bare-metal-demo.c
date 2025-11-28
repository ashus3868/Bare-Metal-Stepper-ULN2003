// Controlling Mini Stepper motor with ULN2003
#include <stdio.h>
#include <stdint.h>

#define GPIO_IO1           27
#define GPIO_IO2           26
#define GPIO_IO3           25
#define GPIO_IO4           2        //33-31

#define GPIO_OUT_W1TS_REG  0x3FF44008 
#define GPIO_OUT_W1TC_REG  0x3FF4400C 
#define GPIO_ENABLE_REG    0x3FF44020 

#define GPIO_OUT1_W1TS_REG  0x3FF44014  
#define GPIO_OUT1_W1TC_REG  0x3FF44018  
#define GPIO_ENABLE1_REG    0x3FF4402C  

void delay(volatile uint32_t cycles){
    while (cycles--)
    {
        for (int i = 0; i < 10000; i++)
        {
            __asm__ volatile("nop");    // no operation
        }   
    }
}

void delay_us(volatile uint32_t cycles){
    while (cycles--)
    {
        __asm__ volatile("nop");    // no operation
          
    }
}

void app_main(void){
    volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*)GPIO_OUT_W1TS_REG;
    volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*)GPIO_OUT_W1TC_REG;
    volatile uint32_t* gpio_enable_reg = (volatile uint32_t*)GPIO_ENABLE_REG;

    volatile uint32_t* gpio_out1_w1ts_reg = (volatile uint32_t*)GPIO_OUT1_W1TS_REG;
    volatile uint32_t* gpio_out1_w1tc_reg = (volatile uint32_t*)GPIO_OUT1_W1TC_REG;
    volatile uint32_t* gpio_enable1_reg = (volatile uint32_t*)GPIO_ENABLE1_REG;

    *gpio_enable_reg  |= (1<<GPIO_IO1);
    *gpio_enable_reg  |= (1<<GPIO_IO2);
    *gpio_enable_reg  |= (1<<GPIO_IO3);
    *gpio_enable1_reg  |= (1<<GPIO_IO4);

    while(1){
        // // Clockwise direction
        // *gpio_out_w1ts_reg = (1<<GPIO_IO1);
        // *gpio_out_w1tc_reg = (1<<GPIO_IO2);
        // *gpio_out_w1tc_reg = (1<<GPIO_IO3);
        // *gpio_out1_w1tc_reg = (1<<GPIO_IO4);
        // delay_us(40000);
        // *gpio_out_w1tc_reg = (1<<GPIO_IO1);
        // *gpio_out_w1ts_reg = (1<<GPIO_IO2); 
        // *gpio_out_w1tc_reg = (1<<GPIO_IO3);  
        // *gpio_out1_w1tc_reg = (1<<GPIO_IO4); 
        // delay_us(40000);
        // *gpio_out_w1tc_reg = (1<<GPIO_IO1);  
        // *gpio_out_w1tc_reg = (1<<GPIO_IO2); 
        // *gpio_out_w1ts_reg = (1<<GPIO_IO3); 
        // *gpio_out1_w1tc_reg = (1<<GPIO_IO4); 
        // delay_us(40000);
        // *gpio_out_w1tc_reg = (1<<GPIO_IO1);  
        // *gpio_out_w1tc_reg = (1<<GPIO_IO2);  
        // *gpio_out_w1tc_reg = (1<<GPIO_IO3);  
        // *gpio_out1_w1ts_reg = (1<<GPIO_IO4); 
        // delay_us(40000);


        // anti-Clockwise direction
        *gpio_out_w1tc_reg = (1<<GPIO_IO1);  //  0
        *gpio_out_w1tc_reg = (1<<GPIO_IO2);  //  0
        *gpio_out_w1tc_reg = (1<<GPIO_IO3);  //  0
        *gpio_out1_w1ts_reg = (1<<GPIO_IO4); //  1
        delay_us(40000);
        *gpio_out_w1tc_reg = (1<<GPIO_IO1);  //  0
        *gpio_out_w1tc_reg = (1<<GPIO_IO2);  //  0
        *gpio_out_w1ts_reg = (1<<GPIO_IO3);  //  1
        *gpio_out1_w1tc_reg = (1<<GPIO_IO4);  // 0
        delay_us(40000);
        *gpio_out_w1tc_reg = (1<<GPIO_IO1);  //  0
        *gpio_out_w1ts_reg = (1<<GPIO_IO2);  //  1
        *gpio_out_w1tc_reg = (1<<GPIO_IO3);  //  0
        *gpio_out1_w1tc_reg = (1<<GPIO_IO4);  // 0
        delay_us(40000);
        *gpio_out_w1ts_reg = (1<<GPIO_IO1);  //  1
        *gpio_out_w1tc_reg = (1<<GPIO_IO2);  //  0
        *gpio_out_w1tc_reg = (1<<GPIO_IO3);  //  0
        *gpio_out1_w1tc_reg = (1<<GPIO_IO4);  // 0
        delay_us(40000);
    }
}
