// Insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int *arr, int arr_size, int mod_value);
void print_array(const int *arr, int arr_size);
void Insertion_sort(int *arr, int arr_size, long *comparisons, long *swaps); 


int main(int argc, char **argv)
{
    #define ELEMENTS_TO_SORT 1000
    #define MOD_VALUE 10

    int arr[ELEMENTS_TO_SORT];

    srand((unsigned int)time(NULL));

    generate_random_array(arr, ELEMENTS_TO_SORT, MOD_VALUE);

    printf("The original array\n");
    print_array(arr, ELEMENTS_TO_SORT);

    long comparisons = 0;
    long swaps = 0;

    Insertion_sort(arr, ELEMENTS_TO_SORT, &comparisons, &swaps);

    printf("\nSorted Array:\n");
    print_array(arr, ELEMENTS_TO_SORT);

    printf("\nInsertion Sort Stats:\n");
    printf("Compairons: %ld\n", comparisons);
    printf("Swaps:      %ld\n", swaps);

    return 0;
}

void generate_random_array(int *arr, int arr_size, int mod_value)
{
    for(int i = 0; i < arr_size; i++)
    {
        arr[i] = rand() % mod_value;
    }
}

void print_array(const int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("\n");
}

void Insertion_sort(int *arr, int arr_size, long *comparisons, long *swaps)
{
    for(int i = 1; i < arr_size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0)
        {
            (*comparisons)++;

            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                (*swaps)++;
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }
}


