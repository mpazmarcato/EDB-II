#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int buscaBinaria(const std::vector<int>& vec, int element) {
    int left = 0;
    int right = vec.size() - 1;
    int middle;

    while (left < right) {
        middle = (left + right) / 2;
        if (element > vec[middle]) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }
    if (vec[left] == element) {
        return left;
    }
    return -1;
}

int bBinRec(const std::vector<int>& vec, int left, int right, int element) {
    if (left > right) {
        return -1;
    }

    int middle = (left + right) / 2;

    if (vec[middle] == element) {
        return middle;
    }
    else if (vec[middle] > element) {
        return bBinRec(vec, left, middle - 1, element);
    }
    else {
        return bBinRec(vec, middle + 1, right, element);
    }
}

std::vector<int> generateRandomAges(int size) {
    std::vector<int> ages(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    for (int i = 0; i < size; ++i) {
        ages[i] = dist(gen);
    }
    return ages;
}

void search(int size) {
    std::vector<int> vec = generateRandomAges(size);
    std::sort(vec.begin(), vec.end());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    int elementToFind = dist(gen);

    std::cout << "\n\n--- Testando com vetor de tamanho " << size << " ---\n";
    std::cout << "Número a ser procurado: " << elementToFind << "\n";

    auto iterativeStart = std::chrono::high_resolution_clock::now();
    int iterativeResult = buscaBinaria(vec, elementToFind);
    auto iterativeEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> iterativeTime = iterativeEnd - iterativeStart;

    if (iterativeResult != -1) {
        std::cout << "Iterativa: Elemento encontrado na posição " << iterativeResult << "\n";
    } else {
        std::cout << "Iterativa: Elemento não encontrado.\n";
    }
    std::cout << "Tempo da busca iterativa: " << iterativeTime.count() << " segundos\n";

    auto recursiveStart = std::chrono::high_resolution_clock::now();
    int recursiveResult = bBinRec(vec, 0, vec.size() - 1, elementToFind);
    auto recursiveEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> recursiveTime = recursiveEnd - recursiveStart;

    if (recursiveResult != -1) {
        std::cout << "Recursiva: Elemento encontrado na posição " << recursiveResult << "\n";
    } else {
        std::cout << "Recursiva: Elemento não encontrado.\n";
    }
    std::cout << "Tempo da busca recursiva: " << recursiveTime.count() << " segundos\n";
}

int main() {
    search(100);    
    search(1000);   
    search(10000);  

    return 0;
}
