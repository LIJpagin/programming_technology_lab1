#include "Queue.h"

Queue::Queue(int value, ...) {
	if (value < 1)
		throw new std::exception("Error: The first parameter when calling this constructor must be positive!");
	head_ = tail_ = nullptr;
	va_list vl;
	va_start(vl, value);
	for (auto i = 0; i < value; i++)
		push(va_arg(vl, int));
	va_end(vl);
}

bool Queue::isEmpty() const {
	return !((bool)head_);
}

int Queue::size() const {
	if (isEmpty()) return 0;
	Item* temp = head_;
	int size = 0;
	while (temp != nullptr)
		size++, temp = temp->next;
	return size;
}

int Queue::pop() {
	if (isEmpty()) throw new std::exception("Error: The list is empty!");
	Item* temp = head_;
	int data = temp->data;
	head_ = temp->next;
	delete temp;
	return data;
}

void Queue::push(int value) {
	try {
		Item* temp = new Item;
		temp->data = value, temp->next = nullptr;
		if (!head_) head_ = tail_ = temp;
		else tail_->next = temp, tail_ = temp;
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

Item* Queue::front() const {
	if (isEmpty()) throw new std::exception("Error: The list is empty!");
	return head_;
}

Item* Queue::back() const {
	if (isEmpty()) throw new std::exception("Error: The list is empty!");
	return tail_;
}

Queue Queue::copy() {
	Queue queue;
	if (isEmpty()) return queue;
	Item* temp = head_;
	do queue.push(temp->data), temp = temp->next;
	while (temp != NULL);
	return queue;
}

Queue Queue::merge(Queue that) {
	Queue result = this->copy();
	while (!that.isEmpty())
		result.push(that.pop());
	return result;
}

int* Queue::getArray() const {
	int* array = nullptr;
	if (isEmpty()) return array;
	try {
		array = new int[size()];
		Item* temp = head_;
		auto counter = 0;
		while (temp != nullptr)
			array[counter++] = temp->data, temp = temp->next;
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return array;
}

void Queue::random(int size, int min, int max) {
	if (size < 1)
		throw new std::exception("Error: The size parameter when calling the random() method must be positive!");
	clear();
	srand(time(NULL));
	size = rand() % (size) + 1;
	for (auto i = 0; i < size; i++)
		push(rand() % (max - min + 1) + min);
}

std::ostream& operator<< (std::ostream& out, const Queue& queue) {
	int* array = queue.getArray();
	if (!array) {
		out << "The queue is empty";
		return out;
	}
	int size = queue.size();
	for (auto i = 0; i < size; i++)
		out << array[i] << " ";
	return out;
}

Queue::Queue(const Queue& that) {
	this->head_ = this->tail_ = nullptr;
	if (that.isEmpty()) return;
	Item* temp = that.head_;
	while (temp != nullptr) {
		this->push(temp->data);
		temp = temp->next;
	}
}

Queue& Queue::operator= (const Queue& that) {
	if (this == &that) return *this;
	this->clear();
	if (that.isEmpty()) {
		this->head_ = this->tail_ = nullptr;
		return *this;
	}
	Item* temp = that.head_;
	while (temp != nullptr)
		this->push(temp->data), temp = temp->next;
	return *this;
}

Queue operator+ (const Queue& q1, const Queue& q2) {
	Queue queue;
	Item* temp = q1.head_;
	while (temp != nullptr)
		queue.push(temp->data), temp = temp->next;
	temp = q2.head_;
	while (temp != nullptr)
		queue.push(temp->data), temp = temp->next;
	return queue;
}

bool operator== (const Queue& q1, const Queue& q2) {
	if (q1.size() != q2.size()) return false;
	Item* temp1 = q1.head_, * temp2 = q2.head_;
	while (temp1 != nullptr || temp2 != nullptr) {
		if (temp1->data != temp2->data) return false;
		temp1 = temp1->next, temp2 = temp2->next;
	}
	return true;
}

void Queue::clear() {
	while (head_ != tail_) {
		Item* temp = head_;
		head_ = temp->next;
		delete temp;
	}
	if (head_ != nullptr) {
		Item* temp = head_;
		delete temp;
		head_ = tail_ = nullptr;
	}
}