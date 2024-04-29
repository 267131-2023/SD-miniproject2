#pragma once
#include <iostream>

using namespace std;

struct PriorityQueueElement {
	int value;
	int priority;

	PriorityQueueElement() : value(0), priority(0) {}

	PriorityQueueElement(int val, int pr) : value(val), priority(pr) {}
};

class Heap
{
private:
	PriorityQueueElement *heapArray;
	int capacity;
	int size;

	void heapifyUp(int index);
	void heapifyDown(int index);
	int parent(int index);
	int left(int index);
	int right(int index);

public:
	Heap(int capacity) : capacity(capacity), size(0) {
		heapArray = new PriorityQueueElement[this->capacity];
	}

	~Heap() {
		delete[] heapArray;
	}

	void insert(int value, int priority);
	void modifyKey(int value, int newPriority);

	int extractMax();
	int findMax();
	int returnSize();


};

