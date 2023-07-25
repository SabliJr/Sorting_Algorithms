#include <stdio.h>

void sort_insertionaly(int a[], int len);
void sorting_while(int arr[], int size);

int main(int argc, char *argv[]) {

  int arr[] = {26, 18, 39, 21, 33, 0, -5, 4, 10, 55};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  sort_insertionaly(arr, arr_size);
  sorting_while(arr, arr_size);

  for(int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  return 0;
};

//Sorting with for loop;
void sort_insertionaly(int a[], int len) {
  for (int i = 1; i < len; i++) {
    int k = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > k) {
      a[j + 1] = a[j];
      j--;
    };

    a[j + 1] = k;
  };
};

//Sorting using only while loop;
void sorting_while(int arr[], int size) {
  int i = 0;

  while (i < size) {
    int k = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > k) {
      arr[j + 1] = arr[j];
      j--;
    };

    arr[j + 1] = k;
    i++;
  };
};
