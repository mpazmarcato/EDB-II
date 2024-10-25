#include <iostream>
#include <vector>
#include <stack>
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
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    return start;
}

void quickSortIterative(vector<int> &array, int left, int right)
{
    stack<pair<int, int>> s;

    // Empilha o subarray inicial (toda a array)
    s.push({left, right});

    // Processa os subarrays até que a pilha esteja vazia
    while (!s.empty())
    {
        // Desempilha os limites do subarray atual
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        // Particiona o subarray e obtém o índice do pivô
        int pivot = partition(array, low, high);

        // Se houver elementos à esquerda do pivô, empilha o subarray da esquerda
        if (low < pivot - 1)
        {
            s.push({low, pivot - 1});
        }

        // Se houver elementos à direita do pivô, empilha o subarray da direita
        if (pivot < high)
        {
            s.push({pivot, high});
        }
    }
}

int main()
{
    vector<int> data = {8, 7, 2, 1, 0, 9, 6};
    printVector(data);

    quickSortIterative(data, 0, data.size() - 1);

    printVector(data);

    return 0;
}
