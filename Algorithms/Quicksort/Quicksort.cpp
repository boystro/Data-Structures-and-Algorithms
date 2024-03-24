#include <iostream>
#include <vector>

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int partition(std::vector<int>& arr, int low, int high, int (*comp)(int, int)) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; ++j) {
    if (comp(arr[j], pivot) < 0) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, int (*comp)(int, int)) {
  if (low < high) {
    int pi = partition(arr, low, high, comp);
    quickSort(arr, low, pi - 1, comp);
    quickSort(arr, pi + 1, high, comp);
  }
}

int main() {
  std::vector<int> sequence = { 1, 4, 6, 0, -1, -2, 10, 9, -9 };

  quickSort(sequence, 0, sequence.size() - 1, [](int a, int b) -> int { return a - b; });

  for (int num : sequence) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
