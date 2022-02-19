#pragma once
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
class Queue {
private:
	struct Item {
		int value;
		Item* prev;
	};
	Item* queue_;
	int size_;
protected:

public:
	Queue();
	bool empty() const;
	int size() const;
	int pop();
	void push(int);
	int front() const;
	int back() const;
	void copy(Queue);
	void merge(Queue, Queue);
};
#endif QUEUE_H