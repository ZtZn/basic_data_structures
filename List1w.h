#pragma once

//#include "stdafx.h"
//#include <iostream>

using namespace std;

template< typename T >
struct element
{
	T data;
	element<T>* next;
};

template< typename T >
struct List1W
{	
	element<T>* head;
	int size;
};

template< typename T >
List1W<T> CreateEmptyList()
{
	List1W<T> temp;
	temp.head = NULL;
	temp.size = 0;
	return temp;
}

template< typename T >
bool isEmpty(List1W<T> list)
{
	return (list.head == NULL);
}

template< typename T >
void PrintList(List1W<T> list)
{
	element<T>* temp = list.head;
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
void AddFirst(List1W<T> &list, T k)
{
	element<T>* temp = new element<T>;
	temp->data = k;
	temp->next = list.head;
	list.head = temp;
	list.size++;
}

template< typename T >
void AddLast(List1W<T> &list, T k)
{
	element<T>* temp = new element<T>;
	temp->data = k;
	temp->next = NULL;
	element<T>* temp2 = list.head;
	if (temp2 == NULL)
	{
		list.head = temp;
	}
	else
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
	}
	list.size++;
}

//например, в список из 3-х элементов можно вставить элементы на 1-ое, 2-ое, 3-е и 4-ое место
template< typename T >
void AddAt(List1W<T> &list, T k, int b)
{
	element<T>* temp = new element<T>;
	temp->data = k;
	temp->next = NULL;
	if ((b == 1))
	{
		temp->next = list.head;
		list.head = temp;
	}
	else
	{
		element<T>* temp2 = list.head;
		int count = 1;
		while (count < (b - 1))
		{
			temp2 = temp2->next;
			count++;
		}
		temp->next = temp2->next;
		temp2->next = temp;
	}
	list.size++;
}

template< typename T >
void DeleteFirst(List1W<T> &list)
{
	element<T>* temp = list.head;
	list.head = list.head->next;
	delete temp;
	list.size--;
}

template< typename T >
void DeleteLast(List1W<T> &list)
{
	element<T>* temp = list.head;
	if (temp->next == NULL)
	{
		list.head = NULL;
		delete temp;
	}
	else
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		delete temp->next;
		temp->next = NULL;
	}
	list.size--;
}

template< typename T >
void DeleteAt(List1W<T> &list, int b)
{
	if (b == 1)
		DeleteFirst<T>(list);
	else
	{
		element<T>* temp2 = list.head;
		int k = 1;
		while (k < (b - 1))
		{
			temp2 = temp2->next;
			k++;
		}
		element<T>* temp = temp2->next;
		temp2->next = temp->next;
		delete temp;
	}
	list.size--;
}

template< typename T >
T GetFirst(List1W<T> list)
{
	return list.head->data;
}

template< typename T >
T GetLast(List1W<T> list)
{
	element<T>* temp = list.head;
	while (temp->next != NULL)
		temp = temp->next;
	return temp->data;
}

template< typename T >
T GetAt(List1W<T> list, int b)
{
	element<T>* temp = list.head;
	int k = 1;
	while (k < b)
	{
		temp = temp->next;
		k++;
	}
	return temp->data;
}

template< typename T >
void MakeCycled(List1W<T> list)
{
	element<T>* temp = list.head;
	if (temp == NULL)
	{
		cout << "List is empty. Cannot be cycled... \n";
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = list.head;
	}
}

template< typename T >
bool isCycled(List1W<T> list)
{
	if (list.head == NULL)
		return false;
	else
	{
		element<T>* temp = list.head;
		while ((temp->next != NULL) && (temp->next != list.head))
			temp = temp->next;
		if (temp->next == NULL)
			return false;
		else
			return true;
	}
}