//
// Created by ROG on 7/16/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// B1: Xay dung cac cau truc du lieu can thiet
typedef struct Course {
    int id;
    char title[20];
    int credit;
} Course;

typedef struct SingleNode {
    Course course;
    struct SingleNode *next;
} SingleNode;

typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

SingleNode *finishNode = NULL;

// B2.1: Ham ho tro xoa bo dem nhap lieu
void clearInputBuffer() {
    // B1: Doc va loai bo tat ca ky tu con lai trong bo dem
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// B3: Xu ly yeu cau so 1
// B3.1: Xay dung ham khoi tao node trong DSLK don
SingleNode *createSingleNode(Course course) {
    SingleNode *node = (SingleNode *)malloc(sizeof(SingleNode));
    node->course = course;
    node->next = NULL;
    return node;
}

// B3.2: Xay dung ham them node vao cuoi DSLK don voi kiem tra ID khong trung
SingleNode *insertSingleNodeAtEnd(SingleNode *head, Course course) {
    // B1: Kiem tra ID trung
    SingleNode *temp = head;
    while (temp != NULL) {
        if (temp->course.id == course.id) {
            printf("ID %d da ton tai, khong the them khoa hoc\n", course.id);
            return head;
        }
        temp = temp->next;
    }
    // B2: Khoi tao node can them
    SingleNode *newNode = createSingleNode(course);
    // B3: Xu ly truong hop danh sach trong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    // B4: Duyet den cuoi danh sach
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // B5: Cap nhat con tro cua node cuoi
    temp->next = newNode;
    return head;
}

// B4: Xu ly yeu cau so 2
void displaySingleList(SingleNode *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // B4.1: Duyet qua tung node
    SingleNode *temp = head;
    printf("Toan bo khoa hoc: \n");
    while (temp != NULL) {
        // B4.2: In cac thong tin cua khoa hoc trong node
        printf("\nCourse ID: %d\n", temp->course.id);
        printf("Title: %s\n", temp->course.title);
        printf("Credit: %d\n", temp->course.credit);
        temp = temp->next;
    }
}

// B5: Xu ly yeu cau so 3
SingleNode *deleteSingleNodeById(SingleNode *head, int id) {
    // B1: Kiem tra danh sach trong
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    // B2: Duyet den node co id hoac duyet het danh sach
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->course.id != id) {
        prev = temp;
        temp = temp->next;
    }
    // B3: Neu duyet het danh sach thi thong bao va ket thuc
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d\n", id);
        return head;
    }
    // B4: Neu tim thay node co id thi cap nhat con tro next cua node truoc do
    // Xu ly truong hop neu temp la node dau tien
    if (temp == head) {
        head = head->next;
        finishNode = temp;
        free(temp);
        return head;
    }
    prev->next = temp->next;
    // B5: Giai phong node can xoa
    finishNode = temp;
    free(temp);
    return head;
}

// B6: Xu ly yeu cau so 4
void updateCourseById(SingleNode *head, int id) {
    // B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // B2: Duyet den node co id hoac duyet het danh sach
    SingleNode *temp = head;
    while (temp != NULL && temp->course.id != id) {
        temp = temp->next;
    }
    // B3: Neu duyet het danh sach thi thong bao va ket thuc
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d\n", id);
        return;
    }
    // B4: Neu tim thay node co id thi in thong tin khoa hoc cu
    printf("Course ID: %d\n", temp->course.id);
    printf("Old title: %s\n", temp->course.title);
    printf("Old credit: %d\n", temp->course.credit);
    // B5: Yeu cau nhap thong tin moi cua khoa hoc
    printf("Nhap vao title moi: ");
    clearInputBuffer(); // Xoa bo dem truoc khi nhap chuoi
    fgets(temp->course.title, sizeof(temp->course.title), stdin);
    temp->course.title[strcspn(temp->course.title, "\n")] = '\0'; // Xoa ky tu newline
    printf("Nhap vao credit moi: ");
    scanf("%d", &temp->course.credit);
    clearInputBuffer(); // Xoa bo dem sau scanf
}

