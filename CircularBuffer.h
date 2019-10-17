#pragma once

#ifndef CIRCULAR_BUFFER_HEADER
#define CIRCULAR_BUFFER_HEADER

#include <stdio.h>

#define CIRCULAR_BUFFER_LENGHT 32

typedef struct CircularBuffer {

	int iWrite;
	int iRead;
	int *WritePointer;
	int *ReadPointer;
	int *ArrayPointer;
	int BufferArray[CIRCULAR_BUFFER_LENGHT];

} CircularBuffer;

_Bool circular_buffer_init(CircularBuffer BufferP, _Bool bRead);
_Bool circular_buffer_read(CircularBuffer BufferP, int *iValeur, _Bool bRead);
_Bool circular_buffer_write(CircularBuffer BufferP, int iValeur, _Bool bRead);

#endif /*CIRCULAR_BUFFER_HEADER*/


