#include "CircularBuffer.h"
#include "CException.h"
#include "stdio.h"
#include "malloc.h"

CircularBuffer *circularBufferNew(int length)
{
	CircularBuffer *circularBuffer;
	
	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
	circularBuffer->length = length;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer;
	circularBuffer->tail = circularBuffer->buffer;
	
	return circularBuffer;
}

void circularBufferDel(CircularBuffer *circularBuffer)
{
	free(circularBuffer);
	
}

void circularBufferAdd(CircularBuffer *circularBuffer, int valueToAdd)
{
	
	*circularBuffer->tail = valueToAdd; // put a value into the buffer 
	circularBuffer->tail++; // after the value is placed, the tail point to next
	circularBuffer->size++; // increase the size whenever the tail gets in value
	
	if(circularBuffer->size == circularBuffer->length) // if the total space(length) of the buffer is equal as the size means that the buffer is full
	{
		Throw(ERR_BUFFER_IS_FULL); // throw an exception to indicate that the buffer is full
	}
	
	if(circularBuffer->size == 6) // if the size of the buffer is full
		circularBuffer->tail = &circularBuffer->buffer[0]; // reset the address of the head to the starting of the buffer
	
}

int circularBufferRemove(CircularBuffer *circularBuffer)
{
	if(circularBuffer->size == 0)
	{
		Throw(ERR_BUFFER_IS_EMPTY);
	}
	
	*circularBuffer->tail = 0; // set the tail value as zero to clear the value in the buffer
	circularBuffer->tail++; // the tail will point next
	circularBuffer->size--; // as the data is removed the size will also decrease
	
	if(circularBuffer->size == 0)
		circularBuffer->tail = &circularBuffer->buffer[0];
}
