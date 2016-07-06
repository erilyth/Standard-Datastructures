#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};

struct Queue{
	struct Node* value;
	struct Queue* next;
};

struct Queue* myqueue=NULL;

int state;

struct Node* mytree=NULL;

struct Node* delete(struct Node* temp, int x)
{
	if(temp->val==x && temp->left==NULL && temp->right==NULL)
		return NULL;
	else
	{
		if(temp->val==x && temp->left!=NULL)
		{
			struct Node* temp2=temp->left;
			while(temp2->right!=NULL)
				temp2=temp2->right;
			temp->val=temp2->val;
			temp->left=delete(temp->left,temp2->val);
		}
		else if(temp->val==x && temp->right!=NULL)
		{
			struct Node* temp2=temp->right;
			while(temp2->left!=NULL)
				temp2=temp2->left;
			temp->val=temp2->val;
			temp->right=delete(temp->right,temp2->val);
		}
		else if(temp->val>=x)
			temp->left=delete(temp->left,x);
		else if(temp->val<x)
			temp->right=delete(temp->right,x);
		return temp;
	}
}

void preorder(struct Node* temp)
{
	if(temp!=NULL)
	{
		printf("%d ", temp->val);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(struct Node* temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\n", temp->val);
	}
}

void inorder(struct Node* temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d ", temp->val);
		inorder(temp->right);
	}
}

void checktree(struct Node* temp, int min, int max)
{
	if(temp!=NULL)
	{
		if(temp->val>=min && temp->val<=max)
		{
			checktree(temp->left,min,temp->val);
			checktree(temp->right,temp->val+1,max);
		}
		else
			state=1;  
	}
}

int find(int x)
{
	struct Node* temp=mytree;
	while(temp!=NULL)
	{
		if(temp->val==x)
			return 1;
		if(temp->val<x)
			temp=temp->right;
		else
			temp=temp->left;
	}
	return 0;
}

void insert(int x)
{
	struct Node* temp=mytree;
	struct Node* temp2=malloc(sizeof(struct Node));
	temp2->left=NULL;
	temp2->right=NULL;
	temp2->val=x;
	if(mytree==NULL)
	{
		mytree=temp2;
	}
	else
	{
		while(1)
		{
			if(temp->val>=x && temp->left==NULL)
			{
				temp->left=temp2;
				break;
			}
			else if(temp->val<x && temp->right==NULL)
			{
				temp->right=temp2;
				break;
			}
			else if(temp->val>=x)
				temp=temp->left;
			else
				temp=temp->right;
		}
	}
	return;
}

int parse(int a[4][4])
{
	int i,j,sum=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=sum*10+a[i][j];
		}
	}
	return sum;
}

void funct(int x[4][4])
{
	int state=0,val;
	int b[4][4];
	int temp,i,j,ii,jj;	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			b[i][j]=x[i][j];
	state=0;
	printf("%d\n", parse(b));
	for(i=0;i<3 && find(123456789)==0;i++)
	{
		for(j=0;j<3;j++)
		{
			if(b[i][j]==9 && state==0)
			{
				if(i-1>=0)
				{
					for(ii=0;ii<4;ii++)
						for(jj=0;jj<4;jj++)
							b[ii][jj]=x[ii][jj];
					temp=b[i][j];
					b[i][j]=b[i-1][j];
					b[i-1][j]=temp;
					val=parse(b);
					if(find(val)==0)
					{
						insert(val);
						funct(b);
					}
				}
				if(i+1<3)
				{
					for(ii=0;ii<4;ii++)
						for(jj=0;jj<4;jj++)
							b[ii][jj]=x[ii][jj];
					temp=b[i][j];
					b[i][j]=b[i+1][j];
					b[i+1][j]=temp;
					val=parse(b);
					if(find(val)==0)
					{
						insert(val);
						funct(b);
					}
				}
				if(j+1<3)
				{
					for(ii=0;ii<4;ii++)
						for(jj=0;jj<4;jj++)
							b[ii][jj]=x[ii][jj];
					temp=b[i][j];
					b[i][j]=b[i][j+1];
					b[i][j+1]=temp;
					val=parse(b);
					if(find(val)==0)
					{
						insert(val);
						funct(b);
					}
				}
				if(j-1>=0)
				{
					for(ii=0;ii<4;ii++)
						for(jj=0;jj<4;jj++)
							b[ii][jj]=x[ii][jj];
					temp=b[i][j];
					b[i][j]=b[i][j-1];
					b[i][j-1]=temp;
					val=parse(b);
					if(find(val)==0)
					{
						insert(val);
						funct(b);
					}
				}
				state=1;
			}
		}
	}
}

int main()
{
	int start[4][4]={{5,2,3},{4,1,6},{7,8,9}};
	insert(523416789);
	funct(start);
	//postorder(mytree);
	return 0;
}
