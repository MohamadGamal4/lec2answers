//#include <util/delay.h>
typedef unsigned char u8;

#define DDRA *((u8*)0x3A)
#define PORTA *(u8*)0x3B
#define PINA *(volatile u8*)0x39

#define DDRB *((u8*)0x37)
#define PORTB *(u8*)0x38
#define PINB *(volatile u8*)0x36

int main(void)
{
	//led1 and 2 are output
	DDRA|=(1<<0);
	DDRA|=(1<<1);

	//led1&2 initially off
	PORTA&=~(1<<0);
	PORTA&=~(1<<1);




	//sw s are input
	DDRB&=~(1<<0);
	DDRB&=~(1<<1);
	DDRB&=~(1<<2);

	//active pulled up
	PORTB|=(1<<0);
	PORTB|=(1<<1);
	PORTB|=(1<<2);

	while(1)
	{

		if(((PINB>>0)&1)==0)
		{
			PORTA|=(1<<0);
		}
		else if(((PINB>>1)&1)==0)
		{
			PORTA|=(1<<1);
		}
		else if(((PINB>>2)&1)==0)
		{
			PORTA|=(1<<0);
			PORTA|=(1<<1);
		}
		else
		{
			PORTA&=~(1<<0);
			PORTA&=~(1<<1);
		}
	}

	return 0;
}
