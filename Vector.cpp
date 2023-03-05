#include <iostream>
#include <vector>

using namespace  std;

//���������� ������
class Queue {

private:

	unsigned int top;   //������� �������� ��������
	unsigned int bot;//������� ���������� ��������
	unsigned int size;  //����� ������
	unsigned int real_size; //���������� ��������� � ������

public:

	vector<int> buff;

	//����������� ������
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

	//���������� �������� � �����
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

	//�������� �������� �� ������
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

	//������ ������� � �������
	int first() {
		if (top == size) {
			this->top = 0;
		}
		return this->buff[top];
	}

	//����� ������
	int size_of() {
		return this->buff.size();
	}

	//���� ������� ������
	bool isEmpty() {
		if (this->real_size == 0) { return true; }
		else return false;
	}

	//������� ������
	void clear() {
		while (!this->isEmpty()) {
			this->dequeue();
		}
	}

	//���������� ������
	~Queue() {
		cout << "Buffer deleted.";
	}
