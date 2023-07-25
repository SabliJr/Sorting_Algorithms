#include <stdio.h>

void sort_selectively(int a[], int length);
void sort_with_while(int arr[], int len);

int main(int argc, char *argv[]) {

  int arr[] = {5, 29, 13, 40, 18, 36, -1, 7, 0, -6, 22};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  //sort_selectively(arr, arr_size);
  sort_with_while(arr, arr_size);


  for(int u = 0; u < arr_size; u++)
    printf("%d ", arr[u]);

  return 0;
};

//Sorting with for loop;
void sort_selectively(int a[], int length) {
  for(int i = 0; i < length - 1; i++) {
    int min_position = i;
    for(int j = i + 1; j < length; j++) {
      if (a[j] < a[min_position])
        min_position = j;
    }

      if (min_position != i) {
        int temp = a[i];
        a[i] = a[min_position];
        a[min_position] = temp;
      }
  }
};

//Sorting with while loop;
void sort_with_while(int arr[], int len) {
  int i = 0;
  while (i < len - 1) {
    int min_index = i;
    int j = i + 1;
    
    while (j < len) {
      if (arr[j] < arr[min_index]) 
        min_index = j;

      j++;
    };

    if (min_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    }

    i++;
  };
};
