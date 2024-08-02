
#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"


int main(void) {

	// Configuration, internal registers
	SIM->SCGC5     = 0x00000400; // Clock Gating Control, Clock enabled on PORT B
	PORTB->PCR[22] = 0x00000100; // Pin Control Register, MUX to GPIO (001)
	GPIOB->PDOR    = 0x00400000;
	GPIOB->PDDR    = 0x00400000;

	while(1) {

		GPIOB->PDOR = 0;

		printf("RED LED ON\n");


		GPIOB->PDOR = 0x00400000;

		GPIOB->PDOR = 0x00000000;

		GPIOB->PDOR = 0x00200000;

		printf("RED LED OFF\n");

	}
	return 0;
}
