#include <iostream>

void printArray(int array[], int n) {
  std::cout << "This is the array now: \n";
  for (int i = 0; i < n; i++) {
    std::cout << "Position " << i + 1 << ": " << array[i] << "\n";
  }
}

void swap(int array[], int index1, int index2) { 
  int aux = array[index2];
  array[index2] = array[index1];
  array[index1] = aux;
}
