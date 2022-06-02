#include "RingBuffer.h"

RingBuffer::RingBuffer(const int& size):maxSize(size),front(0),rear(0)
{
	data[size];
}
RingBuffer::~RingBuffer()
{
	delete[] data;
}
bool RingBuffer::isEmpty()
{
	return front==rear;
}

bool RingBuffer::isFull()
{
	return (rear+1)%maxSize==front;
}

void RingBuffer::push(char* input)
{
	if (isFull)
	{
		//�Զ�����
	}
	else
	{
		data[rear] = input;
		rear++;
	}
}

char* RingBuffer::pop()
{
	if (isEmpty)
	{
		cout << "empty" << endl;
		return nullptr;
	}
	else
	{
		front++;
		//�Զ�����
		char* res = data[front - 1];
		return res;
	}
}

int RingBuffer::length()
{
	return (rear-front+maxSize)%maxSize;
}
