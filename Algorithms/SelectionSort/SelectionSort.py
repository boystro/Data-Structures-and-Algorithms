
def selection_sort(array):
    for i in range(len(array)):
        for j in range( i + 1, len(array) ):
            if ( array[i] > array[j] ):
                array[i], array[j] = array[j], array[i]
    return array


def main():
    array = [78, 98, 14, 25, 36, 69, 33, 21, 48, 57]
    print(array)
    selection_sort(array)
    print(array)

if ( __name__ == '__main__' ):
    main()