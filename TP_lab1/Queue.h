#pragma once
#ifndef QUEUE_H
#define QUEUE_H
class Queue {
private:
	int* queue_;
	int size_;
public:
	Queue();

	bool empty();
	int size();

	int pop();
	void push(int);

	int* front();
	int* back();

	void copy(Queue);
	void merge(Queue, Queue);

	~Queue();
};
#endif QUEUE_H