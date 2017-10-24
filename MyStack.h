#pragma once

#include "List1W.h"

using namespace std;

template< typename T >
struct MyStack
{
	List1W<T> list;
};

template< typename T >
MyStack<T> CreateEmptyStack()
{
	MyStack<T> st;
	st.list = CreateEmptyList<T>();
	return st;
}

template< typename T >
void Push(MyStack<T> &st, T k)
{
	AddFirst(st.list, k);
}

template< typename T >
T Pop(MyStack<T> &st)
{
	T temp = GetFirst(st.list);
	DeleteFirst(st.list);
	return temp;
}

template< typename T >
T Top(MyStack<T> st)
{
	return GetFirst(st.list);
}

template< typename T >
bool isEmpty(MyStack<T> st)
{
	return isEmpty(st.list);
}