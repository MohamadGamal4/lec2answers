#include <util/delay.h>
typedef unsigned char u8;

#define DDRA *((u8*)0x3A)
#define PORTA *(u8*)0x3B
#define PINA *(volatile u8*)0x39

#define DDRB *((u8*)0x37)
#define PORTB *(u8*)0x38
#define PINB *(volatile u8*)0x36

int main(void)
{
	u8 segmant [10]={ 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

	//bttns are inputs
	DDRA&=~(1<<0);
	DDRA&=~(1<<1);

	//active pull up
	PORTA|=3;

	//seg is output
	DDRB|=255;
	//seg initially zero
	PORTB=0x3f;

	u8 counter=0;
	while(1)
	{
		if( (((PINA>>0)&1)==0) && (counter<9) )
		{
			while(((PINA>>0)&1)==0);
			PORTB=segmant[++counter];
			//_delay_ms(300);

		}
		else if( (((PINA>>1)&1)==0) && (counter>0))
		{
			while(((PINA>>1)&1)==0);
			PORTB=segmant[--counter];
			//_delay_ms(300);
		}
	}
	return 0;
}
