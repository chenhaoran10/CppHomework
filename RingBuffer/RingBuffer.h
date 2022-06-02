#pragma once
#include<vector>
#include<iostream>
using namespace std;
class RingBuffer
{
	//环形队列，最后一个位置不存以判断空与满,队尾指向最后一个元素后一个位置。
	//队空时，队头=队尾，队满时，(front-rear+maxSize)%maxSize
private:
	int maxSize;
	int front;
	int rear;
	char* data[];
public:
	RingBuffer(const int& size);
	~RingBuffer();
	bool isEmpty();
	bool isFull();
	void push(char* data);
	char* pop();
	int length();
};

