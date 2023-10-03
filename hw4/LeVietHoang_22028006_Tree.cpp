#include <iostream>
using namespace std;


// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* nextBranch;

public:
    Node() {
        this -> data = 0;
        this -> fatherNode = NULL;
        this -> firstChild = NULL;
        this -> nextBranch = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data) {
        this -> data = data;
        this -> fatherNode = NULL;
        this -> firstChild = NULL;
        this -> nextBranch = NULL;
    }

    Node* findNode(Node *temp, int const data){
        if (temp) {
            if (temp->data == data) {
                return temp;
            }
            Node *p = findNode(temp->firstChild, data);
            if (p) {
                return p;
            }
            p = findNode(temp->nextBranch, data);
            if (p) {
                return p;
            }
        }
        return NULL;
    }

    // Hàm đếm số node con
    int numOfChildren() {
        int count = 0;
        Node* tmp = firstChild;
        while (!tmp) {
            tmp = tmp->nextBranch;
            count++;
        }
        return count;
    }

    void preorder(Node* temp){
        if (temp) {
            cout << temp->data << " ";
            preorder(temp->firstChild);
            preorder(temp->nextBranch);
        }
    }

    void postorder(Node* temp){
        if (temp) {
            preorder(temp->firstChild);
            preorder(temp->nextBranch);
            cout << temp->data << " ";
        }
    }

    bool isBinaryTree(Node *temp){
        if (temp) {
            if (temp->firstChild && temp->firstChild->nextBranch && temp->firstChild->nextBranch->nextBranch) {
                return false;
            }
            return (!isBinaryTree(temp->firstChild) || !isBinaryTree(temp->nextBranch) ? false : true);
        }
        return true;
    }

    bool isBinarySearchTree(Node*temp){
        if (temp) {
            if (temp->firstChild && temp->firstChild->nextBranch) {
                if (temp->firstChild->data > temp->data || temp->firstChild->nextBranch->data < temp->data) {
                        return false;
                    }
            }
            return (!isBinarySearchTree(temp->firstChild) || !isBinarySearchTree(temp->nextBranch) ? false : true);
        }
        return true;
    }

    bool isMaxHeapTree(Node *temp) {
        if (temp) {
            if (temp->firstChild) {
                if (temp->firstChild->data > temp->data) {
                        return false;
                    }
                if (temp->firstChild->nextBranch && temp->firstChild->nextBranch->data > temp->data) {
                        return false;
                    }
            }
            return (!isMaxHeapTree(temp->firstChild) || !isMaxHeapTree(temp->nextBranch) ? false : true);
        }

        return true;
    }

    void findMax(Node*temp, int& max){
        if (temp) {
            if (temp->data > max) {
                max = temp->data;
            }
            findMax(temp->firstChild, max);
            findMax(temp->nextBranch, max);
        }
    }

    int numOfLeaves(Node* temp) {
        if (temp) {
            if (!temp->firstChild) {
                return 1 + numOfLeaves(temp->nextBranch);
            }else {
                return numOfLeaves(temp->firstChild) + numOfLeaves(temp->nextBranch);
            }
        }
        return 0;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        // ...
        root = new Node();
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(int data) {
        root = new Node(data);
    }

    void printData()
    {
        //
    }

    Node *find(int data) {
        return root->findNode(root, data);
    }
    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data)
    {
        Node *l = root->findNode(root, father);
        if (l == NULL) {
            return false;
        }

        Node *temp = new Node(data);
        temp->fatherNode = l;
        if (l->firstChild == NULL || l->firstChild->data > temp->data) {
                temp->nextBranch = l->firstChild;
                l ->firstChild = temp;
            return true;
        }

        if (l->firstChild->nextBranch == NULL || l->firstChild->nextBranch->data > temp->data) {
                temp->nextBranch = l->firstChild->nextBranch;
                l->firstChild->nextBranch = temp;
            return true;
        }
        l = l->firstChild->nextBranch;
        while(l->nextBranch != NULL && l->nextBranch->data > temp->data) {
                l = l->nextBranch;
        }
        temp->nextBranch = l->nextBranch;
        l->nextBranch = temp;
        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data);

    // Hàm in ra các Node theo thứ tự preorder
    void preorder()
    {
        root->preorder(root);
        cout << endl;
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder()
    {
        root->postorder(root);
        cout << endl;
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree()
    {
        return root->isBinaryTree(root);
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree()
    {
        if (!root->isBinaryTree(root)) {
            return false;
        }
        return root->isBinarySearchTree(root);
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree()
    {
        if (!root->isBinaryTree(root)) {
            return false;
        }
        return root->isMaxHeapTree(root);
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node* node) {
        //if (isBinaryTree()) {
            if (!node) return;
            inorder(node->firstChild);
            cout << node->data << ' ';
            if (node->firstChild) inorder(node->firstChild->nextBranch);
        //}
    } 

    // Hàm trả về độ cao của cây
    int height() {
        if (!root) return -1;
        int d, h = 0;
        Node* tmp = root;
        while (tmp) {
            while (tmp->firstChild) {
                tmp = tmp->firstChild;
            }
            d = depth(tmp);
            if (d > h) h = d;
            if (tmp->nextBranch) {
                tmp = tmp->nextBranch;
            }
            if (!(tmp->firstChild)) {
                while (!(tmp->nextBranch) && tmp != root) {
                    tmp = tmp->fatherNode;
                }
                tmp = tmp->nextBranch;
            }
        }
        return h;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node* node = find(data);
        if (!node) return -1;
        return depth(node);
    }

    int depth(Node* node) {
        int d = 0;
        while (node->fatherNode) {
            node = node->fatherNode;
            d++;
        }
        return d;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves()
    {
        if (root) {
            return root->numOfLeaves(root);
        }
        return 0;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax()
    {
        int max = root->data;
        root->findMax(root, max);
        return max;
    }

    int findMaxChild() {
        Node* tmp = root;
        int mx = 0;
        while (tmp) {
            if (tmp->numOfChildren() > mx) mx = tmp->numOfChildren();
            while (tmp->firstChild) {
                tmp = tmp->firstChild;
                if (tmp->numOfChildren() > mx) mx = tmp->numOfChildren();
            }
            if (tmp->nextBranch) {
                tmp = tmp->nextBranch;
                if (tmp->numOfChildren() > mx) mx = tmp->numOfChildren();
            }
            if (!(tmp->firstChild)) {
                while (!(tmp->nextBranch) && tmp != root) {
                    tmp = tmp->fatherNode;
                }
                tmp = tmp->nextBranch;
            }
        }
        return mx;
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây
    Tree *tree_1 = new Tree(3);
    tree_1->insert(3, 1);
    tree_1->insert(3, 4);
    tree_1->insert(3, 8);
    tree_1->insert(1, 12);
    tree_1->insert(1, 11);
    tree_1->insert(1, 7);
    tree_1->insert(4, 6);
    tree_1->insert(4, 5);
    tree_1->insert(8, 9);
    tree_1->insert(9, 13);
    tree_1->insert(9, 10);
    tree_1->preorder();
    tree_1->postorder();
    cout << boolalpha << tree_1->isBinaryTree() << "\n";
    cout << boolalpha << tree_1->isBinarySearchTree() << "\n";
    cout << boolalpha << tree_1->isMaxHeapTree() << "\n";
    cout << tree_1->findMax() << "\n";
    cout << tree_1->numOfLeaves() << "\n";
    cout << "\n";
    // Tạo ra một cây thoả mãn tính chất là Binary Tree và test lại
    Tree *tree_2 = new Tree(3);
    tree_2->insert(3, 1);
    tree_2->insert(3, 8);
    tree_2->insert(1, 12);
    tree_2->insert(1, 11);
    tree_2->insert(8, 9);
    tree_2->insert(9, 13);
    tree_2->insert(9, 10);
    tree_2->preorder();
    tree_2->postorder();
    cout << boolalpha << tree_2->isBinaryTree() << "\n";
    cout << boolalpha << tree_2->isBinarySearchTree() << "\n";
    cout << boolalpha << tree_2->isMaxHeapTree() << "\n";
    cout << tree_2->findMax() << "\n";
    cout << tree_2->numOfLeaves() << "\n";
    cout << "\n";
    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lạ
    Tree *tree_3 = new Tree(10);
    tree_3->insert(10, 1);
    tree_3->insert(10, 15);
    tree_3->insert(1, 2);
    tree_3->insert(2, 3);
    tree_3->insert(15, 11);
    tree_3->insert(15, 16);
    tree_3->insert(11, 13);
    tree_3->insert(16, 17);
    tree_3->preorder();
    tree_3->postorder();
    cout << boolalpha << tree_3->isBinaryTree() << "\n";
    cout << boolalpha << tree_3->isBinarySearchTree() << "\n";
    cout << boolalpha << tree_3->isMaxHeapTree() << "\n";
    cout << tree_3->findMax() << "\n";
    cout << tree_3->numOfLeaves() << "\n";
    cout << "\n";
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    Tree *tree_4 = new Tree(10);
    tree_4->insert(10, 9);
    tree_4->insert(10, 8);
    tree_4->insert(9, 7);
    tree_4->insert(9, 6);
    tree_4->insert(8, 5);
    tree_4->insert(5, 4);
    tree_4->preorder();
    tree_4->postorder();
    cout << boolalpha << tree_4->isBinaryTree() << "\n";
    cout << boolalpha << tree_4->isBinarySearchTree() << "\n";
    cout << boolalpha << tree_4->isMaxHeapTree() << "\n";
    cout << tree_4->findMax() << "\n";
    cout << tree_4->numOfLeaves() << "\n";
    cout << "\n\n";

    return 0;
}
////