class Queue:
    def __init__(self, size=5):
        self.__size = size
        self.__queue = [0 for _ in range(self.__size)]
        self.__front = self.__rear = -1

    def isEmpty(self):
        return self.__front == self.__rear == -1

    def isFull(self):
        return (self.__front == 0 and self.__rear==self.__size-1) or (self.__front-1 == self.__rear)

    def getSize(self):
        if (self.isEmpty()):
            return 0
        if (self.__front > self.__rear):
            return self.__rear - self.__front + 1 + self.__size
        if (self.__front < self.__rear):
            return self.__rear - self.__front + 1
        return 1 

    def enqueue(self, value):
        if (self.isFull()):
            return

        if (self.isEmpty()):
            self.__front = self.__rear = 0
            self.__queue[self.__rear] = value
            return
        
        self.__rear += 1
        if (self.__rear >= self.__size):
            self.__rear = 0

        self.__queue[self.__rear] = value
    
    def dequeue(self):
        if (self.isEmpty()):
            return

        self.__front += 1
        if (self.__front >= self.__size):
            self.__front = 0

    def log(self):
        if (self.isEmpty()):
            return

        temp = self.__front
        count = self.getSize()
        while count:
            print(self.__queue[temp], end = " ")
            temp += 1
            if (temp >= self.__size):
                temp = 0
            count -= 1
        print()

def main():
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.log()

    q.dequeue()
    q.dequeue()
    q.dequeue()
    q.log()

    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.log()

if __name__ == '__main__':
    main()