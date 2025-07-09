//
// Created by ROG on 7/9/2025.
//
#include <stdio.h>
#include <string.h>

typedef struct Stack {
    char arr[100];
    int top;
    int maxSize;
} Stack;

Stack creatStack (int maxSize) {
    Stack s;
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

void push (Stack *s, char element) {
    if ( s->top < s->maxSize - 1) {
        s->top++;
        s->arr[s->top]= element;
    }
}
char pop (Stack *s) {
    if (s->top >= 0) {
        char element = s->arr[s->top];
        s->top--;
        return element;
    }
    return '\0';
}
int valid(const char str[]) {
    int leng = strlen(str);
    Stack s = creatStack(leng);
    for (int i = 0; i < leng; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&s, str[i]);
        }else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            char top = pop(&s);
            if ((str[i]== ')' && top != '(' ) ||
                (str[i] == ']' && top != '[' ) ||
                (str[i] == '}' && top != '{')  ||
                top == '\0') {
                return 0;
            }
        }
    }
    return s.top == -1;
}



int main(void) {

    char str[100];
    printf("Moi nhap bieu thuc: ");
    scanf("%[^\\n]", str);

    printf("\"%s\"\n", str);
    if (valid(str)) {
        printf("TRue\n");
    }else{
    printf("False\n");}

    return 0;
}