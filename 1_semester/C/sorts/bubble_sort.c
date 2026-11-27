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

int bubble_sort(size_t length, int arr[])
{
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - 1 - i; j++)
        {
            print_arr(length, arr);
            printf("%d %d\n############\n", arr[j], arr[j+1]);
            if (arr[j+1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubble_sort(length, arr);
    print_arr(length, arr);

    return 0;
}