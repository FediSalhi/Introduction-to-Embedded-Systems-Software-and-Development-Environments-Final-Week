/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief contains main function and other functions definitions
 *
 * This file contains main function and other functions definitions including
 * print_statics(), print_array(), find_minimum(), find_maximum()
 * find_mean(), find_median(), and sort_array()
 *
 * @author Fedi Salhi
 * @date 17/11/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  print_statics(test, SIZE);

}

void print_statics(unsigned char* data_array_u8, unsigned int length_u32) {

	/* local variables declariation */
	unsigned char minimum_u8;
	unsigned char maximum_u8;
	unsigned char mean_u8;
	unsigned char median_u8;

	/* find minimum */
	minimum_u8 = find_minimum(data_array_u8, length_u32);

	/* find maximum */
	maximum_u8 = find_maximum(data_array_u8, length_u32);

	/* find mean */
	mean_u8 = find_mean(data_array_u8, length_u32);

	/* sort_array */
	sort_array(data_array_u8, length_u32);
	
	/* find median */
	median_u8 = find_median(data_array_u8, length_u32);

	/* print minimum, maximum, mean, and median*/
	printf("minimum =  %u\n", minimum_u8);
	printf("maximum =  %u\n", maximum_u8);
	printf("mean =  %u\n", mean_u8);
	printf("median =  %u\n", median_u8);

	/* print sorted array */
	print_array(data_array_u8, length_u32);

}

void print_array(unsigned char* data_array_u8, unsigned int length_u32) {

	unsigned int i;

	for(i=0; i<length_u32; i++) {
		printf("Element %u = %u\n", i, data_array_u8[i]);
	}
}

void sort_array(unsigned char* data_array_u8, unsigned int length_u32) {
	
	unsigned char temp_u8;
	unsigned int i = 0;

	while (i<length_u32-1) {
		if (data_array_u8[i] < data_array_u8[i+1]) {
			temp_u8 = data_array_u8[i+1];
			data_array_u8[i+1] = data_array_u8[i];
			data_array_u8[i] = temp_u8;
			i = 0;
		}

		else {
			i++;
		}
	}
}

unsigned char find_median(unsigned char* data_array_u8, unsigned int length_u32) {
	
	unsigned char median_u8; 

	if (length_u32 % 2 == 0) {
		/* number of elements is even */
		median_u8 = (data_array_u8[length_u32/2] + data_array_u8[length_u32/2 -1])/2; 
	}

	else if (length_u32 % 2 != 0) {
		/* number of elements is odd */
		median_u8 = data_array_u8[(int)(length_u32/2)];
	}

	return median_u8;
}

unsigned char find_maximum(unsigned char* data_array_u8, unsigned int length_u32) {
	
	unsigned char maximum_u8;
	maximum_u8 = data_array_u8[0]; /* maximum_u8 = first element of data_array_u8 */
	unsigned int i;

	for(i=0; i<length_u32; i++) {
		if (data_array_u8[i] > maximum_u8) {
			maximum_u8 = data_array_u8[i];
		}
	}

	return maximum_u8;
}

unsigned char find_minimum(unsigned char* data_array_u8, unsigned int length_u32) {
	
	unsigned char minimum_u8;
	minimum_u8 = data_array_u8[0];
	unsigned int i;

	for(i=0; i<length_u32; i++) {
		if (data_array_u8[i] < minimum_u8) {
			minimum_u8 = data_array_u8[i];
		}
	}

	return minimum_u8;
}


unsigned char find_mean(unsigned char* data_array_u8, unsigned int length_u32) {
	
	unsigned char mean_u8;
	unsigned long sum_u64 = 0;
	unsigned int i;

	for(i=0; i<length_u32; i++) {
		sum_u64 += data_array_u8[i];
	}

	mean_u8 = sum_u64/length_u32; 

	return mean_u8;

}

