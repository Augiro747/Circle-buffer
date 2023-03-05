#include <iostream>
#include <memory>

using namespace std;

//Структура для буфера
struct Node {
	int data;
	shared_ptr<Node> next;
};

//Реализация буфера. 
class Queue {
private:

	shared_ptr<Node> top;
	shared_ptr<Node> bot;
	unsigned int count = 0;

public:

	//Конструктор буфера
	Queue(unsigned int size) {

		shared_ptr<Node> current(new Node);
		shared_ptr<Node> begin(new Node);
		current->data = 0;
		current->next = current;
		begin = current;

		this->top = begin;
		for (int i = 1; i < size; i++) {
			shared_ptr<Node> tmp(new Node);
			bot = tmp;
			tmp->data = 0;
			tmp->next = begin;
			current->next = tmp;
			current = current->next;
		}
	}

	//Добавение элемента в буфер
	void enqueue(int value) {

		bot = bot->next;
		bot->data = value;
		count++;

	}

	//Удаление элемента из буфера	
	int dequeue() {
		if (count != 0) {
			int deleted;
			deleted = top->data;
			top->data = 0;
			top = top->next;
			count--;
			return deleted;
		}
		else {
			return -1;
		}
	}

	//Количество элементов в буфере
	unsigned int size() {
		return count;
	}

	//Флаг пустого буфера
	bool isEmpty() {
		if (count == 0) { return true; }
		else return false;
	}

	//Первый элемент в очереди
	int first() {
		return top->data;
	}

	//Очистка буфера
	void clear() {
		while (!this->isEmpty()) {
			this->dequeue();
		}
	}

	//Деструктор буфера
	~Queue() {
		cout << "Buffer deleted.";
	}

};