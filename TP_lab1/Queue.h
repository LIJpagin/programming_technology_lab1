#pragma once

#include <iostream>
#include <windows.h>

#ifndef QUEUE_H
#define QUEUE_H

struct Item {
	int data;
	Item* next;
};

class Queue {
private:
	Item* head_, * tail_;
public:
	Queue() : head_(nullptr), tail_(nullptr) { }
	Queue(int, ...);
	Queue(const Queue&);

	bool isEmpty() const;
	int size() const;
	int pop();
	void push(int);
	Queue copy();
	Queue merge(Queue);
	Item* front() const;
	Item* back() const;
	int* getArray() const;

	Queue& operator = (const Queue& that);
	friend Queue operator+ (const Queue&, const Queue&);
	friend std::ostream& operator<< (std::ostream&, const Queue&);
	friend bool operator== (const Queue&, const Queue&);

	void clear();
	~Queue() { clear(); }
};

#endif QUEUE_H