#pragma once
class Node
{
public:
	Node* pre;
	Node* next;
	int data;
	Node() = delete;
	Node(const int& input):data(input) {
		pre = nullptr;
		next = nullptr;
	}
	~Node(){}
};