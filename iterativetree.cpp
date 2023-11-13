//iterative traversal
#include<iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
	public:
		node* lchild;
		node* rchild;
		int data;
};
 class Stack{
 	private :
 	int size;
 	int top;
 	node **S;
 	public:
 		void Stackcreate(int size){
 			this->size = size;
 			top = -1;
 		    S = new node*[size];
		 }
		 void push(node* x){
		 	if(top==size-1){
		 		cout<<"overflow"<<endl;
			 }else{
			 	top++;
			 	S[top] = x;
			 }
		 }
		 node* pop(){
		 	node* x = NULL;
		 	if(top==-1){
		 		cout<<"Empty"<<endl;
			 }else{
			 	x = S[top--];
			 }
			 return x;
		 }
		 int isEmptyStack(){
		 	if(top==-1){
		 		return 1;
			 }else{
			 	return 0;
			 }
		 }
		 int isFullStack(){
		 	if(top==size-1){
		 		return 1;
			 }else{
			 	return 0;
			 }
		 }
 };
class Queue{
	private:
		int front;
		int rear;
		int size;
		 node **Q;
	public:
		Queue(){
			front = -1;
			rear = -1;
			size = 10;
			Q = new node*[size];
		}
		Queue(int size){
			front = -1;
			rear = -1;
			this->size = size;
			Q = new node*[this->size];
		}	
	
		bool isEmpty(){
			if(front==rear){
				return true;
			}else{
				return false;
			}
		}
		bool isFull(){
			if(rear==size-1){
				return true;
			}else{
				return false;
			}
		}
		void enqueue(node* x){
			if(rear==size-1){
				cout<<"Overflow"<<endl;
			}else{
				rear++;
				Q[rear] = x;
			}
		}
		node* dequeue(){
			node* x = NULL;
			if(front==rear){
				cout<<"Empty"<<endl;
			}else{
				x = Q[front+1];
				front++;
			}
			return x;
		}
};
class tree{
	public:
	node* root;
	tree(){
		root = NULL;
	}
	void create(){
		node* p,*t;
		int x;
		Queue q(100);
		cout<<"enter root value"<<endl;
		cin>>x;
		root = new node;
		root->data = x;
		root->lchild = NULL;
		root->rchild = NULL;
		q.enqueue(root);
		while(!q.isEmpty()){
			p = q.dequeue();
			cout<<"enter l child "<<endl;
			cin>>x;
			if(x!=-1){
				t = new node;
				t->data = x;
				t->lchild = NULL;
				t->rchild = NULL;
				p->lchild = t;
				q.enqueue(t);
			}
			cout<<"enter r child "<<endl;
			cin>>x;
			if(x!=-1){
				t = new node;
				t->data = x;
				t->lchild = NULL;
				t->rchild = NULL;
				p->rchild = t;
				q.enqueue(t);
			}
		}
	}
	void Ipreorder(node* p){
    Stack stk;
    stk.Stackcreate(100);

    while (p || !stk.isEmptyStack()) {
        if(p){
            cout<<p->data<<endl;
            stk.push(p);
            p=p->lchild;
        }
        else{
            p=stk.pop();
            p=p->rchild; // Move this line outside the else block
        }
    }
}
void Iinorder(node* p){
    Stack stk;
    stk.Stackcreate(100);

    while (p || !stk.isEmptyStack()) {
        if(p){
            stk.push(p);
            p=p->lchild;
        }
        else{
            p=stk.pop();
            cout<<p->data<<endl;
            p=p->rchild;
        }
    }
}

void Ipostorder(node* p){
    Stack stk1, stk2;
    stk1.Stackcreate(100);
    stk2.Stackcreate(100);

    stk1.push(p);

    while (!stk1.isEmptyStack()) {
        p = stk1.pop();
        stk2.push(p);

        if (p->lchild) {
            stk1.push(p->lchild);
        }

        if (p->rchild) {
            stk1.push(p->rchild);
        }
    }

    while (!stk2.isEmptyStack()) {
        p = stk2.pop();
        cout << p->data << endl;
    }
}
 void Ilevelorder(node *p){
 	Queue q;
 	cout<<root->data;
 	q.enqueue(p);
 	while(!q.isEmpty()){
 		p = q.dequeue();
 		if(p->lchild){
 			cout<<p->lchild->data;
 			q.enqueue(p->lchild);
		 }
	 if(p->rchild){
	 	cout<<p->rchild->data;
	 	q.enqueue(p->rchild);
	 }
	 }
 }

};
 int main(){
	tree t;
	t.create();
	
	cout<<"preorder : A B C"<<endl;
	t.Ipreorder(t.root);
	cout<<endl;
		cout<<"postorder : BCA"<<endl;
	t.Ipostorder(t.root);
	cout<<endl;
		cout<<"level : A B C"<<endl;
	t.Ilevelorder(t.root);
	cout<<endl;
		cout<<"inorder : BAC"<<endl;
	t.Iinorder(t.root);
	cout<<endl;
	return 0;
}
