#include"RingBuffer.h"

int main()
{
	const char* data = "123456789";

	auto buffer = new RingBuffer(256);
	buffer->push(data, 10);
	buffer->pop(5);


	return 0;
}