// -*- GB18030 -*-
// 2020��12��14������һ����11��36��

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE		100
#define INTMAX		10000

// judge wether visited
int visid[MAXSIZE] = { 0 };

// define graph
typedef struct {
	char	vexs[MAXSIZE];
	int	edges[MAXSIZE][MAXSIZE];
	int	n, e;
} graph;

// define min edge �ߵĺ�ѡ��
struct {
	int	end;
	int	len;
}
minedge[MAXSIZE+1];

void creategraph(graph *ga)
// creat graph
{
	int i, j, k, w;

	printf("����ͼ�Ķ������ͱ�����\n");
	scanf("%d%d", &(ga->n), &(ga->e));
	// printf("%d,%d\n", ga->n, ga->e);
	printf("�����붥����Ϣ�������ţ�������������Ϣ��\n");

	for (i = 0; i < ga->n; i++)
	{
		scanf("\n%c", &(ga->vexs[i]));
	}


	// for (i = 0; i < ga->n; i++)
	// {
	// 	printf("%c ", (ga->vexs[i]));
	// }
	// printf("\n");


	for (i = 0; i < ga->n; i++)
	{
		for (j = 0; j < ga->n; j++)
		{
			ga->edges[i][j] = INTMAX;
		}
	}
	for (i = 0; i < ga->n; i++)
	{
		ga->edges[i][i] = 0;
	}


	for (k = 0; k < ga->e; k++)
	{
		printf("�������%d���ߵĶ������i,j��Ȩֵw:", k+1);

		scanf("%d,%d,%d", &i, &j, &w);

		ga->edges[i][j] = w;
		ga->edges[j][i] = w;
	}
}


void printgraph(graph *ga)
// print graph
{
	int i = 0, j = 0;

	for (i = 0; i < ga->n; i++)
	{
		for (j = 0; j < ga->n; j++)
		{
			if (ga->edges[i][j] == INTMAX) {
				printf("INF\t");
			}else{
				printf("%d\t", ga->edges[i][j]);
			}
		}
		printf("\n");
	}
}


void DFSM(graph *g, int i)
// DFS
{
	int j;

	printf("������ȱ����ڵ�:%c\n", g->vexs[i]);
	visid[i] = 1;
	for (j = 0; j < g->n; j++)
	{
		if ((g->edges[i][j] != 0) && !visid[j] && (g->edges[i][j] != INTMAX)) {
			DFSM(g, j);
		}
	}
}


void DFS(graph *g)
// DFS
{
	int i;

	// set visid[0...n] = 0
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


void prim(graph *g, int u)
// prim
{
	int v, k, j, min;

	// �����ѡ�߼�
	for (v = 0; v < g->n; v++)
	{
		if (v != u) {
			minedge[v].end = u;
			minedge[v].len = g->edges[v][u];
		}
	}

	minedge[u].len = 0;

	for (k = 1; k < g->n; k++) //
	{
		min = INTMAX;
		v = k;
		for (j = 0; j < g->n; j++)
		{
			if ((minedge[j].len > 0) && (minedge[j].len < min)) {
				min = minedge[j].len;
				v = j;
			}
		}

		if (min == INTMAX) {
			printf("ERROR!\n");
			return;
		}

		printf("��С�������ıߣ� %d %d\n", v, minedge[v].end);
		minedge[v].len = -minedge[v].len;
		for (j = 0; j < g->n; j++)
		{
			if (g->edges[j][v] < minedge[j].len) {
				minedge[j].len = g->edges[j][v];
				minedge[j].end = v;
			}
		}
	}
}


int main()
{
	graph g;

	creategraph(&g);
	printgraph(&g);
	DFS(&g);
	prim(&g, 0);


	return (0);
}
