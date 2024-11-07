#include <iostream>
#include <vector>
#include "../common/utils.h"
#include <algorithm>

void quickSort(std::vector<int> &array, int left, int right)
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
    std::vector<int> data = generateRandomAges(10);

    std::cout << "Given vector is \n";
    printVector(data);

    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted vector is \n";
    printVector(data);

    return 0;
}
