class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class HashTable:
    def __init__(self):
        self.__size = 10;
        self.__table = tuple([[] for _ in range(self.__size)]);
    
    def hash(self, key: str):
        if type(key) != str:
            return;
        return len(key) % self.__size;

    def isEmpty(self):
        return self.getSize() == 0;

    def getSize(self):
        return sum([len(lst) for lst in self.__table]);

    def insert(self, key: str, value: int):
        hashValue = self.hash(key);
        lst = self.__table[hashValue];
        for pair in lst:
            if pair.key == key:
                pair.value = value;
                return;
        self.__table[hashValue].append(Pair(key, value))

    def remove(self, key: str):
        hashValue = self.hash(key);
        lst = self.__table[hashValue];
        for i, pair in enumerate(lst):
            if pair.key == key:
                lst.pop(i);
                return;
            


    def log(self):
        print("[HASH TABLE]");
        if (self.isEmpty()):
            print("Empty!!\n");
            return;
        for lst in self.__table:
            for pair in lst:
                print("{ " + str(pair.key) + ", " + str(pair.value) + " } ", end=", ");
            if len(lst) > 0:
                print();
        print();

def main():
    HT = HashTable();
    HT.log();

    HT.insert("Jim", 38);
    HT.insert("Vim", 68);
    HT.insert("Stink", 46);
    HT.insert("Rimf", 22);
    HT.insert("Rimf", 25);
    HT.log();

    HT.remove("Grock");
    HT.remove("Vim");
    HT.log();

if __name__ == '__main__':
    main();