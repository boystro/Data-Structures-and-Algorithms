class ListNode:
    def __init__(self, Data, Prev, Next):
        self.data = Data;
        self.prev = Prev;
        self.next = Next;

class LinkedList:
    def __init__(self, data=None):
        self.head = self.end = ListNode(data, None, None) if data else None

    def pushBack(self, val):
        if (self.head == None):
            self.head.data = val
            return
        temp = self.head
        while temp.next!=None:
            temp = temp.next
        temp.next = ListNode(val, temp, None)

    def pushFront(self, val):
        if (self.head == None):
            self.head.data = val
            return
        self.head.prev = ListNode(val, None, self.head)
        self.head = self.head.prev

    def removeFront(self):
        self.head = self.head.next

    def removeEnd(self):
        temp = self.head
        while temp.next!=None:
            temp = temp.next
        temp.prev.next = None

    def log(self):
        temp = self.head
        print("Linked List: ", end="")
        while temp!=None:
            print(temp.data, end="" if temp.next==None else ", ")
            temp = temp.next
        print()

def main():
    lst = LinkedList(45)
    lst.pushBack(55)
    lst.pushBack(65)
    lst.pushFront(25)
    lst.pushFront(15)
    lst.log()

    lst.removeFront()
    lst.removeEnd()
    lst.removeEnd()
    lst.removeEnd()
    lst.log()

    lst.pushFront(15)
    lst.pushFront(5)
    lst.log()

    lst.removeEnd()
    lst.removeEnd()
    lst.log()

if __name__ == "__main__":
    main()