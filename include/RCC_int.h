#ifndef _RCC_INT_H
#define _RCC_INT_H 



////////////AHB  FROM 0 TO 31///////////////
#define RCC_CLK_DMA1   0x01
#define RCC_CLK_DMA2   0x02
#define RCC_CLK_SRAM   0x03
#define RCC_CLK_FLITF  4
#define RCC_CLK_CRC    6
#define RCC_CLK_FSMC   8
#define RCC_CLK_SDIO   10


///////////APB2 FROM 32 TO 63/////////////
#define RCC_CLK_AFIO   32
#define RCC_CLK_IOPA   34
#define RCC_CLK_IOPB   35
#define RCC_CLK_IOPC   36
#define RCC_CLK_ADC1   41
#define RCC_CLK_ADC2   42
#define RCC_CLK_TIM1   43
#define RCC_CLK_SPI1   44
#define RCC_CLK_TIM8   45
#define RCC_CLK_USART1 46
#define RCC_CLK_ADC3   47
#define RCC_CLK_TIM9   51
#define RCC_CLK_TIM10  52
#define RCC_CLK_TIM11  53


///////////APB1 FROM 64 TO 95//////////////
#define RCC_CLK_TIM2   64
#define RCC_CLK_TIM3   65
#define RCC_CLK_TIM4   66
#define RCC_CLK_TIM5   67
#define RCC_CLK_TIM6   68
#define RCC_CLK_TIM7   69
#define RCC_CLK_TIM12  70
#define RCC_CLK_TIM13  71
#define RCC_CLK_TIM14  72
#define RCC_CLK_WWDG   75
#define RCC_CLK_SPI2   78
#define RCC_CLK_SPI3   79
#define RCC_CLK_USART2 81
#define RCC_CLK_USART3 82
#define RCC_CLK_USART4 83
#define RCC_CLK_USART5 84
#define RCC_CLK_I2C1   85
#define RCC_CLK_I2C2   86
#define RCC_CLK_USB    87
#define RCC_CLK_CAN    89
#define RCC_CLK_BKP    91
#define RCC_CLK_PWR    92
#define RCC_CLK_DAC    93


#define  RCC_CR_HSION                        0x00000001        /*!< Internal High Speed clock enable */
#define  RCC_CR_HSIRDY                       0x00000002        /*!< Internal High Speed clock ready flag */
#define  RCC_CR_HSITRIM                      0x000000F8        /*!< Internal High Speed clock trimming */
#define  RCC_CR_HSICAL                       0x0000FF00        /*!< Internal High Speed clock Calibration */
#define  RCC_CR_HSEON                        0x00010000        /*!< External High Speed clock enable */
#define  RCC_CR_HSERDY                       0x00020000        /*!< External High Speed clock ready flag */
#define  RCC_CR_HSEBYP                       0x00040000        /*!< External High Speed clock Bypass */
#define  RCC_CR_CSSON                        0x00080000        /*!< Clock Security System enable */
#define  RCC_CR_PLLON                        0x01000000        /*!< PLL enable */
#define  RCC_CR_PLLRDY                       0x02000000        /*!< PLL clock ready flag */

#define  RCC_CFGR_SWS                        0x0000000C        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define  RCC_CFGR_SWS_0                      0x00000004        /*!< Bit 0 */
#define  RCC_CFGR_SWS_1                      0x00000008        /*!< Bit 1 */

#define  RCC_CFGR_SWS_HSI                    0x00000000        /*!< HSI oscillator used as system clock */
#define  RCC_CFGR_SWS_HSE                    0x00000004        /*!< HSE oscillator used as system clock */
#define  RCC_CFGR_SWS_PLL                    0x00000008        /*!< PLL used as system clock */


void RCC_voidInit(void);

void RCC_voidEnableClock(u8 PeripheralIdx);

void RCC_voidDisableClock(u8 PeripheralIdx);




#endif
