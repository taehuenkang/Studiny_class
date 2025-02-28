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
        printf("메모리 할당 실패\n");
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
        printf("책 ID %d를 찾을 수 없습니다.\n", id);
    else if (node->data.is_borrowed)
        printf("책 '%s' (ID %d) 는 이미 대출 중입니다.\n", node->data.bookname, node->data.id);
    else {
        node->data.is_borrowed = 1;
        printf("책 '%s' (ID %d) 를 대출했습니다.\n", node->data.bookname, node->data.id);
    }
}

void return_book(DListNode* head, int id) {
    DListNode* node = dsearch_id(head, id);
    if (node == NULL)
        printf("책 ID %d를 찾을 수 없습니다.\n", id);
    else if (!node->data.is_borrowed)
        printf("책 '%s' (ID %d) 는 이미 반납된 상태입니다.\n", node->data.bookname, node->data.id);
    else {
        node->data.is_borrowed = 0;
        printf("책 '%s' (ID %d) 를 반납했습니다.\n", node->data.bookname, node->data.id);
    }
}

void display_books(DListNode* head) {
    DListNode* p = head->rlink;
    if (p == head) {
        printf("등록된 책이 없습니다!\n");
        return;
    }
    printf("\n도서 목록\n");
    while (p != head) {
        printf("ID: %d, 제목: %s, 상태: %s\n", p->data.id, p->data.bookname,
            p->data.is_borrowed ? "대출 중" : "보유 중");
        p = p->rlink;
    }
}
