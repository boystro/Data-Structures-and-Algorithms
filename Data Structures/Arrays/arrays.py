
class Array:
    def __init__(self: object, *args, length=None) -> None:
        self.len = length or len(args)
        self.__arr = list(args)

    def __getitem__(self: object, key: int):
        return self.__arr[key]

    def __setitem__(self: object, key: int, val):
        self.__arr[key] = val

    def __str__(self: object) -> str:
        string = "[ "
        for i in self.__arr:
            string += str(i) + ", "
        return string + " ]"

my_arr = Array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
my_arr[2] = 99
print(my_arr)