#include <stdio.h>

void sorting_ele(int a[], int start, int end, int arr_len);
void merging_elements(int a[], int start, int middle, int end, int arr_len);


int main(int argc, char *argv[]) {

  int arr[] = {16, 3, -5, 23, 44, 18, 39, 76, 2};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  sorting_ele(arr, 0, arr_size - 1, arr_size);

  //Printing out the sorted array;
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  return 0;
};

//Sorting the elements;
void sorting_ele(int a[], int start, int end, int arr_len) {
  if (start < end) {
    int middle = (start + end) / 2;
    sorting_ele(a, start, middle, arr_len);
    sorting_ele(a, middle + 1, end, arr_len);

    merging_elements(a, start, middle, end, arr_len);
  };
};

//Merging the elements togther;
void merging_elements(int a[], int start, int middle, int end, int arr_len) {
  int i, j, k;
  int curr[arr_len];

  i = start;
  j = middle + 1;
  k = start;

  while (i <= middle && j <= end) {
    if (a[i] <= a[j]) {
      curr[k] = a[i];
      i++;
      k++;
    } else {
      curr[k] = a[j];
      j++;
      k++;
    };
  };

  while (i <= middle) {
    curr[k] = a[i];
    i++;
    k++;
  };

  while (j <= end) {
    curr[k] = a[j];
    j++;
    k++;
  };

  //Swaping the sorted array with the unsorted one;
  for(int p = start; p <= end; p++)
    a[p] = curr[p];
};

