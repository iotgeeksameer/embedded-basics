#include "spi_driver.h"
 
bool spi_init()
{
	spi_low_level_init(MASTER,0,16,false);
	_enable = ture;
}

bool spi_low_level_init(bool mode,uint8_t clock_mode,uint8_t clock_prescalar,bool lsb_first)
{
	SPCR &= 0x00;
	// spi enable
	SPCR |= (1<< SPE);              

	// enable spi interrupt
	// SPCR |= (1<< SPIE); 

	// set master / slave mode
	DDRB = (1<<MOSI_BIT) | (1<< SCLK_BIT);
	SPCR |= (1<<MSTR)   
	if(mode == SLAVE)
	{
		SPCR &= ~(1<<MSTR)
		DDRB = (1<<MISO_BIT);

	}
	//set first transmit bit MSB/LSB
	SPCR &= ~(1<<DORD);
	if(lsb_first)
		SPCR |= (1<<DORD);


	// setting clock mode
	switch(clock_mode)
	{
		case 0:
		{
			SPCR &= ~(1<< CPOL) ; 
			SPCR &= ~(1<< CPHA) ;
			break;
		}
		case 1:
		{
			SPCR &= ~(1<< CPOL) ; 
			SPCR |= (1<< CPHA) ;
			break;
		}
		case 2:
		{
			SPCR |= (1<< CPOL) ; 
			SPCR &= ~(1<< CPHA);
			break;
		}
		case 3:
		{
			SPCR |= (1<< CPOL) ; 
			SPCR |= (1<< CPHA) ;
			break;
		}
	}

// setting clock frequency
	switch (clock_prescalar)
	{
		case 4:
		{	
		
		SPSR &= ~(1<< SPI2X);
		SPCR &= ~(1 << SPR1);
		SPCR &= ~(1 << SPR0);
			break;
		}
		case 8:
		{	
		
		SPSR | = (1<< SPI2X);
		SPCR &= ~(1 << SPR1);
		SPCR | = (1 << SPR0);
			break;
		}

		case 16:
		{	
		
		SPSR &= ~(1<< SPI2X);
		SPCR &= ~(1 << SPR1);
		SPCR | = (1 << SPR0);
			break;
		}
		case 32:
		{	
		
		SPSR | = (1<< SPI2X);
		SPCR | = (1 << SPR1);
		SPCR &= ~(1 << SPR0);
			break;
		}
		case 64:
		{	
		
		SPSR | = (1<< SPI2X);
		SPCR | = (1 << SPR1);
		SPCR | = (1 << SPR0);
			break;
		}
		case 128:
		{	
		
		SPSR &= ~(1<< SPI2X);
		SPCR | = (1 << SPR1);
		SPCR | = (1 << SPR0);
			break;
		}
		
	}

	return true;
}


uint8_t spi_send(uint8_t byte)
{
	if(_enable == true)
	{
		while(! ( SPSR & (1<<WCOL) ) )    // todo: interupt for packet completion
		{
		SPDR = byte;
		while(! ( SPSR & (1<<SPIF) ) );
		return SPDR;
		}
	}
	else
		return 0;
}

void set_ss_pin()
{
	PORTB |= SET_SS_PIN_BIT;
}

void Reset_ss_pin()
{
	PORTB &= ~SET_SS_PIN_BIT;
}

void spi_disable()
{
	_enable = false;
}

bool busy()
{
	if (! ( SPSR & (1<<SPIF) ))
		return true;
	return false;

}