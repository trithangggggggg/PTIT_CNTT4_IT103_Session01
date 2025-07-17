#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Project {
    int id;
    char title[100];
    char owner[100];
    int priority;
} Project;

typedef struct SingleNode {
    Project project;
    struct SingleNode *next;
} SingleNode;

typedef struct DoubleNode {
    Project project;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

SingleNode *finishNode = NULL;

SingleNode *createSingleNode(Project project) {
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode->project = project;
    newNode->next = NULL;
    return newNode;
}

SingleNode *insertSingleNodeAtEnd(SingleNode *head, Project project) {
    SingleNode *temp = head;
    while (temp != NULL) {
        if (temp->project.id == project.id) {
            printf("Id %d da ton tai, khong the them !\n");
            return head;
        }
        temp = temp->next;
    }
    SingleNode *newNode = createSingleNode(project);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
//case2
void displayList(SingleNode *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    printf("List du an:\n");
    while (temp != NULL) {
        printf("Id: %d\n", temp->project.id);
        printf("Ten du an: %s\n", temp->project.title);
        printf("Nguoi quan ly: %s\n", temp->project.owner);
        printf("Muc do uu tien: %d\n\n", temp->project.priority);
        temp = temp->next;
    }
    printf("\n");
}


//case3
SingleNode *deleteSingleNodeById(SingleNode *head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->project.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim tahy id %d !\n", id);
        return head;
    }
    if (temp == head) {
        head = head->next;
        finishNode = temp;
        free(temp);
        return head;
    }
    prev->next = temp->next;
    finishNode = temp;
    free(temp);
    return head;
}

// case4
SingleNode *updateSingleNodeById(SingleNode *head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    SingleNode *temp = head;
    while (temp != NULL && temp->project.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay id %d !\n", id);
        return head;
    }
    printf("Id: %d\n", temp->project.id);
    printf("Ten du an cu: %s\n", temp->project.title);
    printf("Nguoi quan ly cu: %s\n", temp->project.owner);
    printf("Muc do uu tien cu: %d\n\n", temp->project.priority);

    printf("Moi nhap thong tin moi: \n");
    fflush(stdin);
    printf("Nhap ten du an: ");
    fgets(temp->project.title, sizeof(temp->project.title), stdin);
    temp->project.title[strlen(temp->project.title) - 1] = '\0';
    printf("Nhap ten nguoi quan ly: ");
    fgets(temp->project.owner, sizeof(temp->project.owner), stdin);
    temp->project.owner[strlen(temp->project.owner) - 1] = '\0';
    printf("Nhap muc do uu tien: ");
    scanf("%d", &temp->project.priority);
    printf("Da update du an iid %d", id);
}
// case6
SingleNode *softByPriority(SingleNode *head) {
    if (head == NULL || head->next == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    int swap;
    SingleNode *current;
    SingleNode *last = NULL;

    do {
        swap = 0;
        current = head;
        while (current->next != last) {
            if (current->project.priority > current->next->project.priority) {
                Project temp = current->project;
                current->project = current->next->project;
                current->next->project = temp;
                swap = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swap);
}

//case7
void searchByName(SingleNode *head, char *name) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SingleNode *temp = head;
    int find = 0;
    while (temp != NULL) {
        if (strstr(temp->project.title, name) != NULL) {
            printf("Id: %d\n", temp->project.id);
            printf("Ten du an: %s\n", temp->project.title);
            printf("Nguoi quan ly: %s\n", temp->project.owner);
            printf("Muc do uu tien: %s\n", temp->project.title);
            find = 1;
        }
        temp = temp->next;
    }
    if (!find) {
        printf("Nhong tim thay du an ten %s !\n", name);
    }
}

int main() {
    int choice;
    SingleNode *singleHead = NULL;
    DoubleNode *doubleHead = NULL;
    do {
        printf("\n===============MENU==============\n");
        printf("1. Them moi du an \n");
        printf("2. Hien thi danh sach du an ca nhan\n");
        printf("3. Xoa du an\n");
        printf("4. Cap nhat thong tin du an\n");
        printf("5. Danh dau du an da hoan thanh\n");
        printf("6. Sap xep du an theo muc do uu tien\n");
        printf("7. Tim kiem du an theo ten\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int n;
                printf("Nhap so luong du an can them: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    Project newProject;
                    printf("Nhap thong tin du an thu %d:\n", i+1);
                    printf("Nhap id: ");
                    scanf("%d", &newProject.id);
                    fflush(stdin);
                    printf("Nhap ten du an: ");
                    fgets(newProject.title, sizeof(newProject.title), stdin);
                    newProject.title[strcspn(newProject.title, "\n")] = '\0';
                    printf("Nhap ten nguoi quan ly: ");
                    fgets(newProject.owner, sizeof(newProject.owner), stdin);
                    newProject.owner[strcspn(newProject.owner, "\n")] = '\0';
                    printf("Nhap muc do uu tien: ");
                    scanf("%d", &newProject.priority);
                    singleHead = insertSingleNodeAtEnd(singleHead, newProject);
                }

                break;
            case 2:
                displayList(singleHead);
                break;
            case 3:
                int deleteId;
                printf("Moi nhap Id muon xoa: ");
                scanf("%d", &deleteId);
                singleHead = deleteSingleNodeById(singleHead, deleteId);
                break;
            case 4:
                int updateId;
                printf("Moi nhap Id muon update: ");
                scanf("%d", &updateId);
                singleHead = updateSingleNodeById(singleHead, updateId);
                break;
            case 5:
                break;
            case 6:
                singleHead = softByPriority(singleHead);
                printf("Du an sau khi da xap xep theo muc do uu tien: \n");
                displayList(singleHead);
                break;
            case 7:
                char nameSearch;
                printf("Nhap ten an tim: ");
                fgets(nameSearch, sizeof(nameSearch), stdin);
                nameSearch[strcspn(nameSearch, "\n")] = '\0';
                searchByName(singleHead, nameSearch);
                break;
            case 8:
                printf("Hen gap lai!!\n");
                break;
            default:
                printf("Lua chon khong hop le (1-8)!!\n");
        }
    } while (choice != 8);

    return 0;
}