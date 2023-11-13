#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST {
public:
    Node* root;


    BST() {
        root = NULL;
    }

    Node* getRoot() {
        return root;
    }

    void Inorder(Node* p);
  Node *Insert(Node* p, int key); // Updated function signature
    void createFromPreorder(int pre[], int n);
};

Node* BST::Insert(Node* p, int key) {
	Node* t;
	if(p==NULL){
		t=new Node;
		t->data = key;
		t->lchild = NULL;
		t->rchild = NULL;
		return t;
	}
	if(key<p->data){
		p->lchild = Insert(p->lchild,key);
	}else if(key>p->data){
		p->rchild = Insert(p->rchild,key);
	}
	return p;
}
 
void BST::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}



void BST::createFromPreorder(int* pre, int n) {
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = NULL;
    root->rchild = NULL;

    Node* t;
    Node* p = root;
    stack<Node*> stk;

    while (i < n) {
        if (pre[i] < p->data) {
            t = new Node;
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        } else {
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data)) {
                t = new Node;
                t->data = pre[i++];
                t->lchild = NULL;
                t->rchild = NULL;
                p->rchild = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main() {

    // BST from Preorder traversal
    cout << "BST from Preorder: ";
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;

    return 0;
}
