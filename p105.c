#include <stdio.h>
#include <stdlib.h>
#define MaxSize    10000
typedef int DataType;
typedef struct {
	int		i, j;
	DataType	v;
} TriTupleNode;
typedef struct {
	TriTupleNode	data[MaxSize];
	int		m, n;
	int		t;
} TriTupleTable;

void FastTransMatrix(TriTupleTable *a, TriTupleTable *b)
{
	int pa, pb, col;
	int *cpos;
	int *cnum;

	b->m = a->n;
	b->n = a->m;
	b->t = a->t;

	if (a->t <= 0) {
		printf("A has no element, exit!\n");
		return;
	}

	cpos = malloc(sizeof(int)*(a->n));
	cnum = malloc(sizeof(int)*(a->n));

	for (col = 0; col < a->n; col++)
	{
		cnum[col] = 0;
	}
	for (pa = 0; pa < a->t; pa++)
	{
		col = a->data[pa].j;
		cnum[col]++;
	}
	for (col = 0; col < a->n; col++)
	{
		cpos[col] = 0;
	}
	for (col = 1; col < a->n; col++)
	{
		cpos[col] = cpos[col-1] + cnum[col-1];
	}

	for (pa = 0; pa < a->t; pa++)
	{
		col = a->data[pa].j;
		pb = cpos[col];
		b->data[pb].i = a->data[pa].j;
		b->data[pb].j = a->data[pa].i;
		b->data[pb].v = a->data[pa].v;
		cpos[col]++;
	}

	free(cpos);
	free(cnum);
}


int main()
{
	TriTupleTable *a, *b;
	TriTupleNode node[MaxSize];
	int num;

	a = malloc(sizeof(TriTupleTable));
	b = malloc(sizeof(TriTupleTable));

	node[0].i = 0, node[0].j = 1, node[0].v = 5;
	node[1].i = 0, node[1].j = 4, node[1].v = 8;
	node[2].i = 1, node[2].j = 0, node[2].v = 1;
	node[3].i = 1, node[3].j = 2, node[3].v = 3;
	node[4].i = 2, node[4].j = 1, node[4].v = -2;
	node[5].i = 3, node[5].j = 0, node[5].v = 6;

	for (num = 0; num <= 5; num++)
	{
		a->data[num].i = node[num].i;
		a->data[num].j = node[num].j;
		a->data[num].v = node[num].v;
	}

	a->m = 4, a->n = 5, a->t = 6;

	FastTransMatrix(a, b);

	for (num = 0; num < b->t; num++)
	{
		printf("%d,%d,%d\n", b->data[num].i, b->data[num].j, b->data[num].v);
	}

	return (0);
}
