#include "CircularBuffer.h"

CB_BOOL circular_buffer_init(CircularBuffer *BufferP)
{
	BufferP->ReadPointer = 0;
	BufferP->WritePointer = 0;

	//Initialize the buffer
	for (CB_INDEX_TYPE i = 0; i < CB_LENGHT; i++)
	{
		BufferP->BufferArray[i] = 0;
	}

	return 1;
}

CB_BOOL circular_buffer_read(CircularBuffer *BufferP, CB_STORAGE_TYPE *value)
{
	if(BufferP->ReadPointer == BufferP->WritePointer)
    {
        // Nothing to read
        return 0;
    }

	*value = BufferP->BufferArray[BufferP->ReadPointer];

	//Increment the read pointer
	BufferP->ReadPointer = (BufferP->ReadPointer + 1) % CB_LENGHT;

	return 1;
}

CB_BOOL circular_buffer_write(CircularBuffer *BufferP, CB_STORAGE_TYPE value)
{
	if ((BufferP->WritePointer + 1) % CB_LENGHT == BufferP->ReadPointer)
    {
		// Buffer full
		return 0;
	}
	else
    {
		BufferP->BufferArray[BufferP->WritePointer] = value;
		BufferP->WritePointer = (BufferP->WritePointer + 1) % CB_LENGHT;
		return 1;
	}
}
