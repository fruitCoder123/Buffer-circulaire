
#ifndef CIRCULAR_BUFFER_HEADER
#define CIRCULAR_BUFFER_HEADER

#include <stdint.h>

#define CB_LENGHT                   8          // has t be a power of 2 !!
#define CB_STORAGE_TYPE             uint8_t
#define CB_BOOL                     _Bool

#if CIRCULAR_BUFFER_LENGHT < 0xFF
#   define CB_INDEX_TYPE            uint8_t
#elif CIRCULAR_BUFFER_LENGHT < 0xFFFF
#   define CB_INDEX_TYPE            uint16_t
#else
#   error Buffer size not supported
#endif

typedef struct CircularBuffer
{
	CB_INDEX_TYPE WritePointer;
	CB_INDEX_TYPE ReadPointer;
	CB_STORAGE_TYPE BufferArray[CB_LENGHT];
} CircularBuffer;

CB_BOOL circular_buffer_init(CircularBuffer *BufferP);
CB_BOOL circular_buffer_read(CircularBuffer *BufferP, CB_STORAGE_TYPE *value);
CB_BOOL circular_buffer_write(CircularBuffer *BufferP, CB_STORAGE_TYPE value);

#endif /*CIRCULAR_BUFFER_HEADER*/


