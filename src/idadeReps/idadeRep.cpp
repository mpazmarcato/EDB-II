#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "../common/utils.h"

bool idadeRep(const std::vector<int>& Idade) {
    int tam = Idade.size();
    if (tam == 0) return false;
    int menor = 200;

    for (int i = 0; i < tam; i++) {
        if (Idade[i] < menor) {
            menor = Idade[i];
        }
    }

    int count = 0;
    for (int i = 0; i < tam; i++) {
        if (Idade[i] == menor) {
            count++;
        }
    }

    return count > 1;
}

bool idadeRep2(std::vector<int>& Idade){
    sort(Idade.begin(), Idade.end());
    return Idade[0] == Idade[1];
}

int main() {
    std::vector<int> sizes = {100, 1000, 10000};
    for (int size : sizes) {
      std::vector<int> ages = generateRandomAges(size);
      // Medindo o tempo para idadeRep
      auto start1 = std::chrono::high_resolution_clock::now();
      bool result1 = idadeRep(ages);
      auto end1 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> duration1 = end1 - start1;
      // Medindo o tempo para idadeRep2
      auto start2 = std::chrono::high_resolution_clock::now();
      bool result2 = idadeRep2(ages);
      auto end2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> duration2 = end2 - start2;
      std::cout << "\n\n--- Testando com vetor de tamanho " << size << "---\n";
      std::cout << "idadeRep: " << (result1 ? "Elementos repetidos" : "Sem repetição") << "\n";
      std::cout << "Tempo de idadeRep: " << duration1.count() << " segundos\n";
      std::cout << "idadeRep2: " << (result2 ? "Elementos repetidos" : "Sem repetição") << "\n";
      std::cout << "Tempo de idadeRep2: " << duration2.count() << " segundos\n";
    }
    return 0;
}
