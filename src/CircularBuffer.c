#include "CircularBuffer.h"
#include "CException.h"
#include "stdio.h"
#include "malloc.h"

/*
	In this function, this function act as a function that creates a new buffer 
	everytime I call this function.
*/

CircularBuffer *circularBufferNew(int length)
{
	CircularBuffer *circularBuffer;
	
	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
	circularBuffer->length = 6;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer;
	circularBuffer->tail = circularBuffer->buffer;
	
	return circularBuffer;
}

void circularBufferDel(CircularBuffer *circularBuffer)
{
	free(circularBuffer);
	
}

/*
	In this function, the circularBuffer will be added in with value,
	as the value is fit in, the size also will increase.
*/
void circularBufferAdd(CircularBuffer *circularBuffer, int valueToAdd)
{
	if(circularBuffer->length == circularBuffer->size) // if the total space(length) of the buffer is equal as the size means that the buffer is full
	{
		Throw(ERR_BUFFER_IS_FULL); // throw an exception to indicate that the buffer is full
	}

	if(circularBuffer->size != 0) // if the size is not zero the head will point to the next location
		circularBuffer->head++;
	
	circularBuffer->buffer[circularBuffer->size] = valueToAdd; // valueToAdd will be fit into the buffer
	circularBuffer->size++; // when the value is fit in, the size increase
}

/*
	In this function, the size will decrease as the tail will return the 
	value in the buffer and send to the result so that it can return it.
	As the result is taken out, the tail pointer will point to the next location.
*/

int circularBufferRemove(CircularBuffer *circularBuffer)
{
	int result; // declaration of the result
	if(circularBuffer->size == 0) // if the size is 0, it will throw an exception
	{
		Throw(ERR_BUFFER_IS_EMPTY);
	}
	
	circularBuffer->size--; // the size decrease
	result = *circularBuffer->tail; // the value in the buffer is moved to result
	circularBuffer->tail++; // the tail points to the next location
	
	return result; // the result is returned
}
