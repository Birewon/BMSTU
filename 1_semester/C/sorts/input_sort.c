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

int input_sort(size_t length, int arr[])
{
    for (size_t start = 1; start < length; start++)
    {
        int value = arr[start];
        size_t value_pos = start;
        while (value_pos != 0 && arr[value_pos - 1] > value)
        {
            arr[value_pos] = arr[value_pos - 1];
            value_pos--;
        }
        arr[value_pos] = value;
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

    input_sort(length, arr);
    print_arr(length, arr);

    return 0;
}