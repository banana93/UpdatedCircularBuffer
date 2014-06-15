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
		printf("Error code %d due to buffer is full", ERR_BUFFER_IS_FULL);
		circularBufferDel(circularBuffer);
	}
	
}

void test_circularBufferAdd_given_valueToAdd_1_should_return_1(void)
{
	CircularBuffer *circularBuffer = circularBufferNew(6);

		circularBufferAdd(circularBuffer, 1);
		TEST_ASSERT_EQUAL(1, circularBuffer->buffer[0]);
	
	circularBufferDel(circularBuffer);
}

void test_circularBufferRemove_should_generate_an_exception_due_to_the_buffer_is_empty(void)
{
	CircularBuffer *circularBuffer = circularBufferNew(6);
	CEXCEPTION_T err;
	
	Try
	{
		circularBufferRemove(circularBuffer);
		TEST_FAIL_MESSAGE("Should generate an exception due to the buffer is empty.");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Error code %d due to the buffer is empty", ERR_BUFFER_IS_EMPTY);
		circularBufferDel(circularBuffer);
	}
	
}


void test_circularBufferRemove_after_removed_should_get_the_value_of_0(void)
{
	CircularBuffer *circularBuffer = circularBufferNew(6);
	circularBufferRemove(circularBuffer);
	
	TEST_ASSERT_EQUAL(0, circularBuffer->buffer[0]);
	TEST_ASSERT_EQUAL(0, circularBuffer->buffer[1]);
	TEST_ASSERT_EQUAL(0, circularBuffer->buffer[2]);
	TEST_ASSERT_EQUAL(0, circularBuffer->buffer[3]);
	TEST_ASSERT_EQUAL(0, circularBuffer->buffer[4]);
	TEST_ASSERT_EQUAL(0, circularBuffer->buffer[5]);
	
	circularBufferDel(circularBuffer);
}
	
	

	
	



