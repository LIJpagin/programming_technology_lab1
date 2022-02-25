#include "Queue.h"
int* Queue::getArray() const {
	int* array = nullptr;
	try {
		array = new int[size_];
		for (int i = 0; i < size_; i++)
			array[i] = queue_[i].value;
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return array;
}

bool Queue::empty() const {
	return !((bool)size_);
}

int Queue::size() const {
	return size_;
}

int Queue::pop() {
	if (empty())
		throw new std::exception("Error: The queue is empty!");
	try {
		Item* temp = queue_;
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

void Queue::push(int value) {
	Item* temp = queue_;
	try {
		queue_ = new Item[size_ + 1];
		for (int i = 0; i < size_; i++)
			queue_[i] = temp[i];
		queue_[size_].value = value;
		queue_[size_].prev = size_ ? &queue_[size_ - 1] : nullptr;
		size_++;
		delete[] temp;
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int Queue::front() const {
	if (empty())
		throw new std::exception("Error: The queue is empty!");
	return queue_[0].value;
}

int Queue::back() const {
	if (empty())
		throw new std::exception("Error: The queue is empty!");
	return queue_[size_ - 1].value;
}

void Queue::copy(const Queue& that) {
	if (that.empty())
		throw new std::exception("Error: The copied array is empty!");

	try {
		delete[] this->queue_;
		this->size_ = that.size_;
		this->queue_ = new Item[this->size_];
		for (auto i = 0; i < that.size_; i++)
			this->queue_[i] = that.queue_[i];
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void Queue::merge(Queue first, Queue second) {
	try {
		if (this->queue_ == first.queue_) {
			Item* temp = this->queue_;
			this->queue_ = new Item[first.size_ + second.size_];
			auto counter = 0;
			for (; counter < this->size_; counter++)
				this->queue_[counter] = temp[counter];
			for (; counter < this->size_ + second.size_; counter++)
				this->queue_[counter] = second.queue_[counter - this->size_];
			this->size_ = this->size_ + second.size_;
			delete[] temp;
		}
		else if (this->queue_ == second.queue_) {
			Item* temp = this->queue_;
			this->queue_ = new Item[first.size_ + second.size_];
			auto counter = 0;
			for (; counter <first.size_; counter++)
				this->queue_[counter] = first.queue_[counter];
			for (; counter < first.size_ + this->size_; counter++)
				this->queue_[counter] = temp[counter - first.size_];
			this->size_ = first.size_ + this->size_;
			delete[] temp;
		}
		else {
			delete[] this->queue_;
			this->queue_ = new Item[first.size_ + second.size_];
			auto counter = 0;
			for (; counter < first.size_; counter++)
				this->queue_[counter] = first.queue_[counter];
			for(; counter < first.size_ + second.size_; counter++)
				this->queue_[counter] = second.queue_[counter - first.size_];
			this->size_ = first.size_ + second.size_;
		}
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void Queue::clear() {
	this->size_ = 0;
	if (this->queue_)
		delete[] this->queue_;
}

std::ostream& operator<< (std::ostream& out, const Queue& queue) {
	int* array = new int[queue.size()];
	array = queue.getArray();
	for (int i = 0; i < queue.size(); i++)
		out << array[i] << " ";
	return out;
}

Queue::Queue(const Queue& that) {
	this->size_ = that.size_;
	this->queue_ = new Item[this->size_];
	for (auto i = 0; i < this->size_; i++)
		this->queue_[i] = that.queue_[i];
}

Queue& Queue::operator= (const Queue& that) {
	if (this == &that) return *this;
	if (this->size_) delete[] this->queue_;
	this->size_ = that.size_;
	this->queue_ = new Item[this->size_];
	for (auto i = 0; i < this->size_; i++)
		this->queue_[i] = that.queue_[i];
	return *this;
}

Queue operator+ (const Queue& q1, const Queue& q2) {
	Queue queue;
	queue.size_ = q1.size_ + q2.size_;
	queue.queue_ = new Item[queue.size_];
	auto counter = 0;
	for (; counter < q1.size_; counter++)
		queue.queue_[counter] = q1.queue_[counter];
	for (; counter < queue.size_; counter++)
		queue.queue_[counter] = q2.queue_[counter - q1.size_];
	return queue;
}