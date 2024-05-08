#include "Heap.h"
#include <iostream>

using namespace std;

void Heap::heapifyUp(int index) {

	while (index > 0 && heapArray[parent(index)].priority < heapArray[index].priority) {
		swap(heapArray[index], heapArray[parent(index)]);
		index = parent(index);
	}
}

void Heap::heapifyDown(int index) {

	int maximum = index;
	int leftChild = left(index);
	int rightChild = right(index);

	if (leftChild < size && heapArray[leftChild].priority > heapArray[maximum].priority) {
		maximum = leftChild;
	}

	if (rightChild < size && heapArray[rightChild].priority > heapArray[maximum].priority) {
		maximum = rightChild;
	}

	if (index != maximum) {
		swap(heapArray[index], heapArray[maximum]);
		heapifyDown(maximum);
	}
}

int Heap::parent(int index) {
	return (index - 1) / 2;
}

int Heap::left(int index) {
	return 2 * index + 1;
}

int Heap::right(int index) {
	return 2 * index + 2;
}

void Heap::insert(int value, int priority) {
	if (size == capacity) {
		capacity *= 2;
		PriorityQueueElement* newHeapArray = new PriorityQueueElement[capacity];

		for (int i = 0; i < size; i++) {
			newHeapArray[i] = heapArray[i];
		}
		newHeapArray[size] = PriorityQueueElement(value, priority);
		delete[] heapArray;
		heapArray = newHeapArray;

		heapifyUp(size);
		size++;
	}
	else {
		heapArray[size] = PriorityQueueElement(value, priority);
		heapifyUp(size);
		size++;
	}
}

void Heap::modifyKey(int value, int newPriority) {
	for (int i = 0; i < size; i++) {
		if (heapArray[i].value == value) {
			int oldPriority = heapArray[i].priority;
			heapArray[i].priority = newPriority;
			if (newPriority > oldPriority) {
				heapifyUp(i);
			}
			else {
				heapifyDown(i);
			}
			return;
		}
	}
}

int Heap::extractMax() {

	if (size == 0) {
		cout << "Kolejka jest pusta" << endl;
		return -1;
	}

	heapArray[0] = heapArray[size - 1];
	size--;
	heapifyDown(0);
	int maxValue = heapArray[0].value;
	return maxValue;
}

int Heap::findMax() {

	if (size == 0) {
		cout << "Kolejka jest pusta" << endl;
		return -1;
	}

	int maxValue = heapArray[0].value;
	return maxValue;
}

int Heap::returnSize() {
	return size;
}