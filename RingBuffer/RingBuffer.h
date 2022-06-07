#pragma once
#include<vector>
#include<iostream>
using namespace std;
class RingBuffer
{
	//环形队列，最后一个位置不存以判断空与满,队尾指向最后一个元素后一个位置。
	//队空时，队头=队尾，队满时，(front-rear+maxSize)%maxSize
private:
	int m_size;
	int capacity;
	int begin;
	int end;
	char* data;
	void expand();
	void reduce();
public:
	RingBuffer(const int& size);
	~RingBuffer();
	bool isEmpty();
	bool isFull();
	void push(const char* data,int size);
	void pop(int count);
	int length();

};

