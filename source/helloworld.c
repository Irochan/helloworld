#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define	NONE	'0'
#define	GREEN	'1'
#define RED	'2'
#define ORENGE	'3'

int uifp;

int setLED (unsigned char color) {

	unsigned char buf[2];
	int result;

	buf[0] = color;
	buf[1] = 0;

	result = write(uifp, buf, 2);

	return result;

}

int main(void) {
	
	uifp = open("/dev/lms_ui", O_RDWR);

	if (uifp < 0) {
		printf(" Opne False /dev/lms_ui\n");
		exit(-1);
	}
	
	printf("Hello World!!\n");

	setLED(NONE);
	sleep(1);
	setLED(GREEN);
	sleep(1);
	setLED(RED);
	sleep(1);
	setLED(ORENGE);
	sleep(1);

	close(uifp);
	exit(0);
	
} 


