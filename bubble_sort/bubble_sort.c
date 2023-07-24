#include <stdio.h>

void sorting_with_forLoop(int arr[], int arrLenght);
void sorting_with_whileLoop(int arr[], int arrLenght);
void recursive_bubble_sort(int arr[], int arrLenght);

int main(int argc, char *argv[]) {

  int arr[] = {13, 5, 82, 18, 34, 68, 23, 49};
  int arrLenght = sizeof(arr) / sizeof(arr[0]); //Creating the array length dynamically

  sorting_with_forLoop(arr, arrLenght);
  sorting_with_whileLoop(arr, arrLenght);
  recursive_bubble_sort(arr, arrLenght);

  //Checking array length;
  printf("%d", arrLenght);

  //Printing out the array;
  for (int i = 0; i < arrLenght; i++)
    printf("%d ", arr[i]);

  return 0;
};

//Sorting the array with for loop;
void sorting_with_forLoop(int arr[], int arrLenght) {

  for (int i = 0; i < arrLenght; i++) {
    for (int j = 0; j < arrLenght - 1 - i; j++) {
      if (arr[j] < arr[j + 1]) {
        int curr = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = curr;
      }
    }

  }
};

//Sorting the array with while loop;
void sorting_with_whileLoop(int arr[], int arrLenght) {

  int i, j;
  i = 0;

  while (i < arrLenght) {
    j = i + 1;
    while (j < arrLenght) {
      if (arr[i] < arr[j]) {
        int curr = arr[i];
        arr[i] = arr[j];
        arr[j] = curr;
      }
      j++;
    }
    i++;
  }

};

//Sorting the array recursively
void recursive_bubble_sort(int arr[], int arrLenght) {

  if (arrLenght == 1) {
    return;
  }

  int i = 0;
  while (i < arrLenght - 1) {
    if (arr[i] < arr[i + 1]) {
      int curr = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = curr;
    };
    i++;
  };

  arrLenght--;
  recursive_bubble_sort(arr, arrLenght);
};
