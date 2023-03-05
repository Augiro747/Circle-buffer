#include <iostream>
#include <vector>

using namespace  std;

//Реализация буфера
class Queue {

private:

	unsigned int top;   //Позиция верхнего элемента
	unsigned int bot;//Позиция последнего элемента
	unsigned int size;  //Длина буфера
	unsigned int real_size; //Количество элементов в буфере

public:

	vector<int> buff;

	//Конструктор буфера
	Queue(unsigned int value) {
		top = 0;
		bot = 0;
		size = 0;
		buff.reserve(value);
		for (int i = 0; i < value; i++) {
			buff.push_back(0);
			this->size++;
		}
	}

	//Добавление элемента в буфер
	void enqueue(int value) {
		if (real_size < size) {
			this->buff[bot] = value;
			bot += 1;
		}
		else {
			this->buff[bot % size] = value;
			bot += 1;
			top += 1;
		}
		if (real_size < size) {
			this->real_size++;
		}
	}

	//Удаление элемента из буфера
	int dequeue() {
		int deleted;
		if (top < size) {
			deleted = this->buff[top];
			this->buff[top] = 0;
			this->top++;
		}
		else {
			this->top = 0;
			deleted = this->buff[top];
			this->buff[top] = 0;
			this->top++;
		}
		if (real_size > 0) {
			this->real_size--;
		}
		return deleted;
	}

	//Первый элемент в очереди
	int first() {
		if (top == size) {
			this->top = 0;
		}
		return this->buff[top];
	}

	//Длина буфера
	int size_of() {
		return this->buff.size();
	}

	//Флаг пустого буфера
	bool isEmpty() {
		if (this->real_size == 0) { return true; }
		else return false;
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
