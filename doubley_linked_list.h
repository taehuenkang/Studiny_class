#pragma once
#ifndef __doubly_linked_list_h__
#define __dounly_linked_list_h__

//#define USE_NUMBER
//#define USE_STRING //������ ����� ��� �ּ�ó��
#define USE_STRUCT

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef USE_NUMBER
typedef int element;
#endif

#ifdef USE_STRING
typedef char element[80];
#endif

#ifdef USE_STRUCT
typedef struct {
	char   bookname[80];   //å�̸�
	int      id;            //å ���� ��ȣ
	int      is_borrowed;   //�뿩����(0:����,1:�뿩)
} element;
#endif

typedef struct DListNode {
	element data;
	struct DListNode* llink; //���� ��� ��ũ
	struct DListNode* rlink;  //������ ��ũ
}DListNode;

void init(DListNode* phead);
void print_dlist(DListNode* phead);
void dinsert(DListNode* before, element data);
void ddelete(DListNode* head, DListNode* removed);
DListNode* dsearch_id(DListNode* head, int id);
DListNode* dsearch_name(DListNode* head, char* name);
void borrow_book(DListNode* head, int id);
void return_book(DListNode* head, int id);
void display_books(DListNode* head);

#endif