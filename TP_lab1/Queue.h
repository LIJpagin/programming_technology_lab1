#pragma once
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
struct Item {
	int value;
	Item* prev;
};
class Queue {
private:
	Item* queue_;
	int size_;
protected:
	Queue(const Queue&);
	Queue& operator = (const Queue& that);
	friend std::ostream& operator<< (std::ostream&, const Queue&);
	friend Queue operator+ (const Queue&, const Queue&);
	bool empty() const;
	int front() const;
	int back() const;
	int* getArray() const;
	void clear();
public:
	Queue() : queue_(nullptr), size_(0) { }
	int size() const;
	int pop();
	void push(int);
	void copy(const Queue&);
	void merge(Queue, Queue);
};

#endif QUEUE_H