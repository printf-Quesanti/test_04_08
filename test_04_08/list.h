#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int Listtype;

typedef struct List
{
	Listtype date;
	List* next;
	List* prev;
}LT;

List* Listinit(List* phead)
{
	phead = (List*)malloc(sizeof(List));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void Listprintf(List* phead)
{
	assert(phead);
	List* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
}

List* buyList(Listtype x)
{
	List* newnode = (List*)malloc(sizeof(List));
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void Listinsert( List* pos, Listtype x)//Ç°²å
{
	assert(pos);
	List* newnode = buyList(x);
	List* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void Listerase(List* pos)
{
	assert(pos);
	List* prev = pos->prev;
	List* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

void Listpushback(List* phead, Listtype x)
{
	/*assert(phead);
	List* newnode= buyList(x);
	List* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;*/
	Listinsert( phead,x);
}

void Listpopback(List* phead)
{
	assert(phead);
	assert(phead->next != phead);
	List* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
}

void Listpushfront(List* phead, Listtype x)
{
	/*assert(phead);
	List* newnode = buyList(x);
	List* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	next->prev = newnode;
	newnode->next = next;*/
	Listinsert( phead->next, x);
}

void Listpopfront(List* phead)
{
	assert(phead);
	assert(phead->next != phead);
	List* next = phead->next;
	phead->next = next->next;
	next->next->prev = phead;
	free(next);
}

List* Listfind(List* phead,Listtype x)
{
	assert(phead);
	List* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void Listdestroy(List* phead)
{
	assert(phead);
	List* cur = phead->next;
	while (cur != phead)
	{
		List* next = cur->next;
		free(cur);
		cur = next;
	}
	phead = NULL;
}

List* Listinit(List* phead);
void Listpushback(List* phead, Listtype x);
void Listpushfront(List* phead, Listtype x);
void Listpopback(List* phead);
void Listpopfront(List* phead);
void Listprintf(List* phead);
void Listinsert(List* pos, Listtype x);
List* Listfind(List* phead,Listtype x);
void Listerase(List* pos);
void Listdestroy(List* phead);
