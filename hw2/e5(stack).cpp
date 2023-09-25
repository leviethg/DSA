#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
	Node* getTop() {
		return top;
	}
	// Them 1 phan tu vao ngan xep
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Loai bo phan tu o dinh ngan xep
    void pop() {
        
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

    }

};

void printStack(Node* top) {
	Node* t = top;
	if (t) {
		printStack(t->next);
		cout << t->data << " ";
		t = t->next;	
	}
}

int main() {
    Stack myStack;
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
    	string ip; int x;
    	cin >> ip;
    	if (ip == "push") {
    		cin >> x;
    		myStack.push(x);
		}
		if (ip == "pop") {
			myStack.pop();
		}
	}
	
	printStack(myStack.getTop());
	
    return 0;
}

