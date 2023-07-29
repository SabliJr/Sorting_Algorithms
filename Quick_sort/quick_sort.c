#include <stdio.h>

void sort_quick(int a[], int start, int end);
int sort_partition(int arr[], int s, int e);
void swap_func(int *x, int *y);

int main(int argc, char *argv[]) {

  int arr[] = {5, 79, -3, 18, 24, 56, 8, 0, 33};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  
  sort_quick(arr, 0, arr_size - 1);

  for(int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);

  return 0;
};

//Sorting the elements quickly;
void sort_quick(int a[], int start, int end) {
 if (start < end) {
    int partition = sort_partition(a, start, end);
    sort_quick(a, start, (partition - 1));
    sort_quick(a, (partition + 1), end );
  }
};

//Positioning the partition;
int sort_partition(int arr[], int s, int e) {
  int povit = arr[e];
  int p_index = s;

  int j = s;
  while (j < e) {
    if(arr[j] < povit ) {
      swap_func(&arr[j], &arr[p_index]);
      p_index++;
    };

    j++;
  };

  swap_func(&arr[e], &arr[p_index]);
  return p_index;
};

//Swaping the elements
void swap_func(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
