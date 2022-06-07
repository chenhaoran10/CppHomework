#include "RingBuffer.h"

RingBuffer::RingBuffer(const int& _capacity):m_size(0),begin(0),end(0),capacity(_capacity)
{
	data[_capacity];
}
RingBuffer::~RingBuffer()
{
	capacity = 0;
	m_size = 0;
	begin = 0;
	delete[] data;
}
bool RingBuffer::isEmpty()
{
	//end指向的位置不存数据，牺牲一个格子来判断空
	return begin==end;
}

bool RingBuffer::isFull()
{
	return (end +1)%capacity==begin;
}

void RingBuffer::push(const char* input,int size)
{
	if (size==0)
	{
		return;
	}
	while(size + m_size > capacity)
	{
		expand();
	}
	if (end + size <= capacity)
	{
		memcpy(data + end, input, size);
		end = (end + size)%capacity;
	}
	else
	{
		auto size_1 = capacity - end;
		memcpy(data + end, input, size_1);
		memcpy(data, input + size_1, size - size_1);
		end = (end + size) % capacity;
	}
	m_size += size;
}

void RingBuffer::pop(int count)
{
	if (count <= 0)
		return;
	int pop_size = min(count, m_size);
	if (pop_size + begin <= capacity)
	{
		begin = (begin + pop_size) % capacity;
	}
	else
	{
		int size_t = capacity - begin;
		begin = pop_size - size_t;
	}
	m_size -= pop_size;
	reduce();
}

int RingBuffer::length()
{
	return (end-begin+capacity)%capacity;	
}
void RingBuffer::expand()
{
	int expand_capacity = capacity ? capacity * 2 : 2;
	char* new_buf = new char[expand_capacity];
	if (begin + m_size <= capacity)
	{
		memcpy(new_buf, data + begin, m_size);
	}
	else
	{
		int size_t = capacity - begin;
		memcpy(new_buf, data + begin, size_t);
		memcpy(new_buf + size_t, data, m_size - size_t);
	}
	begin = 0;
	capacity = expand_capacity;
	end = m_size;
	delete[]data;
	data = new_buf;
}
void RingBuffer::reduce()
{
	if (capacity < 2)
		return;
	int reduce_capacity = capacity;
	while (reduce_capacity / 2 > m_size && reduce_capacity >= 2)
	{
		reduce_capacity /= 2;
	}
	char* new_buf = new char[reduce_capacity];
	if (begin + m_size <= capacity)
	{
		memcpy(new_buf, data + begin, m_size);
	}
	else
	{
		int size_t = capacity - begin;
		memcpy(new_buf,data+begin,size_t);
		memcpy(new_buf+size_t,data,m_size-size_t);
	}
	capacity = reduce_capacity;
	begin = 0;
	end = m_size;
	delete[]data;
	data = new_buf;
}