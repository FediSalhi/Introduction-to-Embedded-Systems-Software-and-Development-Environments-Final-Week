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
 * @file stats.h 
 * @brief header file of stats.c file
 *
 * This file contains the header of the functions used in stats.c file
 * Contains print_statics(), print_array(), find_minimum(), find_maximum()
 * find_mean(), find_median(), and sort_array() functions headers
 * @author Fedi Salhi
 * @date 15/11/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief prints statics of n-elements unsigned char array
 *
 * This function takes two inputs, an n-elements unsigned char array
 * and an unsigned 32-bit integer representing its length, and prints
 * minimum, maximum, mean, median, and sorted array 
 *
 * @param data_array_u8 array to print statics and to sort
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
void print_statics(unsigned char* data_array_u8, unsigned int length_u32);

/**
 * @brief print the elements of an unsigned char array
 *
 * This function takes an n-elements unsigned char array with its 
 * size and prints its elements
 *
 * @param data_array_u8 array to print elements
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
void print_array(unsigned char* data_array_u8, unsigned int length_u32);

/**
 * @brief finds the median of an unsigned char array
 *
 * This function takes an n-elements unsigned char array with its 
 * size and finds median
 *
 * @param data_array_u8 array to find the median
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
unsigned char find_median(unsigned char* data_array_u8, unsigned int length_u32);

/**
 * @brief finds the maximum of an unsigned char array
 *
 * This function takes an n-elements unsigned char array with its 
 * size and finds median
 *
 * @param data_array_u8 array to find the maximum
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
unsigned char find_maximum(unsigned char* data_array_u8, unsigned int length_u32);

/**
 * @brief finds the minimum of an unsigned char array
 *
 * This function takes an n-elements unsigned char array with its 
 * size and finds median
 *
 * @param data_array_u8 array to find the minimum
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
unsigned char find_minimum(unsigned char* data_array_u8, unsigned int length_u32);

/**
 * @brief finds the mean of an unsigned char array
 *
 * This function takes an n-elements unsigned char array with its 
 * size and finds median
 *
 * @param data_array_u8 array to find the mean
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
unsigned char find_mean(unsigned char* data_array_u8, unsigned int length_u32);

/**
 * @brief sorts an unsigned char array
 *
 * This function sorts an n-elements unsigned char array given
 * the array and its 32-bit unsigned integer length
 *
 * @param data_array_u8 array to sort
 * @param length_u32 32-bit integer containing the length of the input array
 *
 */
void sort_array(unsigned char* data_array_u8, unsigned int length_u32);


#endif /* __STATS_H__ */
