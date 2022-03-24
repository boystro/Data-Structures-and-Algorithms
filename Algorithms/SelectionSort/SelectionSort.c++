// SELECTION SORT
// SORTS ELEMENT BY COMPARING EACH ELEMENT FROM FRONT TO REST OF THE ARRAY

#include <iostream>
#include <array>

template<size_t S>
void selectionSort(std::array<int, S>& arr) {
	//  TIME COMPLEXITY : O(N^2)
	int temp;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	std::array<int, 10> arr = { 79, 45, 88, 63, 12, 78, 23, 39, 95, 82 };

	for (auto data : arr) {
		std::cout << data << " ";
	} std::cout << std::endl;

	selectionSort(arr);

	for (auto data : arr) {
		std::cout << data << " ";
	} std::cout << std::endl;
}