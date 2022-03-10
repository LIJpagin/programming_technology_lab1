#pragma once
#include <iostream>
#include "Queue.h"
#ifndef QUEUE3_H
#define QUEUE3_H
class Queue3 : public Queue {
public:
	void copy();
	void merge();
	void print() const;
};
#endif QUEUE3_H