#include"List.h"

int main() {
	auto list1= new List(4);
	auto list2 = new List(5);
	auto node1 = list1->push(2);
	auto node2 = list1->insert(node1, 3);
	auto res = list1->find(4);
	list1->remove(node2);
	list1->popAll();
	return 0;
}