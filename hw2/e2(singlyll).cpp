#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        Node *head;
        Node *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            Node* node = new Node(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
        
        Node* delete_node(int p) {
			Node* n = head;
			if(p == 0) {
    			return head->next;
			}	
			for (int i = 1; i < p && n->next->next != nullptr; ++i) {
    			n = n->next;
			}

			n->next = n->next->next;
			return head;
		}
		
		void printLinkedList() {
			Node* t = head;
			while (t != nullptr) {
			cout << t->data << " ";
    		t = t->next;
		}
}
};

void free_singly_linked_list(Node* node) {
    while (node) {
        Node* temp = node;
        node = node->next;

        free(temp);
    }
}

Node* insertNodeAtPosition(Node* head, int x, int p) {
    Node* n = new Node(x);
	if (p == 0) {
		n->next = head;
		return n;
	}
    Node* cur = head;
    for (int i = 1; i < p && cur != nullptr; ++i) {
        cur = cur -> next;
    }
    if (cur == nullptr) {
        Node* t = head;
        while (t->next != nullptr) {
            t = t->next;
        }
        t->next = n;
        return head;
    }
    n->next = cur->next;
    cur->next = n;
    return head;
}

Node* deleteNode(Node* head, int p) {
	Node* n = head;
	if(p == 0) {
    	return head->next;
	}
	for (int i = 1; i < p && n->next->next != nullptr; ++i) {
    	n = n->next;
	}

	n->next = n->next->next;
	return head;
}





int main(){
	SinglyLinkedList myList;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string ip;
		int p, x;
		cin >> ip;
		if (ip == "insert") {
			cin >> p >> x;
			myList.head = insertNodeAtPosition(myList.head, x, p);
		}
		if (ip == "delete") {
			cin >> p;
			myList.head = deleteNode(myList.head, p);
		}
	}
	myList.printLinkedList();
	return 0;
}

