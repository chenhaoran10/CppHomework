#include"Array.h"


int main()
{
	auto arr = new Array<int>();
	// ��������4���ڴ�
	arr->reserve(4);
	arr->push(1);
	arr->remove(5);
	arr->pop();
	arr->clear();
	int index = arr->findIndex(1);
	return 0;
}