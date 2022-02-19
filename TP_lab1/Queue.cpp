#include "Queue.h"

Queue::Queue() : queue_(nullptr), size_(0) {
}

bool Queue::empty() const {
	return !((bool)size_);
}

int Queue::size() const {
	return size_;
}

int Queue::pop() {
	if (size_) {
		Item* temp = queue_;
		try {
			queue_ = new Item[size_ - 1];
			for (int i = 1; i < size_; i++)
				queue_[i - 1] = temp[i];
			size_--;
			int value = temp[0].value;
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

int Queue::front() const {
	if (size_)
		return queue_[0].value;
	std::cout << "Error: The queue is empty!" << std::endl;
	return 0;
}

int Queue::back() const {
	if (size_)
		return queue_[size_ - 1].value;
	std::cout << "Error: The queue is empty!" << std::endl;
	return 0;
}

void Queue::copy(Queue that) {
	if (that.size_) {
		try {
			delete[] this->queue_;
			this->size_ = that.size_;
			this->queue_ = new Item[that.size_];
			for (int i = 0; i < that.size_; i++)
				this->queue_[i] = that.queue_[i];
		}
		catch (const std::bad_alloc& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: The copied array is empty!" << std::endl;
}

void Queue::merge(Queue*, Queue*) {

}