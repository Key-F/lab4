//! \mainpage Программа, реализующая различные обходы деревьев \file <main.cpp>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct tree
{
	int x; //!< значение
	tree *left;
	tree *right;
};
struct tree *stree(
  struct tree *root,
  struct tree *r,
  int x) //!<создание упорядоченного двоичного дерева
{
  if(!r) {
    r = (struct tree *) malloc(sizeof(struct tree));
    r->left = NULL;
    r->right = NULL;
    r->x = x;
    if(!root) return r; 
    if(x < root->x) root->left = r;
    else root->right = r;
    return r;
  }
  if(x < r->x)
    stree(r, r->left, x);
  else
    stree(r, r->right, x);
  return root;
}

void simp(tree* m) //!<симметричный порядок
{
    if (m) {
       simp(m->left);
       cout << m->x;
       simp(m->right);
    }
}

void prp(tree* m) //!<прямой порядок
{
    if (m) {
	   cout << m->x;
       prp(m->left);
       prp(m->right);
    }
}

void obrp(tree* m) //!<обратный порядок
{
    if (m) {
       prp(m->left);
       prp(m->right);
	   cout << m->x;
    }
}

//! Функция main() − точка входа в программу.
void main()
{
	int n;
    int x;
	struct tree *root;
	root = NULL;
	cin >> n;
	for (int i=0; i<n; i++)
	{
      cin >> x;
	  root = stree(root, root, x);
	}
	obrp(root);
	cout<<"\n";
	prp(root);
	cout<<"\n";
	simp(root);
	getch();
};