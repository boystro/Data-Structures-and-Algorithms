
def binary_search(arr, num):
    index = -1;
    start = 0;
    end = len(arr);
    mid = ( start + end ) // 2;

    while True:
        if ( arr[mid] == num ):
            index = mid;
            break;
        if ( start == mid and arr[mid] != num ):
            break;
        if ( num > arr[mid] ):
            start = mid;
        else:
            end = mid;
        mid = ( start + end ) // 2;

    return index;

def main():
    arr = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    print(binary_search(arr, 7));

if ( __name__ == '__main__'):
    main();