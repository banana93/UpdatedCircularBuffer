#include "unity.h"
#include "CircularBuffer.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_circularBufferNew_given_6_should_allocate_circularBuffer_object_with_a_buffer_of_6(void)
{
	CircularBuffer *cb = circularBufferNew(6);
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->tail);
	circularBufferDel(cb);
}

void test_circularBufferAdd_should_generate_an_exception_due_to_the_buffer_is_full(void)
{
	CircularBuffer *circularBuffer = circularBufferNew(6);
	CEXCEPTION_T err;
	
	Try
	{
		circularBufferAdd(circularBuffer, 1);
		circularBufferAdd(circularBuffer, 2);
		circularBufferAdd(circularBuffer, 3);
		circularBufferAdd(circularBuffer, 4);
		circularBufferAdd(circularBuffer, 5);
		circularBufferAdd(circularBuffer, 6);
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		printf("Error Code [%d] due to the buffer is full. \n", err);
		TEST_ASSERT_EQUAL(1, circularBuffer->buffer[0]);
		TEST_ASSERT_EQUAL(2, circularBuffer->buffer[1]);
		TEST_ASSERT_EQUAL(3, circularBuffer->buffer[2]);
		TEST_ASSERT_EQUAL(4, circularBuffer->buffer[3]);
		TEST_ASSERT_EQUAL(5, circularBuffer->buffer[4]);
		TEST_ASSERT_EQUAL(6, circularBuffer->buffer[5]);
		
	}
	circularBufferDel(circularBuffer);
}

void test_circularBufferAdd_given_valueToAdd_10_should_return_10(void)
{
	CircularBuffer *circularBuffer = circularBufferNew(6);

		circularBufferAdd(circularBuffer, 10);
		TEST_ASSERT_EQUAL(10, circularBuffer->buffer[0]);
	
	circularBufferDel(circularBuffer);
}

void test_circularBufferRemove_should_generate_an_exception_due_to_the_buffer_is_empty(void)
{

	CircularBuffer *circularBuffer = circularBufferNew(6);
	CEXCEPTION_T err;
	
	Try
	{
		circularBufferRemove(circularBuffer);
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Error Code [%d] due to the buffer is empty. \n", err);
	}
	circularBufferDel(circularBuffer);
}


void test_circularBufferRemove_the_value_13_pushed_should_removed_value_13(void)
{
	int removedValue;
	CircularBuffer *circularBuffer = circularBufferNew(6);
	
	circularBufferAdd(circularBuffer, 13);
	removedValue = circularBufferRemove(circularBuffer);
	
	TEST_ASSERT_EQUAL(13, removedValue);
	
	circularBufferDel(circularBuffer);
}
	
	

	
	



