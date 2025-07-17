//
// Created by ROG on 7/14/2025.
//
// yesterday
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[100];
    struct Task *next;
} Task;

typedef struct History {
    int id;
    char title[100];
    int priority;
    char deadline[100];
    struct History *next;
    struct History *prev;
} History;

Task *taskHead = NULL;

Task *createTask(int id, char title[], int priority, char deadline[]) {
    Task *task = (Task *)malloc(sizeof(Task));
    task->id = id;
    strcpy(task->title, title);
    task->priority = priority;
    strcpy(task->deadline, deadline);
    task->next = NULL;

    return task;
}

History *createHistory(int id, char title[], int priority, char deadline[]) {
    History *history = (History *)malloc(sizeof(History));
    history->id = id;
    strcpy(history->title, title);
    history->priority = priority;
    strcpy(history->deadline, deadline);
    history->next = NULL;
    history->prev = NULL;

    return history;
}

void add() {
    int id;
    char title[100];
    int priority;
    char deadline[100];

    printf("Hay nhap id: ");
    scanf("%d", &id);
    getchar();
    printf("Hay nhap title: ");
    scanf("%s", title);
    getchar();
    printf("Hay nhap priority: ");
    scanf("%d", &priority);
    getchar();
    printf("Hay nhap deadline: ");
    scanf("%s", deadline);
    getchar();

    Task *task = createTask(id, title, priority, deadline);
    task->next = taskHead;
    taskHead = task;
}

void printfList() {
    Task *task = taskHead;
    if (task == NULL) {
        printf("Ko co ... nao");
        return;
    }
    while (task != NULL) {
        printf("Id: %d\n", task->id);
        printf("Title: %s\n", task->title);
        printf("Priority: %d\n", task->priority);
        printf("Deadline: %s\n\n", task->deadline);
        task = task->next;
    }
}

// void deleteId() {
//     int id;
//     printf("Hay nhap id muon xoa: ");
//     scanf("%d", &id);
//     getchar();
//
//     Task *task = taskHead;
//     Task *prev = NULL;
//     while (task != NULL) {
//         if (task->id == id) {
//             if (prev == NULL) {
//                 prev->next = task->next;
//             } else {
//                 task = task->next;
//                 free(task);
//                 return ;
//             }
//         }
//     }
// }

void update() {
    int id;
    printf("Hay nhap id muon cap nhat: ");
    scanf("%d", &id);
    getchar();

    Task *task = taskHead;
    while (task != NULL) {
        if (task->id == id) {
            printf("Hay nhap title moi: ");
            scanf("%s", task->title);
            getchar();
            printf("Hay nhap priority moi: ");
            scanf("%d", &task->priority);
            getchar();
            printf("Hay nhap deadline moi: ");
            scanf("%s", task->deadline);
            getchar();
        }
        task = task->next;
    }
}

// void sort() {
//     for (Task *i = taskHead; i->next != NULL; i = i->next) {
//         for (Task *j = i; j->next != NULL; j = j->next) {
//             if (i->priority > j->priority) {
//                 int temp = i->priority;
//                 i->priority = j->priority;
//                 j->priority = temp;
//             }
//         }
//     }
// }

void search() {
    char search[100];
    printf("Hay nhap title muon tim kiem: ");
    scanf("%s", search);
    getchar();

    Task *task = taskHead;
    int found = 0;
    while (task != NULL) {
        if (strstr(task->title, search)) {
            printf("Id: %d\n", task->id);
            printf("Title: %s\n", task->title);
            printf("Priority: %d\n", task->priority);
            printf("Deadline: %s\n", task->deadline);
            found = 1;
        }
        task = task->next;
    }
    if (found == 0) {
        printf("Ko tim thay %s nao\n", search);
    }
}

int main(void) {
    int choice;

    do {
        printf("1. Them\n");
        printf("2. Hien thi\n");
        printf("3. Xoa\n");
        printf("4. Cap nhat\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep\n");
        printf("7. Tim kiem\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                add();
                break;
            }
            case 2: {
                printfList();
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                update();
                break;
            }
            case 5: {

                break;
            }
            case 6: {
                break;
            }
            case 7: {
                search();
                break;
            }
            case 8: {
                printf("Thoat thanh cong\n");
                break;
            }
            default : {
                printf("Ko hop le");
            }
        }

    } while (choice != 8);

    return 0;
}