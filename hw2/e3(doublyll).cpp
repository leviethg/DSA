#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        Node *head;
        Node *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            Node* node = new Node(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
}

void free_doubly_linked_list(Node* node) {
    while (node) {
        Node* temp = node;
        node = node->next;

        free(temp);
    }
}

int count_triplets(Node* head) {
	int count = 0;
	Node* t = head->next;
	while(t->prev && t && t->next) {
		if (t->prev->data + t->data + t->next->data == 0) {
			count++;
		}
		t = t->next;
	}
	return count;
}

int main() {
	DoublyLinkedList myList;
	int n; cin >> n;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		myList.insert_node(x);
	}
	cout << count_triplets(myList.head);
	return 0;
}
