#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include<avr/io.h>

#define F_CPU 1000000UL

// pins for spi lines 
#define MOSI_BIT	5
#define MISO_BIT	6
#define SCLK_BIT	7
#define SET_SS_PIN_BIT  // put the gpio number that is conneted to ss 	

//mode
#define MASTER	1
#define SLAVE	0

//spcr
#define SPR0 	0
#define SPR1	1
#define CPHA	2
#define CPOL	3
#define MSTR	4
#define DORD	5
#define SPE 	6
#define SPIE 	7
//spsr
#define SPI2X	0
#define WCOL	6
#define SPIF	7


bool _enable;

bool busy();
bool spi_init();
void set_ss_pin();
void Reset_ss_pin();
void spi_disable();
int8_t spi_send(uint8_t byte);
bool spi_low_level_init(uint8_t mode,uint8_t clock_mode,uint8_t clock_prescalar,bool lsb_first);




#endif