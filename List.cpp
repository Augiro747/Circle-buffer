#include <iostream>
#include <memory>

using namespace std;

//��������� ��� ������
struct Node {
	int data;
	shared_ptr<Node> next;
};

//���������� ������. 
class Queue {
private:

	shared_ptr<Node> top;
	shared_ptr<Node> bot;
	unsigned int count = 0;

public:

	//����������� ������
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

	//��������� �������� � �����
	void enqueue(int value) {

		bot = bot->next;
		bot->data = value;
		count++;

	}

	//�������� �������� �� ������	
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

	//���������� ��������� � ������
	unsigned int size() {
		return count;
	}

	//���� ������� ������
	bool isEmpty() {
		if (count == 0) { return true; }
		else return false;
	}

	//������ ������� � �������
	int first() {
		return top->data;
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

};