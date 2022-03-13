class Stack:
    def __init__(self, size):
        self.__size = size
        self.__stack = [0 for _ in range(size)]
        self.__top = 0
    
    def push(self, value):
        if self.__top == self.__size:
            return;
        self.__stack[self.__top] = value
        self.__top += 1

    def pop(self):
        self.__top -= 1
        return self.__stack[self.__top]

    def log(self):
        print("Stack: ", end="")
        for i in range(self.__top):
            print(self.__stack[self.__top - i - 1], end=" ")
        print()
    
def main():
    s = Stack(5)

    s.push(50)
    s.log()

    s.push(70)
    s.log()

    s.push(90)
    s.log()

    s.pop()
    s.log()

    s.pop()
    s.log()

if __name__ == '__main__':
    main()