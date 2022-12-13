#include <iostream>
#include <vector>

class MergeSort {

  void merge(std::vector<int>& sequence, int lo, int hi, int mid) {
    std::vector<int> tempArr;
    int l = lo;
    int r = mid+1;
    while (l <= mid && r <= hi) {
      if (sequence[l] < sequence[r]) 
        tempArr.emplace_back(sequence[l++]);
      else
        tempArr.emplace_back(sequence[r++]);
    }

    while (l <= mid) {
      tempArr.emplace_back(sequence[l++]);
    }

    while (r <= hi) {
      tempArr.emplace_back(sequence[r++]);
    }

    for (int i = 0; i < tempArr.size(); i++)
      sequence[lo++] = tempArr[i];
  }

  void part(std::vector<int>& sequence, int lo, int hi) {
    if (hi <= lo) return;
    int mid = (hi + lo) / 2;
    part(sequence, lo, mid);
    part(sequence, mid+1, hi);
    merge(sequence, lo, hi, mid);
  }

public:

  void sort(std::vector<int>& sequence) {
    part(sequence, 0, sequence.size()-1);
  }

};

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& arr) {

  std::cout << "{ ";

  for (int i = 0; i < arr.size(); i++)
    std::cout << arr[i] << (i==arr.size()-1?"":", ");

  std::cout << " }";

  return stream;
}

int main() {
  std::vector<int> myArr = { 5, 7, 1, 2, 6, 0, -2, -6, -1, 8, 9, 10, 2 };

  std::cout << myArr << std::endl;

  MergeSort sorter;
  sorter.sort(myArr);

  std::cout << myArr << std::endl;

  return 0;
}