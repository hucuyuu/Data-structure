#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct LNode {
	ElemType	data;
	struct LNode *	next;
} LNode, *LinkList;

int ListInsert_L(LinkList head, int i, ElemType e)
{
	LinkList p = head;
	LinkList s;
	int j;

	for (j = 1; j < i; j++)
	{
		if (p) {
			p = p->next;
		}else{
			break;
		}
	}
	if (!p || (i < 1)) {
		printf("error!!please enter correct i!!\n");
		return (0);
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return (1);
}


LinkList CreateList_L(LinkList head)
{
	ElemType temp;
	LinkList p;

	printf("please enter node data(enter 0 to interrupt):");
	fflush(stdin);
	scanf("%c", &temp);
	while (temp != '0')
	{
		if ((('A' <= temp) && (temp <= 'Z')) || (('a' <= temp) && (temp <= 'z'))) {
			p = (LinkList)malloc(sizeof(LNode));
			p->data = temp;
			p->next = head->next;
			head->next = p;
		}
		printf("please enter node data(enter 0 to interrupt):");
		fflush(stdin);
		scanf("%c", &temp);
	}

	return (head);
}


int ListDel_L(LinkList head, int i)
{
	LinkList p, tmp;
	int j;

	p = head->next;
	tmp = head;
	for (j = 1; j < i; j++)
	{
		if (p) {
			p = p->next;
			tmp = tmp->next;
		}else{
			break;
		}
	}

	if (!p || (i < 1)) {
		printf("error!!please enter correct i!!\n");
		return (0);
	}

	tmp->next = p->next;
	free(p);
	return (1);
}


void ListPint_L(LinkList head)
{
	LinkList p;
	int i = 0;

	p = head->next;
	while (p != NULL)
	{
		i++;
		printf("the %dth element is:", i);
		printf("%c\n", p->data);
		p = p->next;
	}
}


// void ListPint_L2(LinkList head)
// {
// 	LinkList p;
// 	int i = 0;
//
// 	p = head->next;
// 	printf("head");
// 	while (p != NULL)
// 	{
// 		i++;
// 		printf("->%c", p->data);
// 		p = p->next;
// 	}
// 	printf("\n");
// }


int ListOrder_L(LinkList head)
// test data:
// abbffcde
// abbbaffffcdebcccdbbbaa
{
	LinkList cmp, cmpp, mov;

	// ListPint_L2(head);
	cmp = head->next->next;
	cmpp = head->next;

	do
	{
		// ListPint_L2(head);
		// printf("cmp:%c\n", cmp->data);
		// printf("cmpp:%c\n", cmpp->data);
		// 小于第一个
		if (cmp->data <= head->next->data) {
			cmpp->next = cmp->next;
			cmp->next = head->next;
			head->next = cmp;
			cmp = cmpp->next;
			continue;
		}
		//  大于1-小于cmpp
		mov = head->next;
		while (mov != cmpp)
		{
			if ((cmp->data > mov->data) && (cmp->data <= mov->next->data)) {
				cmpp->next = cmp->next;
				cmp->next = mov->next;
				mov->next = cmp;
				cmp = cmpp->next;
				break;
			}
			mov = mov->next;
		}
		// 大于cmpp
		// 不管
		if (mov == cmpp) {
			cmp = cmp->next;
			cmpp = cmpp->next;
		}
	} while (cmp != NULL);

	// ListPint_L2(head);
	// printf("cmp:%c\n", cmp->data);
	// printf("cmpp:%c\n", cmpp->data);

	return (0);
}


int main()
{
	int i;
	char cmd, e;
	LinkList head;

	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	CreateList_L(head);
	// ListPint_L2(head);
	do
	{
		printf("i,I...Insert\n");
		printf("d,D...Delete\n");
		printf("q,Q...Quit\n");
		printf("o,O...Order\n");
		do
		{
			fflush(stdin);
			scanf("%c", &cmd);
		} while (cmd != 'i' && cmd != 'I' && cmd != 'd' && cmd != 'D' && cmd != 'q' && cmd != 'Q' && cmd != 'o' && cmd != 'O');
		switch (cmd)
		{
		case 'i':
		case 'I':
			printf("enter data:");
			fflush(stdin);
			scanf("%c", &e);
			printf("enter data position:");
			scanf("%d", &i);
			ListInsert_L(head, i, e);
			ListPint_L(head);
			break;

		case 'd':
		case 'D':
			printf("enter data position to delete:");
			fflush(stdin);
			scanf("%d", &i);
			ListDel_L(head, i);
			ListPint_L(head);
			break;

		case 'o':
		case 'O':
			printf("sorted data:\n");
			ListOrder_L(head);
			ListPint_L(head);
			break;
		}
	} while (cmd != 'q' && cmd != 'Q');
}
