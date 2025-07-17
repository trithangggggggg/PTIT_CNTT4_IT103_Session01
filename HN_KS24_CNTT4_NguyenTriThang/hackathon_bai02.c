#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

typedef struct Node {
    char text[MAX_LEN];
    struct Node *next;
}Node;

typedef struct Stack {
    Node *top;
}Stack;

int main() {

    int choice;
    do {
        printf("=======Clipboard======\n");
        printf("1. Copy\n");
        printf("2. Paste\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Hien thi\n");
        printf("6. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {

            }
            case 2: {

            }
            case 3: {

            }
            case 4: {

            }
            case 5: {

            }
            case 6: {
                printf("Da thoat!\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le!\n");
            }
        }
    } while (choice != 6);

    return 0;
}