// B7: Xu ly yeu cau so 5
// B7.1: Xay dung ham khoi tao node trong DSLK doi
DoubleNode *createDoubleNode(Course course) {
    DoubleNode *node = (DoubleNode *)malloc(sizeof(DoubleNode));
    node->course = course;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// B7.2: Xay dung ham them vao cuoi DSLK doi
DoubleNode *insertDoubleNodeAtEnd(DoubleNode *head, Course course) {
    // B1: Khoi tao node moi
    DoubleNode *newNode = createDoubleNode(course);
    // B2: Xu ly truong hop danh sach trong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    // B3: Duyet den cuoi danh sach
    DoubleNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // B4: Cap nhat cac con tro can thiet de tien hanh them
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// B8: Xu ly yeu cau so 6
// B8.1: Xay dung ham sap xep DSLK don theo credit (tang dan)
SingleNode *sortSingleListByCredit(SingleNode *head) {
    // B1: Xu ly truong hop danh sach trong hoac chi co 1 node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // B2: Su dung thuat toan bubble sort de sap xep
    int swapped;
    SingleNode *current;
    SingleNode *last = NULL;
    do {
        swapped = 0;
        current = head;
        while (current->next != last) {
            if (current->course.credit > current->next->course.credit) {
                // B3: Hoan doi du lieu giua 2 node
                Course tempCourse = current->course;
                current->course = current->next->course;
                current->next->course = tempCourse;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    return head;
}

// B9: Xu ly yeu cau so 7
void searchCourseByTitle(SingleNode *head, char *findStr) {
    // B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    // B2: Duyet toan bo danh sach
    SingleNode *temp = head;
    int found = 0;
    while (temp != NULL) {
        // B3: Neu co course nao co title chua findStr thi in thong tin course do
        if (strstr(temp->course.title, findStr) != NULL) {
            printf("Course ID: %d\n", temp->course.id);
            printf("Title: %s\n", temp->course.title);
            printf("Credit: %d\n", temp->course.credit);
            found = 1;
        }
        temp = temp->next; // Di chuyen den node tiep theo
    }
    // B4: Neu khong tim thay khoa hoc nao
    if (!found) {
        printf("Khong tim thay khoa hoc co ten chua '%s'\n", findStr);
    }
}

int main(void) {
    // B2: Xay dung menu
    int choice;
    // Khoi tao 2 danh sach lien ket
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    do {
        printf("\n====== MENU ======\n");
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi toan bo khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Sua khoa hoc\n");
        printf("5. Danh dau khoa hoc hoan thanh\n");
        printf("6. Sap xep theo tin chi trong dslk don\n");
        printf("7. Tim kiem ten trong danh sach lien ket don\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Xoa bo dem sau khi nhap choice
        switch (choice) {
            case 1:
                // B1: Nhap so luong khoa hoc
                int n;
                printf("Nhap so luong khoa hoc can them: ");
                scanf("%d", &n);
                clearInputBuffer(); // Xoa bo dem sau scanf
                // B2: Nhap lan luot tung khoa hoc
                for (int i = 1; i <= n; i++) {
                    Course newCourse;
                    printf("\nNhap khoa hoc thu %d:\n", i);
                    printf("Nhap id: ");
                    scanf("%d", &newCourse.id);
                    clearInputBuffer(); // Xoa bo dem truoc khi nhap chuoi
                    printf("Nhap title: ");
                    fgets(newCourse.title, sizeof(newCourse.title), stdin);
                    newCourse.title[strcspn(newCourse.title, "\n")] = '\0'; // Xoa ky tu newline
                    printf("Nhap credit: ");
                    scanf("%d", &newCourse.credit);
                    clearInputBuffer(); // Xoa bo dem sau scanf
                    // B3: Them khoa hoc vao DSLK don
                    singleHead = insertSingleNodeAtEnd(singleHead, newCourse);
                }
                break;
            case 2:
                displaySingleList(singleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap id can xoa: ");
                scanf("%d", &deleteId);
                clearInputBuffer(); // Xoa bo dem sau scanf
                singleHead = deleteSingleNodeById(singleHead, deleteId);
                break;
            case 4:
                int updateId;
                printf("Nhap id can sua: ");
                scanf("%d", &updateId);
                clearInputBuffer(); // Xoa bo dem sau scanf
                updateCourseById(singleHead, updateId);
                break;
            case 5:
                int finishId;
                printf("Nhap id can danh dau hoan thanh: ");
                scanf("%d", &finishId);
                clearInputBuffer(); // Xoa bo dem sau scanf
                // B1: Xoa khoa hoc khoi DSLK don
                singleHead = deleteSingleNodeById(singleHead, finishId);
                if (finishNode == NULL) {
                    break;
                }
                // B2: Them khoa hoc vao DSLK doi
                Course finishCourse;
                finishCourse.id = finishNode->course.id;
                finishCourse.credit = finishNode->course.credit;
                strcpy(finishCourse.title, finishNode->course.title);
                doubleHead = insertDoubleNodeAtEnd(doubleHead, finishCourse);
                finishNode = NULL;
                break;
            case 6:
                singleHead = sortSingleListByCredit(singleHead);
                printf("Danh sach da duoc sap xep theo tin chi\n");
                displaySingleList(singleHead);
                break;
            case 7:
                char findStr[100];
                printf("Nhap ten khoa hoc muon tim: ");
                clearInputBuffer(); // Xoa bo dem truoc khi nhap chuoi
                fgets(findStr, sizeof(findStr), stdin);
                findStr[strcspn(findStr, "\n")] = '\0'; // Xoa ky tu newline
                searchCourseByTitle(singleHead, findStr);
                break;
            case 8:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);
    // Giai phong bo nho truoc khi thoat
    // Giai phong DSLK don
    SingleNode *tempSingle = singleHead;
    while (tempSingle != NULL) {
        SingleNode *next = tempSingle->next;
        free(tempSingle);
        tempSingle = next;
    }
    // Giai phong DSLK doi
    DoubleNode *tempDouble = doubleHead;
    while (tempDouble != NULL) {
        DoubleNode *next = tempDouble->next;
        free(tempDouble);
        tempDouble = next;
    }
    return 0;
}