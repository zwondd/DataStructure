#include <stdio.h>
#include <stdlib.h>

#define offsetof(type, member) ((size_t)&((type*)0)->member)
#define container_of(ptr, type, member) ({ \
		const typeof(((type*)0)->member) *__mptr=(ptr); \
		(type*)((char*)__mptr - offsetof(type,member) );})

typedef struct _node
{
	struct _node *next;
	struct _node *prev;
}NODE;

typedef struct
{
	char name[20];
	NODE list1;
	NODE list2;
}SAWON;

void __insert_data(NODE *temp, NODE *prev, NODE *next)
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void insert_front(NODE *temp, NODE *head)
{
	__insert_data(temp, head, head->next);
}

void insert_back(NODE *temp, NODE *head)
{
	__insert_data(temp, head->prev, head);
}

void display(NODE *head)
{
	NODE *temp;
	SAWON *s;

	system("clear");
	printf("[head]");
	for(temp=head->prev; temp!=head; temp=temp->prev)
	{
		s=container_of(temp, SAWON, list1);
		printf("<->[%s]", s->name);
	}
	printf("<->[head]\n");
	getchar();
}


int main()
{
	NODE head = {&head,&head};
	int i;
	SAWON sawon[2] = {{"홍길동",}, {"임꺽정",}};
	display(&head);
	for(i=0; i<2; i++)
	{
		insert_back(&sawon[i].list1, &head);
		display(&head);
	}
	return 0;
}



