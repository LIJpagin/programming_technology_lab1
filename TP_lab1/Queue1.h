#pragma once
#include <iostream>
#include "Queue.h"
#ifndef QUEUE1_H
#define QUEUE1_H
class Queue1 : private Queue {
public:
	Queue1() { }
	void push_UI();
	void pop_UI();
	void print_UI() const;
	void task();
	void copy_UI();
	void merge_UI();
	void clear_UI();
	Queue& fillQueue();
};
#endif QUEUE1_H