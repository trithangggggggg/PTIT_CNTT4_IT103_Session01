#include <stdio.h>

int main() {

    int n, arr[100];
    int position, newValue;

    printf("Moi nhap so luong phan tu: ");
    scanf("%d",&n);

    if (n < 1 || n > 100) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    printf("Moi nhap cac phan tu\n");
    for (int i = 0;i < n;i++) {
        scanf("%d", arr[i]);
    }

    printf("Nhap vi tri muon sua: ");
    scanf("%d", &position);
    printf("Nhap gia tri muon sua: ");
    scanf("%d", &newValue);

    if (position >= 0 && position < n) {
        arr[position] = newValue;
    }else {
        printf("Vi tri khong hop le\n");
        return 1;
    }
    printf("Mang sau khi da cap nhat: \n[")
    for (int i = 0; i<n;i++) {
        printf("%d", arr[i]);
        if (i < n -1 ) {
            printf(", ");
        }
    }
    printf("")


    return 0;
}