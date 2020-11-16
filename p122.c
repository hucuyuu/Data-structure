#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char		data;
	struct Node *	Lchild, *Rchild;
} BTnode, *Btree;

void Visit(char root)
{
	printf("%c ", root);
}


void Preorder(Btree root)
{
	if (root != NULL) {
		Visit(root->data);
		Preorder(root->Lchild);
		Preorder(root->Rchild);
	}
}


void Inorder(Btree root)
{
	if (root != NULL) {
		Inorder(root->Lchild);
		Visit(root->data);
		Inorder(root->Rchild);
	}
}


void Postorder(Btree root)
{
	if (root != NULL) {
		Postorder(root->Lchild);
		Postorder(root->Rchild);
		Visit(root->data);
	}
}


void CreateBtree(Btree *bt)
{
	char ch;

	ch = getchar();
	if (ch == '.') {
		*bt = NULL;
	}else{
		*bt = (Btree)malloc(sizeof(BTnode));
		(*bt)->data = ch;
		CreateBtree(&((*bt)->Lchild));
		CreateBtree(&((*bt)->Rchild));
	}
}


int main()
{
	Btree q = (Btree)malloc(sizeof(BTnode));
	Btree *t = &q;

	CreateBtree(t);
	Preorder(q);
	return (0);
}
