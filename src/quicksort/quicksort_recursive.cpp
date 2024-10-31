#include <iostream>
#include <vector>
#include "../common/utils.h"
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int middle = low + (high - low) / 2;
    int pivo = arr[middle];

    int start = low;
    int end = high;

    while (start <= end)
    {
        while (arr[start] < pivo)
        {
            start++;
        }

        while (arr[end] > pivo)
        {
            end--;
        }

        if (start <= end)
        {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    return start;
}

void quickSort(vector<int> &array, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot, right);
    }
}

int main()
{
    vector<int> data = {8, 7, 2, 1, 0, 9, 6};
    printVector(data);

    quickSort(data, 0, data.size() - 1);

    printVector(data);

    return 0;
}
