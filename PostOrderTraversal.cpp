#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node * left;
	node * right;
	node (int data1)
	{
		data = data1;
		left = right = NULL;
	}
};


void postorder(node * temp){
	if(temp == NULL)return;
	else{
		
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<" ";
	}
}


int main(){
	node * root = new node(38);
	
	root -> left = new node(45);
	root -> left -> left = new node(87);
	root -> left -> left -> left = new node(56);
	root -> left -> left -> right = new node(22);
	
	root -> right = new node(76);
	root -> right -> left = new node(92);
	root -> right -> left -> right = new node(35);
	
	
	postorder(root);
	cout<<endl;

	
	return 0;
}