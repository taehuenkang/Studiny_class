#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubley_linked_list.h"
#define _CRT_SECURE_NO_WARNINGS

#define USE_STRUCT

typedef DListNode Book;

// ������ �Է� �Լ� (���� �Է� ����)
int safe_input() {
    int num;
    while (1) {
        if (scanf_s("%d", &num) == 1) {
            while (getchar() != '\n');
            return num;
        }
        else {
            printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���: ");
            while (getchar() != '\n'); // �Է� ���� ����
        }
    }
}

int main(void) {
    Book* head = (Book*)malloc(sizeof(Book)); // �޸� �Ҵ�
    if (!head) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }
    init(head);

    int choice, id;
    char bookname[80];
    while (1) {
        printf("\n���� ���� �ý���\n");
        printf("1. ���� �߰�\n");
        printf("2. ���� �ݳ�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ��� ����\n");
        printf("5. ����\n");
        printf("�޴��� �����ϼ���: ");

        choice = safe_input();

        switch (choice) {
        case 1:
            printf("å ID �Է�: ");
            id = safe_input();
            printf("å ���� �Է�: ");
            fgets(bookname, sizeof(bookname), stdin);
            bookname[strcspn(bookname, "\n")] = 0;

            element data;
            strcpy_s(data.bookname, sizeof(data.bookname), bookname);

            data.id = id;
            data.is_borrowed = 0;
            dinsert(head, data);
            break;

        case 2:
            printf("�ݳ��� å ID �Է�: ");
            id = safe_input();
            return_book(head, id);
            break;

        case 3:
            printf("������ å ID �Է�: ");
            id = safe_input();
            borrow_book(head, id);
            break;

        case 4:
            display_books(head);
            break;

        case 5:
            printf("���α׷��� �����մϴ�.\n");
            free(head);
            return 0;

        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
            break;
        }
    }
    return 0;
}