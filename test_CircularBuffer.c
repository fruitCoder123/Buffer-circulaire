
#include <CircularBuffer.h>

void dump_buffer_contents(CircularBuffer *buffer);


void test_circular_buffer(void)
{
int cnt;

    CircularBuffer my_buffer;

    circular_buffer_init(&my_buffer);

    for(cnt=0; cnt < 16; cnt++)
    {
        if(!circular_buffer_write(&my_buffer, cnt))
        {
            printf("Can't write anymore, buffer full. Written %d items so far\n", cnt);
            break;
        }
        else
        {
            printf("Written %d at position %d\n", cnt, cnt);
        }
    }

    dump_buffer_contents(&my_buffer);

    circular_buffer_write(&my_buffer, 0x55);
    circular_buffer_write(&my_buffer, 0xAA);
    circular_buffer_write(&my_buffer, 0x55);
    circular_buffer_write(&my_buffer, 0xAA);

    dump_buffer_contents(&my_buffer);

    return 0;
}

void dump_buffer_contents(CircularBuffer *buffer)
{
    CB_INDEX_TYPE read_index;
    CB_STORAGE_TYPE read_value;

    read_index = buffer->ReadPointer;
    while(circular_buffer_read(buffer, &read_value) == 1)
    {
        printf("Read: %x from position %d\n", read_value, read_index);
        read_index = buffer->ReadPointer;
    }
}
