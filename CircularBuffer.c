#include <CircularBuffer.h>

CB_BOOL circular_buffer_init(CircularBuffer *BufferP)
{
    BufferP->ReadPointer = 0;
    BufferP->WritePointer = 0;
    BufferP->is_full = 0;

    //Initialize the buffer
    for (CB_INDEX_TYPE i = 0; i < CB_LENGHT; i++)
    {
        BufferP->BufferArray[i] = 0;
    }

    return 1;
}

CB_BOOL circular_buffer_read(CircularBuffer *BufferP, CB_STORAGE_TYPE *value)
{
    if(BufferP->ReadPointer == BufferP->WritePointer && !BufferP->is_full)
    {
        // Nothing to read
        return 0;
    }

    *value = BufferP->BufferArray[BufferP->ReadPointer];

    //Increment the read pointer
    BufferP->ReadPointer = (BufferP->ReadPointer + 1) % CB_LENGHT;
    BufferP->is_full = 0;

    return 1;
}

CB_BOOL circular_buffer_write(CircularBuffer *BufferP, CB_STORAGE_TYPE value)
{
    if(BufferP->is_full)
    {
        // Buffer full
        return 0;
    }
    else
    {
        BufferP->BufferArray[BufferP->WritePointer] = value;
        BufferP->WritePointer = (BufferP->WritePointer + 1) % CB_LENGHT;
        BufferP->is_full = BufferP->WritePointer == BufferP->ReadPointer;
        return 1;
    }
}
