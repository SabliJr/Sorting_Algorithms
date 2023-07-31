#include <stdio.h>

int quickSelect(int a[], int lo, int hi, int k);
int partition(int a[], int lo, int hi);
void swap_eles(int *x, int *y);

int main(int agrc, char *argv[]) {

  int arr[] = {2, 15, 6, 1, 18, 39, 67, 7, 58};
  int a_size = sizeof(arr) / sizeof(arr[0]);
  int k = 5;

  int res = quickSelect(arr, 0, a_size - 1, k);

  //Printing the array;
  //for(int m = 0; m < a_size; m++)
    //printf("%d ", arr[m]);

  printf("%d ", res);

  return 0;
};

int quickSelect(int a[], int lo, int hi, int k) {

    while (lo <= hi) {
    int p = partition(a, lo, hi);

    if(p == k - 1) {
      return a[p];
    } else if (p > k - 1) {
      hi = p - 1;
    } else {
     lo = p + 1;
    }
  };
  
  return -1;
};

int partition(int a[], int lo, int hi) {
  int povit = a[hi];
  int i = (lo - 1);
  int j = 0;

  while(j < hi - 1) {
    if(a[j] < povit) {
      i++;
      swap_eles(&a[i], &a[j]);
    }

    j++;
  }
  
  swap_eles(&a[i + 1], &a[hi]);
  return (i - 1);
};

void swap_eles(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
