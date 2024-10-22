#include "../common/utils.h"

void mergeSortIterative(std::vector<int>& arr) {
    int n = arr.size();

    if (n <= 1) return; 

    int length = 1; 

    while (length < n) {
        for (int i = 0; i < n - 1; i += 2 * length) {
            int start = i; 
            int mid = std::min(i + length - 1, n - 1); 
            int end = std::min(i + 2 * length - 1, n - 1); 

            merge(arr, start, mid, end);
        }

        length *= 2;
    }
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    std::cout << "Given vector is \n";
    printVector(arr);

    mergeSortIterative(arr);
    std::cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}
