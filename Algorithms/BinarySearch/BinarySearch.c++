// Binary Search Algorithm
// Finds an element from a sorted array

#include <iostream>
#include <array>

template<size_t S>
int binarySearch(const std::array<int, S>& arr, const int& num) {
	size_t index = -1;
	size_t start = 0, end = arr.size(), mid = (start + end) / 2;

	while (true) {
		if (arr[mid] == num) {
			index = mid;
			break;
		}
		if (start == mid && arr[mid] != num) break;
		
		if (num > arr[mid]) start = mid;
		else end = mid;
		mid = (start + end) / 2;
	}

	return index;

}

int main() {
	std::array<int, 10> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << binarySearch(arr, 5);
}