#pragma once
#include"Node.h"
#include<vector>
using namespace std;

class List
{
private:
	Node* head;
public:
	List(const int& input) {
		head = new Node(input);
	};
	~List() {
		Node* p = head;
		while (p != nullptr) {
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	Node* push(const int& input)
	{
		Node* p = head;
		while ((p->next) != nullptr) {
			p = p->next;
		}
		Node* q = new Node(input);
		p->next = q;
		q->pre = p;
		return q;
	};
	Node* insert(Node* insertPos,const int& input)
	{
		Node* p = head;
		while (p!=insertPos&&p!=nullptr)
		{
			p = p->next;
		}
		if (p != nullptr)
		{
			Node* q = new Node(input);
			q->next = p->next;
			q->pre = p;
			p->next = q;
			return q;
		}
		else
		{
			return nullptr;
		}
	}
	Node* find(const int& input) {
		Node* p = head;
		while (p != nullptr)
		{
			if (p->data = input)
			{
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}
	void remove(Node* node) {
		Node* p = head;
		while (p != nullptr)
		{
			if (p==node)
			{
				if (p->next != nullptr)
				{
					Node* q = p->pre;
					Node* h = p->next;
					q->next = h;
					h->pre = q;
					delete p;
					break;
				}
				else
				{
					Node* q = p->pre;
					q->next = nullptr;
					delete p;
					break;
				}
			}
			else {
				p = p->next;
			}
			
		}
	}
	vector<Node*> popAll() {
		vector<Node*> res;
		Node* p = head;
		while (p!=nullptr)
		{
			res.push_back(p);
			p = p->next;
		}
		return res;
	}
};

