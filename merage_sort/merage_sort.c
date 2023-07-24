#include <stdio.h>

void merage_sort(int a[], int start, int end);
void megre_func(int a[], int left, int middle, int end);

int main() {

  int arr[] = {-2, 0, 6, 19, 38, -5, 47, 68, 4};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  merage_sort(arr, 0, arr_size - 1);
  printf("The array size %d\n", arr_size);

  return 0;
};

void merage_sort(int a[], int start, int end) {
  
  if (start < end) {
    int middle = (start + end) / 2;
    merage_sort(a, start, middle);
    merage_sort(a, middle + 1, end);

    megre_func(a, start, middle, end);
  };
};

void megre_func(int a[], int l, int m, int end) {
  int i, j, k;
  int temp[8];

  i = l;
  j = m + 1;
  k = l;

  while(i <= m && j <= end) {
    if (a[i] <= a[j]) {
      temp[k] = a[i];
      k++;
      i++;
    } else {
      temp[k] = a[j];
      k++;
      j++;
    };
  };

  while(i <= m) {
    temp[k] = a[i];
    k++;
    i++;
  };

  while (j <= end) {
    temp[k] = a[j];
    k++;
    j++;
  };

  for (int p = l; p <= end; p++)
    printf("%d", temp[p]);
};
