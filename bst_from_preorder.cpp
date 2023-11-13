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
  Node *Insert(Node* p, int key); // Updated function signature
    Node* InPre(Node* p);
    Node* InSucc(Node* p);
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

