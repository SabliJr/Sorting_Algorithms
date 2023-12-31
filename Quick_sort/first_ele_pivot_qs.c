#include <stdio.h>

void quick_sort(int a[], int l, int r);
int partition(int a[], int l, int r);
void swap_ele(int *x, int *y);

int main(int argc, char *argv[]) {

  int arr[] = {40, -2, 13, 29, 1, 8, 57, 33};
  int a_len = sizeof(arr) / sizeof(arr[0]);
  
  quick_sort(arr, 0, a_len - 1);

  //Print out the array;
  for (int u = 0; u < a_len; u++)
    printf("%d ", arr[u]);

  return 0;
};

void quick_sort(int a[], int l, int r) {
  if(l < r) {
    int p = partition(a, l, r);
    quick_sort(a, l, (p - 1));
    quick_sort(a, (p + 1), r);
  };
};

//Positioning the partition;
int partition(int a[], int lo, int hi) {
  int pivot = a[lo];
  int k = hi;
  int j = hi;

  while (j > lo) {
    if(a[j] > pivot) {
      swap_ele(&a[j], &a[k--]);
    }
    j--;
  };

  swap_ele(&a[lo], &a[k]);
  return k;
};

void swap_ele(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
};
