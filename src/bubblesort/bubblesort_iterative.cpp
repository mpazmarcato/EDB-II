#include "../common/utils.h"
#include <vector>

void bubbleSortIterative(std::vector<int>& array, int size) {
  bool hasConflict;
  do {
    hasConflict = false;
    for (int x = 0; x < size - 1; x++) {
      if (array[x] > array[x + 1]) {
        swap(array, x, x + 1);
        hasConflict = true;
      }
    }
  } while (hasConflict);
}

int main() { 
    std::vector<int> array = generateRandomAges(10);

    std::cout << "Given vector is \n";
    printVector(array);
    
    bubbleSortIterative(array, array.size());

    std::cout << "Sorted vector is \n";
    printVector(array);
    return 0;
}
