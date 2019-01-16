#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAT 20
#define size 2
struct snake
{
	char data;
	struct snake *next;
	int a;
	int b;
};
struct snake *create(char val)
{
	struct snake *ptr=(struct snake*)malloc(sizeof(struct snake));
	ptr->data=val;
	ptr->next=NULL;
	ptr->a=0;
	ptr->b=0;
	return ptr;
}

struct snake *insert(struct snake *head,char val)
{
	struct snake *temp,*t;
	temp=create(val);
	if(head==NULL)
	head=temp;
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=temp;
	}
	return head;
}
void empty(char arr[][MAT])
{
	int i,j;
	for(i=0; i<MAT; i++)
	{
		for(j=0; j<MAT; j++)
		{
			arr[i][j]=' ';
		}
	}
}
void border(char arr[][MAT])
{
	int i;
	for(i=0;i<MAT;i++)
	arr[0][i]='*';
	for(i=0; i<MAT; i++)
	arr[i][MAT-1]='*';
	for(i=MAT-1; i>=0; i--)
	arr[MAT-1][i]='*';
	for(i=MAT-1; i>=0; i--)
	arr[i][0]='*';
}
void display(char arr[][MAT])
{
	int i,j;
	for(i=0; i<MAT; i++)
	{
		for(j=0; j<MAT; j++)
		printf("%c",arr[i][j]);
		printf("\n");
	}
}
void inmat(char arr[][MAT],struct snake *head)
{
	int i=2,j=3;
	struct snake *t=head;
	while(t!=NULL)
	{
		t->a=i;
		t->b=j;
		arr[t->a][t->b]=t->data;
		j++;
		t=t->next;
	}
	
}
int main() 
{
	//snake
	struct snake *head=NULL;
	int i;
	for(i=0; i<size; i++)
	{
		if(head==NULL)
		head=insert(head,'H');
		else if(i==size-1)
		head=insert(head,'T');
		else
		head=insert(head,'#');
	}
	/*struct snake *t=head;
	while(t!=NULL)
	{
	printf("%c",t->data);
	t=t->next;
    } */
	
	//matrix
	char arr[MAT][MAT];
	empty(arr);
	border(arr);
	//snake in matrix
	inmat(arr,head);
	
	display(arr);
}
