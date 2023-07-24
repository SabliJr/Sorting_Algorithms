#include <stdio.h>

void sorting_with_forLoop(int arr[], int arrLenght);
void sorting_with_whileLoop(int arr[], int arrLenght);

int main(int argc, char *argv[]) {

  int arr[] = {13, 5, 82, 18, 34, 68, 23, 49};
  int arrLenght = sizeof(arr) / sizeof(arr[0]); //Creating the array length dynamically

  sorting_with_forLoop(arr, arrLenght);
  sorting_with_whileLoop(arr, arrLenght);

  //Checking array length;
  //printf("%d", arrLenght);
  return 0;
};

//Sorting the array with for loop;
void sorting_with_forLoop(int arr[], int arrLenght) {

  for (int i = 0; i < arrLenght; i++) {
    for (int j = i + 1; j < arrLenght; j++) {
      if (arr[i] > arr[j]) {
        int curr = arr[i];
        arr[i] = arr[j];
        arr[j] = curr;
      }
    }

    //Printing the array;
    //printf("%d\n", arr[i]);
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

  for (i = 0; i < arrLenght; i++)
    printf("%d ", arr[i]);
};
