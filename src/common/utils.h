#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

const int ARRAY_SIZE_1000 = 1000;
const int ARRAY_SIZE_10000 = 10000;
const int ARRAY_SIZE_100000 = 100000;

void swap(std::vector<int>& array, int index1, int index2) { 
    int aux = array[index2];
    array[index2] = array[index1];
    array[index1] = aux;
}

void printVector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int partition(std::vector<int> &arr, int low, int high)
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
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
    return start;
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

std::vector<int> generateRandomAges(int size) {
    std::vector<int> ages(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < size; ++i) {
        ages[i] = dis(gen);
    }
    return ages;
}
