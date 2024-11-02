#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

const int ARRAY_SIZE_1000 = 1000;
const int ARRAY_SIZE_10000 = 10000;
const int ARRAY_SIZE_100000 = 100000;

void printArray(int array[], int n) {
  std::cout << "This is the array now: \n";
  for (int i = 0; i < n; i++) {
    std::cout << "Position " << i + 1 << ": " << array[i] << "\n";
  }
}

void printVector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { 
            arr[k++] = L[i++]; 
        } else { 
            arr[k++] = R[j++]; 
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
}

void readArrayFromFile(const std::string& fileName, int array[], int size) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        file >> array[i];
    }

    file.close();
}

void swap(int array[], int index1, int index2) { 
  int aux = array[index2];
  array[index2] = array[index1];
  array[index1] = aux;
}
