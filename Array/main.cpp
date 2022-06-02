#include"Array.h"


int main()
{
	auto arr = new Array<int>();
	//arr = { 1,2,3,4,5 };
	arr->reserve(4);
	arr->push(1);
	arr->remove(5);
	arr->pop();
	arr->clear();
	int index = arr->findIndex(1);
	return 0;
}