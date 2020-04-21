#include "libft.h"

void selection_sort(int arr[], int first, int last)
{
    int current;
    int min_index;
    int i;

    current = first;
    while (current <= (last - 1))
    {
        min_index = current;
        i = current + 1;
        while (i <= last)
        {
            if (arr[i] < arr[min_index])
                min_index = i;
            i++;
        }
        swap_int(arr, current, min_index);
        current++;
    }
}

void insertion_sort(int arr[], int first, int last)
{
    int current;
    int i;

    current = first + 1;
    while (current <= last)
    {
        i = current;
        while (i > 0 && arr[i - 1] > arr[i])
        {
            swap_int(arr, i - 1, i);
            i--;
        }
        current++;
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i;
    int j;
    int k;
    int L[middle - left + 1];
    int R[right - middle];

    int n1;
    int n2;

    n1 = middle - left + 1;
    n2 = right - middle;
    i = 0;
    while (i < n1)
    {
        L[i] = arr[left + i];
        i++;
    }
    i = 0;
    while (i < n2)
    {
        R[i] = arr[middle + 1 + i];
        i++;
    }
    i = j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    int middle;

    if (left < right)
    {
        middle = (left + right) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int partition(int *arr, int left, int right)
{
    int pivot;
    int i;
    int j;

    i = left - 1;
    pivot = arr[right];
    j = left;
    while (j <= right - 1)
    {
        if (arr[j] < pivot)
            i++;
        j++;
    }
    iswap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

void ft_qsort(int *arr, int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(arr, left, right);
        ft_qsort(arr, left, pivot - 1);
        ft_qsort(arr, pivot + 1, right);
    }
}

void shellsort(int *arr, int n)
{
    int i;
    int j;
    int gap;

    gap = n / 2;
    while (gap > 0)
    {
        i = gap;
        while (i < n)
        {
            j = i;
            while (j >= gap && arr[j - gap] > arr[j])
            {
                swap_int(arr, i - gap, i);
                j -= gap;
            }
            i++;
        }
        gap /= 2;
    }
}
