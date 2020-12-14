#include <stdio.h>
#include <stdlib.h>
#define nmax    100
typedef  int		datatype;
typedef struct node *	pointer;

struct node {
	int		vertex;
	struct node *	next;
}
nnode;

typedef struct {
	datatype	data;
	pointer		first;
} headtype;

typedef struct {
	headtype	adlist[nmax];
	int		n, e;
} lkgraph;
int visid[nmax] = { 0 };

void creategraph(lkgraph *ga)
{
	int i, j, e, k;
	pointer p;

	printf("Input node sum:");
	scanf("%d\n", &(ga->n));
	for (i = 1; i <= ga->n; i++)
	{
		scanf("\n%d", &(ga->adlist[i].data));//
		ga->adlist[i].first = NULL;
	}

	e = 0;
	scanf("\n%d,%d\n", &i, &j);
	i--;
	while (i > 0)//
	{
		e++;
		p = (pointer)malloc(sizeof(struct node));
		p->vertex = j;
		p->next = ga->adlist[i].first;
		ga->adlist[i].first = p;
		p = (pointer)malloc(sizeof(struct node));
		p->vertex = i;
		p->next = ga->adlist[j].first;
		ga->adlist[j].first = p;
		scanf("\n%d,%d\n", &i, &j);
		// i--;//
	}

	ga->e = e;
}


void DFSL(lkgraph *g, int n)
{
	pointer p;

	printf("%d\n", g->adlist[n].data);
	visid[n] = 1;
	for (p = g->adlist[n].first; p != NULL; p = p->next)
	{
		if (!visid[p->vertex]) {
			DFSL(g, p->vertex);
		}
	}
}


int main(int argc, char const *argv[])
{
	lkgraph g;

	creategraph(&g);
	DFSL(&g, 3);
	return (0);
}
