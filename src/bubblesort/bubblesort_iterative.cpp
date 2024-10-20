#include "../common/utils.h"

const int ARRAY_SIZE = 10;

void bubblesort(int array[], int size) {
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
  int array[ARRAY_SIZE] = { 2, 10, 54, 31, 5, 3, 4, 99, 10, 111 };

  printArray(array, ARRAY_SIZE);

  std::cout << "Sorting now... \n";
  bubblesort(array, ARRAY_SIZE);

  std::cout << "Array is now sorted... \n";
  printArray(array, ARRAY_SIZE);
}
