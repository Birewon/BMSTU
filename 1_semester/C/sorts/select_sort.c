#include <stdio.h>

#define LENGTH 10
#define ERR_OK 0
#define ERR_IO 1

int input_arr(size_t length, int arr[])
{
    for (size_t i = 0; i < length; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            return ERR_IO;
        }
    }
    return ERR_OK;
}

void print_arr(size_t length, int arr[])
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int select_sort(size_t length, int arr[])
{
    size_t min_index = 0;
    for (size_t start = 0; start < length - 1; start++)
    {
        for (size_t current = start + 1; current < length; current++)
        {
            if (arr[current] < arr[min_index])
            {
                min_index = current;
            }
        }
        int temp = arr[start];
        arr[start] = arr[min_index];
        arr[min_index] = temp;
        min_index = start + 1;
    }
    return ERR_OK;
}

int main(void)
{
    size_t length;
    if (scanf("%zu", &length) != 1)
    {
        return ERR_IO;
    }
    int arr[LENGTH] = {0};
    if (input_arr(length, arr) == ERR_IO)
    {
        return ERR_IO;
    }

    select_sort(length, arr);
    print_arr(length, arr);

    return 0;
}