//This is an optimized bubble sorting algorithm;

#include <stdio.h>
#include <stdbool.h>

void opti_sort(int a[], int len);
void swap_ele(int *x, int *y);

int main(int argc, char *argv[]) {

  int arr[] = {23, -7, 18, 34, 45, 12, 4, 8, -2, 29};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  
  opti_sort(arr, arr_size);

  for( int p = 0; p < arr_size; p++)
    printf("%d ", arr[p]);

  return 0;
};

void opti_sort(int a[], int len) {
  int l = 0;

  while (l < len) {
    bool flag = false;
    int m = 0;

    while (m < len - l - 1) {
      if(a[m] < a[m + 1]) {
        flag = true;
        swap_ele(&a[m], &a[m + 1]);
      };

      m++;
    };

    l++;
    if(flag == false)
      break;
  }
};

void swap_ele(int *x, int *y) {
  int curr = *x;
  *x = *y;
  *y = curr;
};
