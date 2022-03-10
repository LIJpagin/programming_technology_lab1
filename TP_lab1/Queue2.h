#pragma once
#include <iostream>
#include "Queue.h"
#ifndef QUEUE2_H
#define QUEUE2_H
class Queue2 : public Queue {
public:
	void copy();
	void merge();
	void print() const;
};
#endif QUEUE2_H