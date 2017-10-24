#pragma once

#include "MyStack.h"
#include "MyQueue.h"


using namespace std;

template< typename T >
struct MyTree
{
	T data;
	MyTree<T> *left, *right;
};

template< typename T >
MyTree<T>* CreateEmptyTree()
{
	return NULL;
}

template< typename T >
void Add(MyTree<T>* &root, T k)
{
	if (root == NULL)
	{
		root = new MyTree<T>;
		root->data = k;
		root->left = NULL;
		root->right = NULL;
	}
	else
	if (k >= root->data)
		Add(root->right, k);
	else
		Add(root->left, k);
}

template< typename T >
bool Find(MyTree<T> *root, T k)
{
	if (root == NULL)
		return false;
	else
	{
		if (k == root->data)
			return true;
		if (k > root->data)
			return Find(root->right, k);
		else
			return Find(root->left, k);
	}
}
template< typename T >
bool isEmpty(MyTree<T>* root)
{
	return (root == NULL);
}

template< typename T >
void PrintTreeStack(MyTree<T> *root)
{
	if (root == NULL)
		cout << "Tree is empty";
	else
	{
		MyStack<MyTree<T>*> st = CreateEmptyStack<MyTree<T>*>();
		MyTree<T>* t = root;
		do
		{
			cout << t->data << " ";
			if (t->right != NULL)
				Push(st, t->right);
			if (t->left != NULL)
				t = t->left;
			else
			if (!isEmpty(st))
				t = Pop(st);
			else
				t = NULL;
		} while (t != NULL);
	}	
	cout<<"\n\n";
}

template< typename T >
void PrintTreeQueue(MyTree<T> *root)
{
	if (root == NULL)
		cout << "Tree is empty";
	else
	{
		MyQueue<MyTree<T>*> Q = CreateEmptyQueue<MyTree<T>*>();
		MyTree<T>* t ;
		Push(Q, root);
		while(!isEmpty(Q))
		{
			t = Pop(Q);
			cout << t->data << " ";
			if (t->left != NULL)
				Push(Q, t->left);
			if (t->right != NULL)
				Push(Q, t->right);
		} 
	}
	cout<<"\n\n";
}


template< typename T >
void PrintTreeRec(MyTree<T> *root)
{
	if (root == NULL)
		cout << "Tree is empty";
	else
	{
		cout << root->data << " ";
		if (root->left != NULL)
			PrintTreeRec(root->left);
		if (root->right != NULL)
			PrintTreeRec(root->right);
	}
}
