//
// Created by ROG on 7/25/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[50];
    int priority;
    char deadline[50];
}Task;

typedef struct SingleNode {
    Task task;
    struct SingleNode *next;
}SingleNode;

typedef struct DoubleNode {
    Task task;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;

SingleNode *finishNode = NULL;

SingleNode *createNode(Task task) {
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}
DoubleNode* createDoubleNode(Task task) {
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode->task=task;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;

}
SingleNode *addSingleNodeAtEnd(SingleNode *head, Task task) {
    SingleNode *temp = head;
    while (temp!=NULL) {
        if (temp->task.id == task.id) {
            printf("Id %d da ton tai, hay thu lai!\n", task.id);
            return head;
        }
        temp = temp->next;
    }
    SingleNode *newNode = createNode(task);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(SingleNode *head) {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    printf("List nhiem vu:\n");
    while (temp!=NULL) {
        printf("ID: %d\n", temp->task.id);
        printf("Title: %s\n", temp->task.title);
        printf("Priority: %d\n", temp->task.priority);
        printf("Deadline: %s\n", temp->task.deadline);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}


SingleNode *deleteNodebyId(SingleNode *head, int id) {
    if (head==NULL) {
        printf("List is empty\n");
        return NULL;
    }
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->task.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("khong tim thay id %d", id);
        return head;
    }
    if (prev == NULL) {
        head = head->next;
    }else {
        prev->next = temp->next;
    }
    finishNode = temp;
    free(temp);
    return head;
}

SingleNode *updateSingleNodebyId(SingleNode *head, int id) {
    if (head==NULL) {
        printf("List is empty\n");
        return NULL;
    }
    SingleNode *temp = head;
    while (temp != NULL && temp->task.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tm thay id %d!!\n", id);
        return head;
    }
    printf("Id: %d", temp->task.id);
    printf("Title: %s\n", temp->task.title);
    printf("Priority: %d\n", temp->task.priority);
    printf("Deadline: %s\n", temp->task.deadline);
    printf("Moi ban nhap thong tin moi \n");
    printf("Nhap title nhiem vu: ");
    fgets(temp->task.title, sizeof(temp->task.title), stdin);
    temp->task.title[strcspn(temp->task.title, "\n")] = '\0';
    printf("Nhap muc do uu tien: ");
    scanf("%d", &temp->task.priority);
    fflush(stdin);
    printf("Nhap deadline: ");
    fgets(temp->task.deadline, sizeof(temp->task.deadline), stdin);
    temp->task.deadline[strcspn(temp->task.deadline, "\n")] = '\0';
    return head;
}

// case 5
void highlightSingleNode(SingleNode **headSingly,DoubleNode **headDouble,int id) {
    if (*headSingly==NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *current = *headSingly;
    SingleNode *prev = NULL;
    while (current!=NULL && current->task.id != id) {
        prev = current;
        current=current->next;
    }
    if (current==NULL) {
        printf("khong tim thay id %d\n", id);
        return;
    }
    if (prev == NULL) {
        *headSingly = current->next;
    }else {
        prev->next = current->next;
    }
    DoubleNode *newNode = createDoubleNode(current->task);

    if (*headDouble == NULL) {
        *headDouble = newNode;
    } else {
        DoubleNode *temp = *headDouble;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    free(current);
    printf("Da danh dau hoan thanh id %d\n", id);
}


//case6
SingleNode *softByPriority(SingleNode *head) {
    if (head==NULL) {
        printf("List is empty\n");
        return NULL;
    }
    int swap;
    SingleNode *current;
    SingleNode *last = head;
    do {
        swap = 0;
        current = head;
        while (current->next!=last) {
            if (current->task.priority > current->next->task.priority) {
                Task temp = current->task;
                current->task = current->next->task;
                current->next->task = temp;
                swap = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swap);
}

// case7
void searchByTitle(SingleNode *head, char *title) {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    int find = 0;
    while (temp!=NULL) {
        if (strstr(temp->task.title, title) != NULL) {
        printf("Id: %d\n", temp->task.id);
            printf("Title: %s\n", temp->task.title);
            printf("Priority: %d\n", temp->task.priority);
            printf("Deadline: %s\n", temp->task.deadline);
            find = 1;
        }
        temp = temp->next;
    }
    if (!find) {
        printf("Khong tim thay nhieem vu %s !\n", title);
    }
}



int main() {
    int choice;
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    do {
        printf("\n==============MENU==========\n");
        printf("1. Them moi nhiem vu \n");
        printf("2. Hien thi danh sach nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat thong tin nhiem vu\n");
        printf("5. Danh dau nhiem vu da hoa thanh\n");
        printf("6. Sap xep nhiem vu theo muc do uu tien \n");
        printf("7. Tim kiem nhiem vu theo teu de\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int n;
                printf("Nhap so luong nhiem vu can them: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    Task newTask;
                    printf("Nhap thong tin du an thu %d: \n", i+1);
                    printf("Nhap ID: ");
                    scanf("%d", &newTask.id);
                    fflush(stdin);
                    printf("Nhap tieu de: ");
                    fgets(newTask.title, sizeof(newTask.title), stdin);
                    newTask.title[strcspn(newTask.title, "\n")] = '\0';
                    printf("Nhap muc do uu tien: ");
                    scanf("%d", &newTask.priority);
                    fflush(stdin);
                    printf("Nhap deadline: ");
                    fgets(newTask.deadline, sizeof(newTask.deadline), stdin);
                    newTask.deadline[strcspn(newTask.deadline, "\n")] = '\0';
                    singleHead = addSingleNodeAtEnd(singleHead, newTask);
                }
                break;
            case 2:
                printList(singleHead);
                break;
            case 3:
                int deleteID;
                printf("Nhap Id muon xoa: ");
                scanf("%d", &deleteID);
                singleHead = deleteNodebyId(singleHead, deleteID);
                break;
            case 4:
                int updateID;
                printf("Nhap Id muon update: ");
                scanf("%d", &updateID);
                singleHead = updateSingleNodebyId(singleHead, updateID);
                break;
            case 5:
                int IdDone;
                printf("Nhap id nhiem vu da hoan thanh :");
                scanf("%d", &IdDone);
                highlightSingleNode(&singleHead,&doubleHead, IdDone);
                break;
            case 6:
                singleHead = softByPriority(singleHead);
                printf("Nhiem vu sau khi da sap xep theo muc do uu tien:\n");
                printList(singleHead);
                break;
            case 7:
                char title[100];
                printf("Nhap ten nhiem vu can tim: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                searchByTitle(singleHead, title);
                break;
            case 8:
                printf("Tam biet!!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 8);
    return 0;
}