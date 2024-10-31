#include "../common/utils.h"

using namespace std;

void bubbleSortRecursive(int array[], int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
        if (array[i] > array[i + 1])
            swap(array, i, i + 1);
    bubbleSortRecursive(array, n - 1);
}

int main()
{
    int array[] = {16, 2, 25, 11, 33, 4, 70};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    
    bubbleSortRecursive(array, n);

    printArray(array, n);
    return 0;
}