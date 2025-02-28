#include "doubley_linked_list.h"

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d, %s| |->", p->data.id, p->data.bookname);
    }
    printf("\n");
}

void dinsert(DListNode* before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    if (newnode == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }
    newnode->data = data;

    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

DListNode* dsearch_id(DListNode* head, int id) {
    DListNode* p = head->rlink;
    while (p != head) {
        if (p->data.id == id) {
            return p;
        }
        p = p->rlink;
    }
    return NULL;
}

DListNode* dsearch_name(DListNode* head, const char* name) {
    DListNode* p = head->rlink;
    while (p != head) {
        if (strcmp(p->data.bookname, name) == 0) {
            return p;
        }
        p = p->rlink;
    }
    return NULL;
}

void borrow_book(DListNode* head, int id) {
    DListNode* node = dsearch_id(head, id);
    if (node == NULL)
        printf("å ID %d�� ã�� �� �����ϴ�.\n", id);
    else if (node->data.is_borrowed)
        printf("å '%s' (ID %d) �� �̹� ���� ���Դϴ�.\n", node->data.bookname, node->data.id);
    else {
        node->data.is_borrowed = 1;
        printf("å '%s' (ID %d) �� �����߽��ϴ�.\n", node->data.bookname, node->data.id);
    }
}

void return_book(DListNode* head, int id) {
    DListNode* node = dsearch_id(head, id);
    if (node == NULL)
        printf("å ID %d�� ã�� �� �����ϴ�.\n", id);
    else if (!node->data.is_borrowed)
        printf("å '%s' (ID %d) �� �̹� �ݳ��� �����Դϴ�.\n", node->data.bookname, node->data.id);
    else {
        node->data.is_borrowed = 0;
        printf("å '%s' (ID %d) �� �ݳ��߽��ϴ�.\n", node->data.bookname, node->data.id);
    }
}

void display_books(DListNode* head) {
    DListNode* p = head->rlink;
    if (p == head) {
        printf("��ϵ� å�� �����ϴ�!\n");
        return;
    }
    printf("\n���� ���\n");
    while (p != head) {
        printf("ID: %d, ����: %s, ����: %s\n", p->data.id, p->data.bookname,
            p->data.is_borrowed ? "���� ��" : "���� ��");
        p = p->rlink;
    }
}
