#pragma once
#ifndef SKIPLISTPRO_SKIPLIST_H
#define SKIPLISTPRO_SKIPLIST_H

#include<cstddef>
#include<cassert>
#include<ctime>
#include"Node.h"
#include"random.h"

using namespace std;

#define DEBUG

template<typename K,typename V>
class SkipList {

public:
	SkipList(K footerKey) :rnd(0x12345678) {
		creatList(footerKey);
	}
};
	~SkipList() {
	freeList();
	}
	Node<K, V>* search(K key)const;
	bool insert(K key, V value);
	bool remove(K key, V& value);

	int size() {
		return nodeCount;
	}
	int getLevel() {
		return level;
	}
private:
	void createList(K footerKey);
	void freeList();
	void createNode(int level, Node<K, V>*& node);
	void createNode(int level, Node<K, V>*& node, K key, V value);

	int getRandomLevel();

	void dumpAllNodes();























#endif // !SKIPLISTPRO_SKIPLIST_H
