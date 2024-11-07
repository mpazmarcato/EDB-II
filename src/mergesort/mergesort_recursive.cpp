#include "../common/utils.h"

void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = generateRandomAges(10);
    int n = arr.size();

    std::cout << "Given vector is \n";
    printVector(arr);

    mergeSortRecursive(arr, 0, n - 1);

    std::cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}
