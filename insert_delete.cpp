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
    Node* Delete(Node* p, int key);
    int Height(Node* p);
  Node *Insert(Node* p, int key); 
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
    
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

Node* BST::Delete(Node* p, int key) {
    Node* q;

    if (p == NULL) {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root) {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int BST::Height(Node* p) {
    int x;
    int y;
    if (p == NULL) {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node* BST::InPre(Node* p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

Node* BST::InSucc(Node* p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

 


int main() {
    BST bs;

    // Recursive Insert
  bs.root =  bs.Insert(bs.getRoot(), 5);
    bs.Insert(bs.getRoot(), 2);
    bs.Insert(bs.getRoot(), 8);
    bs.Insert(bs.getRoot(), 7);
    bs.Insert(bs.getRoot(), 9);
    bs.Insert(bs.getRoot(), 1);

    bs.Inorder(bs.getRoot());
    cout << endl;

    // Delete
    bs.Delete(bs.getRoot(), 5);
    bs.Inorder(bs.getRoot());
    cout << endl;

    

    return 0;
}

