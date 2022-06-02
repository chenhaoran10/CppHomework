#pragma once
#include<vector>
#include<iostream>
using namespace std;
class RingBuffer
{
	//���ζ��У����һ��λ�ò������жϿ�����,��βָ�����һ��Ԫ�غ�һ��λ�á�
	//�ӿ�ʱ����ͷ=��β������ʱ��(front-rear+maxSize)%maxSize
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

