#pragma once

#include "List2w.h"

using namespace std;

template< typename T >
struct MyQueue
{
	List2W<T> list;
};

template< typename T >
MyQueue<T> CreateEmptyQueue()
{
	MyQueue<T> st;
	st.list = CreateEmptyList2W<T>();
	return st;
}

template< typename T >
void Push(MyQueue<T> &st, T k)
{
	AddLast(st.list, k);
}

template< typename T >
T Pop(MyQueue<T> &st)
{
	T temp = GetFirst(st.list);
	DeleteFirst(st.list);
	return temp;
}

template< typename T >
bool isEmpty(MyQueue<T> st)
{
	return isEmpty(st.list);
}