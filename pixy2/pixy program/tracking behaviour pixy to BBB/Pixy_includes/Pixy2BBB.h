
// BeagleBone Black SPI link class

#ifndef _PIXY2_H
#define _PIXY2_H

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <time.h>
#include <inttypes.h>

uint32_t millis();
void delayMicroseconds(uint32_t us);
int spi_open(const char *__file, int __oflag);

#include "TPixy2.h"

class Link2SPI
{
private:
	// Choose SPI device from Beaglebone Black
	const char *spi = "/dev/spidev2.0";
	uint8_t spiMode = 3, wordSize = 8;
	uint32_t spiSpeed = 15000000;
	int file = -1;
public:
	int8_t open(uint32_t arg)
	{
		if ((file = spi_open(spi, O_RDWR)) < 0) {
			printf("Error opening SPI device.");
			return -1;
		}
		if (ioctl(file, SPI_IOC_WR_MODE, &spiMode) == -1) {
			printf("Error setting SPI mode.");
			return -1;
		}
		if (ioctl(file, SPI_IOC_WR_BITS_PER_WORD, &wordSize) == -1) {
			printf("Error configuring word size.");
			return -1;
		}
		if (ioctl(file, SPI_IOC_WR_MAX_SPEED_HZ, &spiSpeed) == -1) {
			printf("Error adjusting SPI speed.");
			return -1;
		}
		return 0;
	}

	void close()
	{
		//SPI.endTransaction();
	}

	int16_t recv(uint8_t *buf, uint8_t len, uint16_t *cs=NULL)
	{
		uint8_t i;

		struct spi_ioc_transfer spiXfer;
		memset(&spiXfer, 0, sizeof(spi_ioc_transfer));
		spiXfer.tx_buf = (unsigned long) NULL;
		spiXfer.rx_buf = (unsigned long) buf;
		spiXfer.len = len;
		if (ioctl(file, SPI_IOC_MESSAGE(1), &spiXfer) < 0) {
			printf("SPI transmit error");
			return -1;
		}

		if (cs)
			*cs = 0;
		for (i=0; i<len; i++)
		{
			//buf[i] = SPI.transfer(0x00);
			if (cs)
				*cs += buf[i];
		}

		return len;
	}

	int16_t send(uint8_t *buf, uint8_t len)
	{
		//uint8_t i;
		//for (i=0; i<len; i++)
		//SPI.transfer(buf[i]);

		struct spi_ioc_transfer spiXfer;
		memset(&spiXfer, 0, sizeof(spi_ioc_transfer));
		spiXfer.tx_buf = (unsigned long) buf;
		spiXfer.rx_buf = (unsigned long) NULL;
		spiXfer.len = len;
		if (ioctl(file, SPI_IOC_MESSAGE(1), &spiXfer) < 0) {
			printf("SPI transmit error");
			return -1;
		}

		return len;
	}
};

// These two functions are borrowed from the Arduino API and need to be implemented in some form
// in order for the existing TPixy2 code to work as-is.  millis() may be difficult to implement,
// but its use isn't hugely important.  Look in TPixy2.h for its references, and remove if necessary.
// delayMicroseconds() can be easily implemented by a simple nested for-loop, and calibrated.
uint32_t millis() {
	struct timespec spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);

	return (spec.tv_nsec / 1000000);
}

void delayMicroseconds(uint32_t us) {
	usleep(us);
}

int spi_open(const char *file, int oflag) {
	return open(file, oflag);
}

typedef TPixy2<Link2SPI> Pixy2BBB;

#endif

//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
