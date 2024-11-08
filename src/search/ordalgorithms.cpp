#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <stack>

using namespace std;
using namespace std::chrono;

void swap(int array[], int index1, int index2) { 
  int aux = array[index2];
  array[index2] = array[index1];
  array[index1] = aux;
}

// Function to generate random lists
void generateRandomList(const string& filename, int size) {
    ofstream file(filename);
    srand(time(0));
    for (int i = 0; i < size; i++) {
        file << rand() % 1001 << endl;  // Random number between 0 and 1000
    }
    file.close();
}

// Function to load a list from a file
vector<int> loadList(const string& filename) {
    ifstream file(filename);
    vector<int> list;
    int number;
    while (file >> number) {
        list.push_back(number);
    }
    file.close();
    return list;
}

// Bubble Sort (Iterative)
void bubbleSortIterative(int array[], int size) {
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

// Bubble Sort (Recursive)
void bubbleSortRecursive(int array[], int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
        if (array[i] > array[i + 1])
            swap(array, i, i + 1);
    bubbleSortRecursive(array, n - 1);
}


// Merge Sort Helper (Recursive)
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
// Merge Sort (Recursive)
void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Merge Sort (Iterative)
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

// Quick Sort (Recursive)
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

void quickSort(vector<int> &array, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot - 1);
        quickSort(array, pivot, right);
    }
}

// Quick Sort (Iterative)
void quickSortIterative(vector<int> &array, int left, int right)
{
    stack<pair<int, int>> s;

    s.push({left, right});

    while (!s.empty())
    {
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        // Particiona o subarray e obtém o índice do pivô
        int pivot = partition(array, low, high);

        //subarray da esquerda
        if (low < pivot - 1)
        {
            s.push({low, pivot - 1});
        }

        //subarray da direita
        if (pivot < high)
        {
            s.push({pivot, high});
        }
    }
}

void saveList(const string& filename, const vector<int>& list) {
    ofstream file(filename);
    for (int i : list) {
        file << i << endl;
    }
    file.close();
}

int main() {
    const vector<int> sizes = {1000, 10000, 100000}; 
    const string filename_prefix = "random_list_";
    const string sorted_filename_prefix = "sorted_list_";

    for (int size : sizes) {
        cout << "\nProcessing list of size: " << size << endl;
        
        // Generate a filename based on the list size
        string filename = filename_prefix + to_string(size) + ".txt";
        string sorted_filename = sorted_filename_prefix + to_string(size) + ".txt";

        // Step 1: Generate a random list and save it to a file
        generateRandomList(filename, size);
        cout << "Random list generated and saved to " << filename << endl;

        // Step 2: Load the list from the file
        vector<int> list = loadList(filename);
        cout << "List loaded from " << filename << endl;

        // Step 3: Sort using different algorithms and measure time

        // Bubble Sort Iterative
        vector<int> bubbleListIter = list;
        auto start = high_resolution_clock::now();
        bubbleSortIterative(bubbleListIter.data(), bubbleListIter.size());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Bubble Sort Iterative took " << duration.count() << " ms" << endl;

        // Bubble Sort Recursive
        vector<int> bubbleListRec = list;
        start = high_resolution_clock::now();
        bubbleSortRecursive(bubbleListRec.data(), bubbleListRec.size());
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Bubble Sort Recursive took " << duration.count() << " ms" << endl;

        // Merge Sort Recursive
        vector<int> mergeListRec = list;
        start = high_resolution_clock::now();
        mergeSortRecursive(mergeListRec, 0, mergeListRec.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Merge Sort Recursive took " << duration.count() << " ms" << endl;

        // Merge Sort Iterative
        vector<int> mergeListIter = list;
        start = high_resolution_clock::now();
        mergeSortIterative(mergeListIter);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Merge Sort Iterative took " << duration.count() << " ms" << endl;

        // Quick Sort Recursive
        vector<int> quickListRec = list;
        start = high_resolution_clock::now();
        quickSort(quickListRec, 0, quickListRec.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Quick Sort Recursive took " << duration.count() << " ms" << endl;

        // Quick Sort Iterative
        vector<int> quickListIter = list;
        start = high_resolution_clock::now();
        quickSortIterative(quickListIter, 0, quickListIter.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Quick Sort Iterative took " << duration.count() << " ms" << endl;

        // Step 4: Save one of the sorted lists to a file
        saveList(sorted_filename, quickListIter);
        cout << "Sorted list saved to " << sorted_filename << endl;
    }

    return 0;
}
