#pragma once
#include <iostream>
#include "Queue.h"
#ifndef QUEUE1_H
#define QUEUE1_H
class Queue1 : private Queue {
public:
	Queue1() { }
	void push(int);
	int pop();
	void print() const;
	void copy();
	void merge();
	bool isEmpty() const;
};
#endif QUEUE1_H