#include <stdio.h>

void qs_3way(int a[], int left, int right);
void partition_3way(int a[], int left, int right, int i, int j);
void swap(int *x, int *y);

int main(int argc, char *argv[]) {

  int arr[] = {3, 9, 7, 7, 5, 5, 7, 3, 7, 9};
  int a_len = sizeof(arr) / sizeof(arr[0]);

  qs_3way(arr, 0, a_len - 1);

  //display the array;
  int o = 0;
  while(o < a_len) {
    printf("%d ", arr[o]);
    o++;
  }
  return 0;
};

void qs_3way(int a[], int left, int right) {

  if(left >= right)
    return;

  int i, j;
  partition_3way(a, left, right, i, j);

  qs_3way(a, left, i);
  qs_3way(a, j, right);
};

void partition_3way(int a[], int left, int right, int i, int j) {

  if(right - left <= 1) {
    if (a[right] < a[left])
      swap(&a[right], &a[left]);

    i = left;
    j = right;

    return;
  };

  int mid = left;
  int pivot = a[right];

  while (mid <= right) {
    if(a[mid] < pivot) {
      swap(&a[left++], &a[mid++]);
    } else if (a[mid] == pivot) {
      mid++;
    } else if (a[mid] > pivot) {
      swap(&a[mid], &a[right--]);
    };

    i = left - 1;
    j = mid;
  }
  
};

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
};
