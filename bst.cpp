 #include <iostream>
using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST{
public:
	Node* root;
    BST(){ 
	root = NULL; 
	}
    Node* getRoot(){ 
	return root; 
	}
    Node* Insert(Node* p, int key);
    void Inorder(Node* p);
    Node* Search(int key);
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
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
Node* BST::Search(int key) {
    Node* t = root;
    while (t != NULL){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return NULL;
}
 
 
int main() {
 
    BST bst;
 
    // Insert
    bst.root = bst.Insert(bst.root, 10);
    bst.Insert(bst.root, 5);
    bst.Insert(bst.root, 20);
    bst.Insert(bst.root, 8);
    bst.Insert(bst.root, 30);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;
 
    // Search
    Node* temp = bst.Search(8);
    if (temp != NULL){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    return 0;
}
