//
// Created by ROG on 6/25/2025.
//
 #include <stdio.h>

int main() {
  int n, value;
  printf("Moi nhap so luong cua mang: ");
  scanf("%d", &n);

  if (n <= 0) {
   printf("So luong phan tu khong hop le!!\n");
   return 1;
  }
  int arr[n];

  printf("Moi nhap cac phan tu cua mang: \n");
  for (int i = 0; i < n; i++) {
   printf("Nhap phan tu thu %d: ", i + 1);
   scanf("%d", &arr[i]);
  }
  printf("Mang : [");
  for (int i = 0; i < n; i++) {
   printf("%d", arr[i]);
   if (i < n - 1) {
    printf(", ");
   }
  }
  printf("]\n");

  int find = 0;
  for (int i = 0; i < n/2; i++) {
   if (arr[i] == arr[n - i - 1]) {
    find = 1;
    printf("Cap doi xung: (%d, %d)\n", arr[i], arr[i]);
   }
  }
 if (!find) {
  printf("Khong co phan tu doi xung\n");
 }

  return 0;
}