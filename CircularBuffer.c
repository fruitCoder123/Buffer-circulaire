#include "CircularBuffer.h"

_Bool circular_buffer_init(CircularBuffer BufferP, _Bool bRead) {

	int iLastValue;

	//Initialize the buffer
	for (size_t i = 0; i < CIRCULAR_BUFFER_LENGHT; i++)
	{

		iLastValue = *(BufferP.ArrayPointer + i);
		*(BufferP.ArrayPointer + i) = NULL;
		if (bRead)
		{
			printf("%i : Address Value : %p | Read last Value : %i | Read new value : %i \n", i, BufferP.ArrayPointer + i, iLastValue, *(BufferP.ArrayPointer + i));
		}

	}

	return 1;
}

_Bool circular_buffer_read(CircularBuffer BufferP, int *iValeur, _Bool bRead) {

	//Read the old value
	if (bRead)
	{
		printf("Tail value : %i | Address Value : %p | Read old value : %i \n", *BufferP.ReadPointer, BufferP.ArrayPointer + *BufferP.ReadPointer, *(BufferP.ArrayPointer + *BufferP.ReadPointer));
	}

	//Lecture du buffer et copie dans iValeur
	*iValeur = *(BufferP.ArrayPointer + *BufferP.ReadPointer);

	//Réinitialiser la valeur du tableau
	*(BufferP.ArrayPointer + *BufferP.ReadPointer) = NULL;

	//Check the new value
	if (bRead)
	{
		printf("Tail value : %i | Address Value : %p | Read new value : %i \n", *BufferP.ReadPointer, BufferP.ArrayPointer + *BufferP.ReadPointer, *(BufferP.ArrayPointer + *BufferP.ReadPointer));
	}

	//Increment the tailpointer
	*BufferP.ReadPointer = (*BufferP.ReadPointer + 1) % CIRCULAR_BUFFER_LENGHT;

	return 1;
}

//Circular buffer
_Bool circular_buffer_write(CircularBuffer BufferP, int iValeur, _Bool bRead) {

	//Read the old value
	if (bRead)
	{
		printf("Head value : %i | Address Value : %p | Read old value : %i \n", *BufferP.WritePointer, BufferP.ArrayPointer + *BufferP.WritePointer, *(BufferP.ArrayPointer + *BufferP.WritePointer));
	}

	if ((*(BufferP.WritePointer) + 1) % CIRCULAR_BUFFER_LENGHT == *BufferP.ReadPointer) {

		if (bRead)
		{
			printf("Can't write anymore\n");
		}

		return 0;

	}
	else {

		*(BufferP.ArrayPointer + *BufferP.WritePointer) = iValeur;

		//Read the new value
		if (bRead)
		{
			printf("Head value : %i | Address Value : %p | Read new value : %i \n", *BufferP.WritePointer, BufferP.ArrayPointer + *BufferP.WritePointer, *(BufferP.ArrayPointer + *BufferP.WritePointer));
		}

		*BufferP.WritePointer = (*BufferP.WritePointer + 1) % CIRCULAR_BUFFER_LENGHT;

		return 1;
	}

}