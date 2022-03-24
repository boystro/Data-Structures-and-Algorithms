
def insertion_sort(arr):
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if ( arr[j] < arr[j-1]):
                arr[j], arr[j-1] = arr[j-1], arr[j];
            else:
                break;

def main():
    arr = [47, 85, 96, 12, 45, 78, 32, 65, 98];
    print(arr);
    insertion_sort(arr);
    print(arr);

if ( __name__ == '__main__'):
    main();