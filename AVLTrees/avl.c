//Include Header files 
#include <stdio.h>
#include <stdlib.h>

//Struct to represtt a node of 
//+ the AVL tree
struct Node {
	int val;
	int height;
	int balance;
	
	struct Node* left;
	struct Node* right;
};

//Function that returns the 
//+ maximum of two values
int maxx(int a, int b) {
	if(b > a)
		return b;
	return a;
}

//Returns the maximum height of the AVL Tree
int maxim(struct Node* a, struct Node* b) {
	if(b!=NULL && a==NULL)
		return b->height;
	if(b==NULL && a!=NULL)
		return a->height;
	if(b==NULL && a==NULL)
		return -1;
	if(b!=NULL && a!=NULL)
		return maxx(a->height,b->height);
}

//FUnction to get difference of the height
int getbalance(struct Node* a, struct Node* b) {
	if(a!=NULL && b!=NULL)
		return a->height+1-(b->height+1);
	if(a!=NULL)
		return a->height+1;
	if(b!=NULL)
		return 0-(b->height+1);
	if(a==NULL && b==NULL)
		return 0;
}

//Left rotate function in the AVL Tree
struct Node* leftrotate(struct Node* z) {
	
	struct Node* temp=z->left;
	struct Node* temp2=z->right->left;
	struct Node* tempfin=z->right;
	
	tempfin->left=z;
	
	z->right=temp2;
	z->left=temp;
	
	tempfin->left->height=maxim(tempfin->left->left,tempfin->left->right)+1;
	tempfin->height=maxim(tempfin->left,tempfin->right)+1;	
	tempfin->left->balance=getbalance(tempfin->left->left,tempfin->left->right);
	tempfin->balance=getbalance(tempfin->left,tempfin->right);
	
	return tempfin;
}

//Right rotate function in the AVL Tree
struct Node* rightrotate(struct Node* z) {
	
	struct Node* temp=z->right;
	struct Node* temp2=z->left->right;
	struct Node* tempfin=z->left;
	
	tempfin->right=z;
	
	z->left=temp2;
	z->right=temp;
	
	tempfin->right->height=maxim(tempfin->right->left,tempfin->right->right)+1;
	tempfin->height=maxim(tempfin->right,tempfin->left)+1;
	tempfin->right->balance=getbalance(tempfin->right->left,tempfin->right->right);
	tempfin->balance=getbalance(tempfin->left,tempfin->right);
	
	return tempfin;
}

struct  Node* insert(int val, struct Node* temp) {
	
	if(temp==NULL) {
		
		struct Node* new=malloc(sizeof(struct Node));
		
		new->val=val;
		new->left=NULL;
		new->right=NULL;
		
		new->height=0;
		new->balance=0;
		//printf("%d ", val);
		return new;
	}
	else if(temp->val>=val)
		temp->left=insert(val,temp->left);
	else
		temp->right=insert(val,temp->right);
	temp->height=maxim(temp->left,temp->right)+1;
	temp->balance=getbalance(temp->left,temp->right);
	
	if(temp->balance==-2 && (temp->right->balance==-1||temp->right->balance==0)) {
		temp=leftrotate(temp);
	}
	else if(temp->balance==-2 && temp->right->balance==1) {
		temp->right=rightrotate(temp->right);
		temp=leftrotate(temp);
	}
	else if(temp->balance==2 && (temp->left->balance==1||temp->left->balance==0)) {
		temp=rightrotate(temp);
	}
	else if(temp->balance==2 && temp->left->balance==-1) {
		temp->left=leftrotate(temp->left);
		temp=rightrotate(temp);
	}

	return temp;
	}

//dfs Function
void dfs(struct Node* temp) {
	
	if(temp->left!=NULL)
		dfs(temp->left);
	
	if(temp->right!=NULL)
		dfs(temp->right);
	
	printf("%d ", temp->val);
}

void check(int val, struct Node* temp) {
	
	if(temp==NULL) {
		printf("NO\n");
		return;
	}
	
	if(val==temp->val) {
		printf("YES\n");
		return;
	}
	else if(val<temp->val)
		check(val,temp->left);
	else
		check(val,temp->right);
}

//Main function
int main() {
	//Variable declaration
	struct Node* mytree=NULL;
	int i,n,a,k;
	scanf("%d", &k);
	
	//Menu driven choice to insert/check
	//+ the elements in the AVL Tree
	while(k!=0) {
		scanf("%d", &n);
		
		if(n==1) {
			scanf("%d",&a);
			mytree=insert(a,mytree);
		}
		
		if(n==2) {
			scanf("%d",&a);
			check(a,mytree);
		}
		k--;
	
	}

	printf("\n");
	return 0;

}
