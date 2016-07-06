#include<stdio.h>
#include<stdlib.h>

int numofelem=0;

struct Node{
	int val;
	int height;
	int balance;
	struct Node* left;
	struct Node* right;
};

int maxx(int a, int b)
{
	if(b>a)
		return b;
	return a;
}

int maxim(struct Node* a, struct Node* b)
{
	if(b!=NULL && a==NULL)
		return b->height;
	if(b==NULL && a!=NULL)
		return a->height;
	if(b==NULL && a==NULL)
		return -1;
	if(b!=NULL && a!=NULL)
		return maxx(a->height,b->height);
}

int getbalance(struct Node* a, struct Node* b)
{
	if(a!=NULL && b!=NULL)
		return a->height+1-(b->height+1);
	if(a!=NULL)
		return a->height+1;
	if(b!=NULL)
		return 0-(b->height+1);
	if(a==NULL && b==NULL)
		return 0;
}

struct Node* leftrotate(struct Node* z)
{
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

struct Node* rightrotate(struct Node* z)
{
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

struct Node* delete(struct Node* temp, int x)
{
    if(temp->val==x && temp->left==NULL && temp->right==NULL)
    {
	numofelem--;
        return NULL;
    }
    else if(temp->left==NULL && temp->right==NULL)
	    return temp;
    else
    {
        if(temp->val==x && temp->left!=NULL)
        {
            struct Node* temp2=temp->left;
            while(temp2->right!=NULL)
                temp2=temp2->right;
            temp->val=temp2->val;
            temp->left=delete(temp->left,temp2->val);
	    temp->height=maxim(temp->left,temp->right)+1;
	    temp->balance=getbalance(temp->left,temp->right);
	}
        else if(temp->val==x && temp->right!=NULL)
        {
            struct Node* temp2=temp->right;
            while(temp2->left!=NULL)
                temp2=temp2->left;
            temp->val=temp2->val;
            temp->right=delete(temp->right,temp2->val);
	    temp->height=maxim(temp->left,temp->right)+1;
	    temp->balance=getbalance(temp->left,temp->right);
        }
        else if(temp->val>=x)
            temp->left=delete(temp->left,x);
        else if(temp->val<x)
            temp->right=delete(temp->right,x);	
	temp->height=maxim(temp->left,temp->right)+1;
	temp->balance=getbalance(temp->left,temp->right);
	if(temp->balance==-2 && (temp->right->balance==-1||temp->right->balance==0))
	{
		temp=leftrotate(temp);
	}
	else if(temp->balance==-2 && temp->right->balance==1)
	{
		temp->right=rightrotate(temp->right);
		temp=leftrotate(temp);
	}
	else if(temp->balance==2 && (temp->left->balance==1||temp->left->balance==0))
	{
		temp=rightrotate(temp);
	}
	else if(temp->balance==2 && temp->left->balance==-1)
	{
		temp->left=leftrotate(temp->left);
		temp=rightrotate(temp);
	}
	return temp;
    }
}

struct Node* insert(int val, struct Node* temp)
{
	if(temp==NULL)
	{
		struct Node* new=malloc(sizeof(struct Node));
		new->val=val;
		new->left=NULL;
		new->right=NULL;
		new->height=0;
		new->balance=0;
		numofelem++;
		//printf("%d ", val);
		return new;
	}
	else if(temp->val>=val)
		temp->left=insert(val,temp->left);
	else
		temp->right=insert(val,temp->right);
	temp->height=maxim(temp->left,temp->right)+1;
	temp->balance=getbalance(temp->left,temp->right);
	if(temp->balance==-2 && (temp->right->balance==-1 || temp->right->balance==0))
	{
		temp=leftrotate(temp);
	}
	else if(temp->balance==-2 && temp->right->balance==1)
	{
		temp->right=rightrotate(temp->right);
		temp=leftrotate(temp);
	}
	else if(temp->balance==2 && (temp->left->balance==1 || temp->left->balance==0))
	{
		temp=rightrotate(temp);
	}
	else if(temp->balance==2 && temp->left->balance==-1)
	{
		temp->left=leftrotate(temp->left);
		temp=rightrotate(temp);
	}
	return temp;
}
void dfs(struct Node* temp)
{
	if(temp==NULL)
		return;
	if(temp->left!=NULL)
		dfs(temp->left);
	if(temp->right!=NULL)
		dfs(temp->right);
	printf("%d ", temp->val);
}

int main()
{
	struct Node* mytree=NULL;
	int i,n,a;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a);
		mytree=insert(a,mytree);
	}
	printf("Enter number of deletions:\n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a);
		if(numofelem>0)
			mytree=delete(mytree,a);
		else
			printf("No elements to delete");
		dfs(mytree);
		printf("\n");
	}
	return 0;
}
