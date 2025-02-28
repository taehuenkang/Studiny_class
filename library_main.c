#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubley_linked_list.h"
#define _CRT_SECURE_NO_WARNINGS

#define USE_STRUCT

typedef DListNode Book;

// 안전한 입력 함수 (숫자 입력 검증)
int safe_input() {
    int num;
    while (1) {
        if (scanf_s("%d", &num) == 1) {
            while (getchar() != '\n');
            return num;
        }
        else {
            printf("잘못된 입력입니다. 숫자를 입력하세요: ");
            while (getchar() != '\n'); // 입력 버퍼 비우기
        }
    }
}

int main(void) {
    Book* head = (Book*)malloc(sizeof(Book)); // 메모리 할당
    if (!head) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    init(head);

    int choice, id;
    char bookname[80];
    while (1) {
        printf("\n도서 대출 시스템\n");
        printf("1. 도서 추가\n");
        printf("2. 도서 반납\n");
        printf("3. 도서 대출\n");
        printf("4. 도서 목록 보기\n");
        printf("5. 종료\n");
        printf("메뉴를 선택하세요: ");

        choice = safe_input();

        switch (choice) {
        case 1:
            printf("책 ID 입력: ");
            id = safe_input();
            printf("책 제목 입력: ");
            fgets(bookname, sizeof(bookname), stdin);
            bookname[strcspn(bookname, "\n")] = 0;

            element data;
            strcpy_s(data.bookname, sizeof(data.bookname), bookname);

            data.id = id;
            data.is_borrowed = 0;
            dinsert(head, data);
            break;

        case 2:
            printf("반납할 책 ID 입력: ");
            id = safe_input();
            return_book(head, id);
            break;

        case 3:
            printf("대출할 책 ID 입력: ");
            id = safe_input();
            borrow_book(head, id);
            break;

        case 4:
            display_books(head);
            break;

        case 5:
            printf("프로그램을 종료합니다.\n");
            free(head);
            return 0;

        default:
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
            break;
        }
    }
    return 0;
}