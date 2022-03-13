// Array
#include <iostream>

template<size_t S>
struct Array
{
private:
	int data[S];

public:
	Array() { memset(data, 0, sizeof data); }

	int& operator[](size_t index) { return data[index]; }
	const int& operator[](size_t index) const { return data[index]; }

	const int Size() const { return S; }
	void fill(int value) { for (size_t i = 0; i < S; i++) data[i] = value; }
};


int main()
{
	Array<5> arr;

	arr.fill(20);

	for (size_t i = 0; i < arr.Size(); i++)
		std::cout << arr[i] << " ";

}