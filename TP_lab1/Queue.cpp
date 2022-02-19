#include "Queue.h"

Queue::Queue() : queue_(nullptr), size_(0) {
}

bool Queue::empty() {
	return !((bool)size_);
}

int Queue::size() {
	return size_;
}

int Queue::pop() {
	if (size_) {
		Item* temp = queue_;
		try {
			queue_ = new Item[size_ - 1];
			for (int i = 0; i < size_ - 1; i++)
				queue_[i] = temp[i];
			size_--;
			int value = temp[size_].value;
			delete[] temp;
			return value;
		}
		catch (const std::bad_alloc& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else 
		std::cout << "Error: The queue is empty!" << std::endl;
	return 0;
}

void Queue::push(int value) {
	Item* temp = queue_;
	try {
		queue_ = new Item[size_ + 1];
		for (int i = 0; i < size_; i++)
			queue_[i] = temp[i];
		queue_[size_].value = value;
		queue_[size_].prev = size_ ? &queue_[size_ - 1] : nullptr;
		size_++;
		if (size_)
			delete[] temp;
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int Queue::front() {
	if (size_)
		return queue_[0].value;
	std::cout << "Error: The queue is empty!" << std::endl;
	return 0;
}

int Queue::back() {
	if (size_)
		return queue_[size_ - 1].value;
	std::cout << "Error: The queue is empty!" << std::endl;
	return 0;
}

void Queue::copy(Queue) {

}

void Queue::merge(Queue, Queue) {

}

Queue::~Queue() {
	delete(queue_);
}