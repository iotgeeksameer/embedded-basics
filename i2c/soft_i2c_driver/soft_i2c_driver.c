#include "soft_i2c.h"

void SoftI2CInit()
{
	PxOUT   &= ~(SCL | SDA);
}


void StartI2C()
{
	SDA_HIGH;
	delay_cycles(1000);
	SCL_HIGH;
	delay_cycles(1000);
	SDA_LOW;
	delay_cycles(1000);
	SCL_LOW;
}


void StopI2C()
{
	SDA_LOW;
	delay_cycles(1000);

	SCL_HIGH;
	delay_cycles(1000);

	SDA_HIGH;
	delay_cycles(1000);
}

void SendResponse(bool response)
{
	WriteBitI2C(response);
}

void WriteBitI2C(bool bit)
{
	if (bit) SDA_HIGH;
	else SDA_LOW;

	delay_cycles(1000);

	SCL_HIGH;

	delay_cycles(1000);

	SCL_LOW;
}

bool WriteByteI2C(uint8_t byte)
{
	for (uint8_t index = 0; index < 8; ++index)
	{
		WriteBitI2C((byte & 0x80) != 0);
		byte <<= 1;
	}

	return ReadBitI2C();
}

bool  ReadBitI2C()
{
	bool bit;

	SDA_HIGH;

	delay_cycles(1000);

	SCL_HIGH;

	delay_cycles(1000);

	if (SDA == (PxIN & SDA)) bit = true;
	else bit = false;

	SCL_LOW;

	return bit;
}

uint8_t ReadByteI2C()
{
	uint8_t byte;

	for (uint8_t bits = 0; bits < 8; ++bits)
	{
		byte = (byte << 1) | ReadBitI2C();
	}

	return byte;
}

void delay_cycles(uint32_t cycle)
{
uuint32_t i =0;
while(i ! = )
{
_NOP();
i++;
}
