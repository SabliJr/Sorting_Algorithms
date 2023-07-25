#include <stdio.h>

void dotch_flag_sort(int a[], int len);
void swap_ele(int *x, int *y);

int main(int argc, char *argv[]) {

  int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
  int arr_length = sizeof(arr) / sizeof(arr[0]);

  dotch_flag_sort(arr, arr_length);

  for(int p = 0; p < arr_length; p++)
    printf("%d ", arr[p]);

  return 0;
};

void dotch_flag_sort(int a[], int len) {
  int start = 0;
  int  end = len - 1;
  int middle = 0;

  while (middle <= end) {
    if(a[middle] == 0) {
      swap_ele(&a[start], &a[middle]);

      start++;
      middle++;
    } else if (a[middle] == 1) {
      middle++;
    } else {
      swap_ele(&a[middle], &a[end]);
      end--;
    };
  };
};

void swap_ele(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
