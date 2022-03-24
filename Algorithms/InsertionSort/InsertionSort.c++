// INSERTION SORT
// SORT BY MOVING I TH ELEMENT TOWARDS LEFT UNTIL IT IS IN THE CORRECT POSITION

#include <iostream>
#include <array>

template<size_t S>
void insertion_sort(std::array<int, S>& arr) {

	int idx_ptr = 0;
	int temp;

	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {

			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	std::array<int, 10> arr = { 47, 67, 92, 14, 9, 65, 15, 36, 83, 66 };

	for (int data : arr) std::cout << data << " "; std::cout << std::endl;
	insertion_sort(arr);
	for (int data : arr) std::cout << data << " "; std::cout << std::endl;
}