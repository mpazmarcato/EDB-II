#include <iostream>
#include <vector>
#include <stack>
#include "../common/utils.h"
#include <algorithm>

void quickSortIterative(std::vector<int> &array, int left, int right)
{
    std::stack<std::pair<int, int>> s;

    s.push({left, right});

    while (!s.empty())
    {
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        // Particiona o subarray e obtém o índice do pivô
        int pivot = partition(array, low, high);

        //subarray da esquerda
        if (low < pivot - 1)
        {
            s.push({low, pivot - 1});
        }

        //subarray da direita
        if (pivot < high)
        {
            s.push({pivot, high});
        }
    }
}

int main()
{
    std::vector<int> data = generateRandomAges(10);
    std::cout << "Given vector is \n";
    printVector(data);

    quickSortIterative(data, 0, data.size() - 1);

    std::cout << "Sorted vector is \n";
    printVector(data);

    return 0;
}
