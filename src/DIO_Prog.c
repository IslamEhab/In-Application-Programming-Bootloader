#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Int.h"
#include "DIO_registers.h"

void DIO_Init(void)
{
	//RESET State -> INPUT 
	//I/P MODE    -> PULL UP - DOWN 

	GPIOA -> CRL = 0x44448888;
	GPIOA -> CRH = 0x00000000;
	//GPIOA -> CRH  = 0x22222222;


	GPIOB -> CRL = 0x44444444;
	GPIOB -> CRH = 0x33334444;

	GPIOC -> CRL = 0x44444444;
	GPIOC -> CRH = 0x44444444;

	//initial value -> HIGH

	GPIOA -> ODR = 0x0000000F;
	GPIOB -> ODR = 0x00000000;
	GPIOC -> ODR = 0x00000000;

}


void DIO_SetPortValue(u8 port, u8 value)
{
	if ((port <= PORTC))
	{
		switch (port)
		{
		case PORTA:
			if (value == HIGH)
			{
				GPIOA -> CRL  = 0x22222222;
				GPIOA -> CRH  = 0x22222222;
				GPIOA -> BSRR = 0x0000FFFF;
			}
			else if (value == LOW)
			{
				GPIOA -> BRR  = 0x0000FFFF;
			}
			else
			{

			}
			break;
		case PORTB:
			if (value == HIGH)
			{
				GPIOB -> CRL  = 0x22222222;
				GPIOB -> CRH  = 0x22222222;
				GPIOB -> BSRR = 0x0000FFFF;
			}
			else if (value == LOW)
			{
				GPIOB -> BRR  = 0x0000FFFF;
			}
			else
			{

			}
			break;
		case PORTC:
			if (value == HIGH)
			{
				GPIOC -> CRL  = 0x22222222;
				GPIOC -> CRH  = 0x22222222;
				GPIOC -> BSRR = 0x0000E000;
			}
			else if (value == LOW)
			{
				GPIOA -> BRR  = 0x0000E000;
			}
			else
			{

			}
			break;

		default:
			//do nothing
			break;
		}
	}
	else
	{
		//do nothing  guard to port and pin
	}
}


//#define PIN1A   4

/*void Test (u8 port, u8 pin, u8 value)
{

	//SET_PORT(GPIOA -> CRL ,OUT_10 , PIN1A);
	GPIOA -> CRL = 0x22222222;

	SET_BIT(GPIOA -> BSRR, pin);


}*/




void DIO_SetPinValue(u8 port, u8 pin, u8 value)
{
	if ((port <= PORTC) && (pin <= PIN15))
	{
		switch (port)
		{
		case PORTA:
			if (value == HIGH)
			{
				//GPIOA -> CRL = 0x22222222;
				//GPIOA -> CRH = 0x22222222;
				SET_BIT(GPIOA -> BSRR, pin);
			}
			else if (value == LOW)
			{
				SET_BIT(GPIOA -> BRR, pin);
			}
			else
			{
				//do nothing
			}
			break;

		case PORTB:
			if (value == HIGH)
			{
				//GPIOB -> CRL = 0x22222222;
				//GPIOB -> CRH = 0x22222222;
				SET_BIT(GPIOB -> BSRR, pin);
			}
			else if (value == LOW)
			{
				SET_BIT(GPIOB -> BRR, pin);
			}
			else
			{
				//do nothing
			}
			break;

		case PORTC:
			if (value == HIGH)
			{
				//GPIOC -> CRL = 0x22222222;
				//GPIOC -> CRH = 0x22222222;
				SET_BIT(GPIOC -> BSRR, pin);
			}
			else if (value == LOW)
			{
				SET_BIT(GPIOC -> BRR, pin);
			}
			else
			{
				//do nothing
			}
			break;

		default:
			//do nothing
			break;
		}
	}
	else
	{
		//do nothing  guard to port and pin 
	}

}



void DIO_SetPinConfig(u8 port, u8 pin, u32 config)
{
	if ((port <= PORTC) && (pin <= PIN15))
	{
		switch (port)
		{
		case PORTA:
			if (pin < 8)
			{
				//CLR_PORT(GPIOA -> CRL);
				pin = pin * 4;
				GPIOA -> CRL = (config << (pin));



				//SET_BIT(GPIOA -> BSRR, pin);


			}
			else if (pin >= 8)
			{
				//CLR_PORT(GPIOA -> CRH);
				pin = pin-8;

				pin = pin * 4;
				GPIOA -> CRH |= (config << (pin));

			}
			else
			{
				//do nothing
			}
			break;

		case PORTB:
			if (pin < 8)
			{

//				CLR_PORT(GPIOB -> CRL);

				pin = pin * 4;
				GPIOB -> CRL = (config << (pin));


			}
			else if (pin >= 8)
			{
				pin = pin-8;

	//			CLR_PORT(GPIOB -> CRH);

				pin = pin * 4;
				GPIOB -> CRH = (config << (pin));
			}
			else
			{
				//do nothing
			}
			break;

		case PORTC:
			if (pin < 8)
			{

		//		CLR_PORT(GPIOC -> CRL);

				pin = pin * 4;
				GPIOC -> CRL = (config << (pin));


			}
			else if (pin >= 8)
			{
				pin = pin-8;
			//	CLR_PORT(GPIOC -> CRH);

				pin = pin * 4;
				GPIOC -> CRH = (config << (pin));
			}
			else
			{
				//do nothing
			}
			break;
		}
	}
	else
	{
		//do nothing  guard to port and pin
	}

}

u8 DIO_GetpinValue(u8 port, u8 pin)
{
	u8 value = 0;

	if ((port <= PORTC) && (pin <= PIN15))
	{
		switch (port)
		{
		case PORTA:
			value = GET_BIT(GPIOA -> IDR, pin);
			break;

		case PORTB:
			value = GET_BIT(GPIOB -> IDR, pin);
			break;

		case PORTC:
			value = GET_BIT(GPIOC -> IDR, pin);
			break;

		default:
			//do nothing
			break;
		}
	}
	else
	{
		value = 0xFF;
	}

	return value;

}



