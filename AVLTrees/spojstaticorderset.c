#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int counters=0;

struct Node{
	int val;
	int height;
	int balance;
	int lchild;
	int rchild;
	struct Node* left;
	struct Node* right;
};

int maxx(int a, int b)
{
	if(b>a)
		return b;
	return a;
}

int getlchild(struct Node* temp)
{
	if(temp->left==NULL)
		return 0;
	else
		return temp->left->lchild+temp->left->rchild+1;
}

int getrchild(struct Node* temp)
{
	if(temp->right==NULL)
		return 0;
	else
		return temp->right->lchild+temp->right->rchild+1;
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
	tempfin->left->lchild=getlchild(tempfin->left);
	tempfin->left->rchild=getrchild(tempfin->left);
	tempfin->lchild=getlchild(tempfin);
	tempfin->rchild=getrchild(tempfin);
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
	tempfin->right->lchild=getlchild(tempfin->right);
	tempfin->right->rchild=getrchild(tempfin->right);
	tempfin->lchild=getlchild(tempfin);
	tempfin->rchild=getrchild(tempfin);
	return tempfin;
}

struct Node* delete(struct Node* temp, int x)
{
    if(temp->val==x && temp->left==NULL && temp->right==NULL)
    {
	counters--;
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
	temp->lchild=getlchild(temp);
	temp->rchild=getrchild(temp);
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
	return temp;
    }
}
    
struct  Node* insert(int val, struct Node* temp)
{
	if(temp==NULL)
	{
		struct Node* new=malloc(sizeof(struct Node));
		new->val=val;
		new->left=NULL;
		new->right=NULL;
		new->height=0;
		new->balance=0;
		new->lchild=0;
		new->rchild=0;
		counters++;
		//printf("%d ", val);
		return new;
	}
	else if(temp->val>=val)
		temp->left=insert(val,temp->left);
	else
		temp->right=insert(val,temp->right);
	temp->height=maxim(temp->left,temp->right)+1;
	temp->balance=getbalance(temp->left,temp->right);
	temp->lchild=getlchild(temp);
	temp->rchild=getrchild(temp);
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

int state=0;

void checker(struct Node* temp, int a)
{
	if(temp==NULL)
	{
		state=0;
		return;
	}
	if(temp->val<a)
		checker(temp->right,a);
	else if(temp->val>a)
		checker(temp->left,a);
	else
		state=1;
}

void dfs(struct Node* temp)
{
	if(temp->left!=NULL)
		dfs(temp->left);
	if(temp->right!=NULL)
		dfs(temp->right);
	printf("%d %d %d\n", temp->val, temp->lchild, temp->rchild);
}

int count=0;

void check(int val, struct Node* temp)
{
	if(temp==NULL)
		return;
	if(temp->val<=val)
	{
		count+=temp->lchild+1;
		check(val,temp->right);
	}
	else
	{
		check(val,temp->left);
	}
}

void getxthmin(struct Node* temp, int x) //If you want xthmax then we go to right instead of left if we want a greater value.
	{
	if(temp->lchild==x-1) //This node itself is the xth minimum
	{
		printf("%d\n", temp->val);
		return;
	}
	if(temp->lchild>=x) //The xth minimum lies in the left side
		getxthmin(temp->left,x);
	else //The xth minimum lies on the right side and now the left children along with this node have been counted for minimums so we reduce the minimum count.
		getxthmin(temp->right,x-(temp->lchild+1)); 
}

int main()
{
	struct Node* mytree=NULL;
	int i,n,a;
	int c,d;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		char arr[100];
		scanf("%s", arr);
		c=arr[0];
		scanf("%d", &a);
		if(c=='I')
		{
			state=0;
			d=getchar();
			checker(mytree,a);
			if(state==0)
				mytree=insert(a,mytree);
		}
		if(c=='D')
		{
			state=0;
			checker(mytree,a);
			if(state==1)
				mytree=delete(mytree,a);
		}
		if(c=='C')
		{
			count=0;
			check(a,mytree);
			state=0;
			checker(mytree,a);
			if(state==1)
				printf("%d\n", count-1);
			else
				printf("%d\n", count);
		}
		if(c=='K')
		{
			if(a>counters || a==0)
				printf("invalid\n");
			else
				getxthmin(mytree,a);
		}
	}
	return 0;
}

