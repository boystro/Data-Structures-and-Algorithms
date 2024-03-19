def partition(arr, low, high):
	pivot = arr[high]
	i = low - 1
	for j in range(low, high):
		if arr[j] <= pivot:
			i += 1
			arr[i], arr[j] = arr[j], arr[i]
	arr[i + 1], arr[high] = (arr[high], arr[i + 1])
	return i + 1


def quickSort(arr, low, high):
	if low < high:
		pi = partition(arr, low, high)
		quickSort(arr, low, pi - 1)
		quickSort(arr, pi + 1, high)


def main():
	arr = [47, 85, 96, 12, 45, 78, 32, 65, 98];
	quickSort(arr, 0, len(arr) - 1)


if __name__ == '__main__':
	main()
