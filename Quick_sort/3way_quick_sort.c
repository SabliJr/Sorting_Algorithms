#include <stdio.h>

void swap_ele(int *x, int *y);
void quick_sort(int a[], int l, int r);
void partition(int a[], int l, int r, int *i, int *j);

int main(int argc, char *argv[]) {

  int arr[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
  int a_len = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, 0, a_len - 1);

  //Printing out the array;
  for(int o = 0; o < a_len; o++)
    printf("%d ", arr[o]);

  return 0;
};

void quick_sort(int a[], int l, int r) {
  if (r <= l)
    return;

  int i, j;
  partition(a, l, r, &i, &j);

  quick_sort(a, l, j);
  quick_sort(a, i, r);
};

void partition(int a[], int l, int r, int *i, int *j) {
  *i = l - 1;
  *j = r;

  int p = l - 1;
  int q = r;

  int u = a[r];

  while (1) {
    
    while (a[*i] < u)
      i++;

    while (u < a[*j]) {
      if(*j == 1)
        break;

      j--;
    };

    if(i >= j)
      break;

    swap_ele(&a[*i], &a[*j]);

    if(a[*i] == u) {
      p++;
      swap_ele(&a[p], &a[*i]);
    };

    if(a[*j] == u) {
      p--;
      swap_ele(&a[*j], &a[p]);
    };

    swap_ele(&a[*i], &a[r]);

    j = i - 1;
    int k = l;
    while (k < p) {
      swap_ele(&a[k], &a[*j]);
      k++;
      j--;
    };

    *i = *i + 1;
    int m = r - 1;
    while (m > p) {
      swap_ele(&a[*i], &a[k]);
      m--;
      i++;
    }
  }
}

void swap_ele(int *x, int *y) {
  int curr = *x;
  *x = *y;
  *y = curr;
};
