#include <stdio.h>
#define ARRAY_SIZE 50

void shift_element(int *arr, int i)
{
    if (i == 0)
    {
        return;
    }
    int n = *(arr + i);
    while (i >= 0)
    {
        *(arr + i) = *(arr + i - 1);
        i--;
    }
    *arr = n;
}
void insertion_sort(int *arr, int len)
{
    int flag, current = 0;
    for (int i = 1; i < len; i++)
    {
        current = *(arr + i);
        if (current < *(arr + i - 1))
        {

            flag = 0;
            int j = i;
            while ((j >= 0) && (flag == 0))
            {
                if (current > *(arr + j))
                {
                    int swap = current;
                    shift_element((arr + j + 1), i - j - 1);
                    *(arr + j + 1) = swap;
                    flag = 1;
                }
                j--;
            }
            if (flag == 0)
            {
                int temp = current;
                shift_element((arr), i);
                *(arr) = temp;
            }
        }
    }
}

int main()
{
    int j, current = 0;
    printf("Please enter 50 positive integers:\n"); //This line may need to be removed because of the automatic check
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE;)
    {
        if ((scanf("%d", (array + i))) == 1)
            i++;
    }

    insertion_sort(array, ARRAY_SIZE);
    for (j = 0; j < ARRAY_SIZE; j++)
    {
        current = *(array + j);
        if (j == ARRAY_SIZE - 1)
            printf("%d\n", current);
        printf("%d,", current);
    }

    return 0;
}