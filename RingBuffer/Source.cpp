#include"RingBuffer.h"

int main()
{
	int initSize = 256;
	const char* data = "123456789";

	auto buffer = new RingBuffer(initSize);
	// ��ʼ�����������
	srand(time(NULL));
	int length = strlen(data) + 1;
	for (int ii = 0; ii < 1000; ii++) {
		int pushCount = rand() % 10;
		for (int jj = 0; jj < pushCount; jj++)
		{
			buffer->push(data, length);
		}
		char out[128];
		int popCount = rand() % 10;
		for (int jj = 0; jj < popCount; jj++)
		{
			// ��ĳ��λ�ÿ�ʼPOP()
			buffer->pop(&out[0], sizeof(out));
		}
	}
	return 0;
}