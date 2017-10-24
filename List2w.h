#pragma once

//#include "stdafx.h"
//#include <iostream>

using namespace std;

template< typename T >
struct element2
{
	T data;
	element2<T> *next, *prev ;
};

template< typename T >
struct List2W
{	
	element2<T> *head, *tail;
	int size;
};

template< typename T >
List2W<T> CreateEmptyList2W()
{
	List2W<T> temp;
	temp.head = NULL;	
	temp.tail = NULL;
	temp.size = 0;
	return temp;
}

template< typename T >
bool isEmpty(List2W<T> list)
{
	return (list.head == NULL);
}

template< typename T >
void PrintList(List2W<T> list)
{
	element2<T>* temp = list.head;
	if (temp == NULL)
	{
		cout << "List is empty";
	}
	else
	{
		while (temp != NULL)
		{
			cout << "  " << temp->data;
			temp = temp->next;
		}
	}
	cout << "\n\n";
}

template< typename T >
void AddFirst(List2W<T> &list, T k)
{
	element2<T>* temp = new element2<T>;
	temp->data = k;
	temp->next = list.head;
	temp->prev = NULL;
	if(list.head == NULL)
		list.tail = temp;
	else
		list.head->prev = temp;
	list.head = temp;
	list.size++;
}

template< typename T >
void AddLast(List2W<T> &list, T k)
{
	element2<T>* temp = new element2<T>;
	temp->data = k;
	temp->prev = list.tail;
	temp->next = NULL;
	if(list.head == NULL)
		list.head = temp;
	else
		list.tail->next = temp;
	list.tail = temp;
	list.size++;
}

template< typename T >
void DeleteFirst(List2W<T> &list)
{
	element2<T>* temp = list.head;
	list.head = list.head->next;
	if(list.head!=NULL)
		list.head->prev = NULL;
	else
		list.tail = NULL;
	delete temp;
	list.size--;
}


template< typename T >
T GetFirst(List2W<T> list)
{
	return list.head->data;
}

