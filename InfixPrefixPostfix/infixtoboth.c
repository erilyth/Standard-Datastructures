#include<stdio.h>
#include<stdlib.h>

int main()
{
	char stack[1000];
	char fin[10000];
	int final=0;
	char A[1000];
	int head=-1;
	int a,b,c,i,j,k,n,m,count=0;
	while((c=getchar())!='\n')
	{
		A[count]=c;
		count++;
	}
	//printf("%s", A);
	for(i=0;i<count;i++)
	{
		if(A[i]=='(')
		{
			head++;
			stack[head]='(';		
		}
		else if(A[i]==')')
		{
			while(head!=-1 && stack[head]!='(')
			{
				fin[final]=stack[head];
				final++;
				head--;
			}
			if(head!=-1)
				head--;
		}
		else if(A[i]=='*' || A[i]=='/')
		{
			while(head!=-1 && stack[head]!='(' && (stack[head]=='*' || stack[head]=='/'))
			{
				fin[final]=stack[head];
				final++;
				head--;
			}
			head++;
			stack[head]=A[i];
		}
		else if(A[i]=='+' || A[i]=='-')
		{
			while(head!=-1 && stack[head]!='(')
			{
				fin[final]=stack[head];
				final++;
				head--;
			}
			head++;
			stack[head]=A[i];
		}
		else
		{
			fin[final]=A[i];
			final++;
		}
	}
	while(head!=-1)
	{
		fin[final]=stack[head];
		final++;
		head--;
	}
	for(i=0;i<final;i++)
		printf("%c", fin[i]);
	printf("\n");	
	final=0;
	for(i=count-1;i>=0;i--)
	{
		if(A[i]==')')
		{
			head++;
			stack[head]=')';		
		}
		else if(A[i]=='(')
		{
			while(head!=-1 && stack[head]!=')')
			{
				fin[final]=stack[head];
				final++;
				head--;
			}
			if(head!=-1)
				head--;
		}
		else if(A[i]=='*' || A[i]=='/')
		{
			while(head!=-1 && stack[head]!=')' && (stack[head]=='*' || stack[head]=='/'))
			{
				fin[final]=stack[head];
				final++;
				head--;
			}
			head++;
			stack[head]=A[i];
		}
		else if(A[i]=='+' || A[i]=='-')
		{
			while(head!=-1 && stack[head]!=')')
			{
				fin[final]=stack[head];
				final++;
				head--;
			}
			head++;
			stack[head]=A[i];
		}
		else
		{
			fin[final]=A[i];
			final++;
		}
	}
	while(head!=-1)
	{
		fin[final]=stack[head];
		final++;
		head--;
	}
	for(i=final-1;i>=0;i--)
		printf("%c", fin[i]);
	printf("\n");
	return 0;
}
