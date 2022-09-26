/*
 * util.h
 *
 * Created: 9/9/2022 6:36:33 AM
 *  Author: Mohamed Ahmed Mohamed Ibrahim
 */ 


#ifndef UTIL_H_
#define UTIL_H_

//common typedef
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef signed long int32_t;
typedef unsigned long long uint64_t;

// common bit operations
#define setBit(X, BIT_COUNT) ((X) |= (1<<(BIT_COUNT)))
#define clearBit(X, BIT_COUNT) ((X) &= ~(1<<(BIT_COUNT)))
#define toggleBit(X, BIT_COUNT) ((X) ^= (1<<(BIT_COUNT)))
#define readBit(X, BIT_COUNT) (((X) & (1<<(BIT_COUNT))) >> (BIT_COUNT))



#endif /* UTIL_H_ */