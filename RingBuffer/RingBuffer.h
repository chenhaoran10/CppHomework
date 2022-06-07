#pragma once
#include<vector>
#include<iostream>
using namespace std;
class RingBuffer
{
	//���ζ��У����һ��λ�ò������жϿ�����,��βָ�����һ��Ԫ�غ�һ��λ�á�
	//�ӿ�ʱ����ͷ=��β������ʱ��(front-rear+maxSize)%maxSize
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

