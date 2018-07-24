#ifndef SOFT_I2C_H_
#define SOFT_I2C_H_


#define SCL                     0x00
#define SDA                     0x01
#define PxDIR                   DDRB
#define PxOUT                   PORTB
#define PxIN                    PINB
#define SDA_HIGH                PxOUT |= SDA  
#define SDA_LOW                 PxOUT &= ~SDA
#define SCL_LOW                 PxOUT |= SCL
#define SCL_HIGH                PxOUT &= ~SCL

#define MSB_HIGH_BIT            0x80
#define MAX_BITS                8
#define LSB_HIGH_BIT			0x01

#define ACK 					0
#define NACK					1

#define READ_COUNT				7

#define _NOP() do { __asm__ __volatile__ ("nop"); } while (0)


	void    SoftI2CInit();
	void 	StartI2C();
	void 	StopI2C();
	void 	SendResponse(bool response);
	void 	WriteBitI2C(bool bit);
	bool 	WriteByteI2C(uint8_t byte);
	bool 	ReadBitI2C();
	uint8_t ReadByteI2C();
	void    delay_cycles(uint32_t cycles);

#endif  /** SOFT_I2C_H_ */
