#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    Node* getFront() const {
        return front;
    }
    // Kiem tra hang doi co rong khong
    bool isEmpty() {
        return front == nullptr;
    }

    // Them 1 phan tu vao cuoi hang doi
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Loai bo phan tu o dau hang doi
    void dequeue() {
        int data = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
    }
};

void printQueue(Node* front) {
	Node* t = front;
	while(t) {
		cout << t->data << " ";
		t = t->next;
	}
	delete t;
}

int main() {
	Queue myQueue;
    int n; cin >> n;
    for (int i = 0;i < n; ++i) {
    	string ip;
    	int x;
    	cin >> ip;
    	if (ip == "enqueue") {
    		cin >> x;
    		myQueue.enqueue(x);
		}
		if (ip == "dequeue") {
			myQueue.dequeue();
		}
	}
	printQueue(myQueue.getFront());
    return 0;
}

