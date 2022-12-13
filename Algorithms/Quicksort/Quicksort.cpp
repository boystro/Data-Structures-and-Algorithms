#include <iostream>
#include <vector>

void quicksort(std::vector<int> sequence, int (*pointer)(int a, int b)) {
  
}

int main() {

  std::vector<int> sequence = { 1, 4, 6, 0, -1, -2, 10, 9, -9 };

  quicksort(sequence, [](int a, int b)->int{ return b - a; });

  return 0;
}