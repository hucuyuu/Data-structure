#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE    100

int visid[MAXSIZE] = { 0 };

typedef struct {
	int	vexs[MAXSIZE];
	int	edges[MAXSIZE][MAXSIZE];
	int	n, e;
} graph;


void creategraph(graph *ga)
// graph
{
	int i, j, k, w;

	printf(" ����ͼ�Ķ������ͱ�����\n");
	scanf("%d%d", &(ga->n), &(ga->e));
	// printf("%d,%d\n", ga->n, ga->e);
	printf("�����붥����Ϣ�������ţ�������������Ϣ��\n");

	for (i = 0; i < ga->n; i++)
	{
		scanf("\n%c", &(ga->vexs[i]));
	}

	/*
	 * for(i = 0; i < ga->n; i++)
	 * {
	 *      printf("%c ",  (ga->vexs[i]));
	 * }
	 * printf("\n");
	 */

	for (i = 0; i < ga->n; i++)
	{
		for (j = 0; j < ga->n; j++)
		{
			ga->edges[i][j] = 0;
		}
	}


	for (k = 0; k < ga->e; k++)
	{
		printf("�������%d���ߵĶ������i,j��Ȩֵw:", k+1);

		scanf("%d,%d,%d", &i, &j, &w);

		ga->edges[i][j] = w;
		ga->edges[j][i] = w;
	}
	for (i = 0; i < ga->n; i++)
	{
		for (j = 0; j < ga->n; j++)
		{
			printf("%d ", ga->edges[i][j]);
		}
		printf("\n");
	}
}


void DFSM(graph *g, int i)
{
	int j;

	printf("������ȱ����ڵ�:%c\n", g->vexs[i]);
	visid[i] = 1;
	for (j = 0; j < g->n; j++)
	{
		if ((g->edges[i][j] == 1) && !visid[j]) {
			DFSM(g, j);
		}
	}
}


void DFS(graph *g)
{
	int i;

	for (i = 0; i < g->n; i++)
	{
		visid[i] = 0;
	}

	for (i = 0; i < g->n; i++)
	{
		if (!visid[i]) {
			DFSM(g, i);
		}
	}
}


int main(int argc, char const *argv[])
{
	graph g;

	creategraph(&g);
	DFS(&g);


	return (0);
}
