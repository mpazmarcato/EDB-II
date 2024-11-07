#include "../common/utils.h"
#include <vector>

void bubbleSortRecursive(std::vector<int>& array, int n)
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
    std::vector<int> array = generateRandomAges(10);

    std::cout << "Given vector is \n";
    printVector(array);
    
    bubbleSortRecursive(array, array.size());

    std::cout << "Sorted vector is \n";
    printVector(array);
    return 0;
}
