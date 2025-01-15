// Insertion sort
#include <stdio.h>

void Insertion_sort(int * arr, int arr_size);
void print_array(const int *arr, int arr_size);

int main(int argc, char **argv)
{
    #define ELEMENTS_TO_SORT 1000
    int arr[ELEMENTS_TO_SORT];

    int j = 0;
    for(int i = ELEMENTS_TO_SORT; i >= 0; i--)
    {
        arr[j] = i;
        j++;
    }

    printf("The original array\n");
    print_array(arr, ELEMENTS_TO_SORT);


    printf("Insertion sorting the array...\n");
    Insertion_sort(arr, ELEMENTS_TO_SORT);

    printf("The array after sorting...\n");
    print_array(arr, ELEMENTS_TO_SORT);

    return 0;
}

void Insertion_sort(int *arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] == key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    return;
}

void print_array(const int *arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        printf("%d\n",arr[i]);
    }

    return;
}
