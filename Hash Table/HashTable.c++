#include <iostream>
#include <string>
#include <array>
#include <list>

struct HashTable
{
private:
	const int size = 50;
	std::array<std::list<std::pair<std::string, int>>, 50> table;

public:
	bool isEmpty() const
	{
		bool r = true;
		for (std::list<std::pair<std::string, int>> el : table)
			if (el.size() != 0)
				r = false;
		return r;
	}

	int hash(std::string key) const
	{
		return key.size() % size;
	}

	int getSize() const
	{
		int sum=0;
		for (std::list<std::pair<std::string, int>> el : table)
			sum += el.size();
		return sum;
	}

	void input(std::string key, int value)
	{
		int hashValue = hash(key);
		std::list<std::pair<std::string, int>>& lst = table[hashValue];
		bool isKeyPresent = false;
		for (std::pair<std::string, int>& el : lst)
		{
			if (el.first == key)
			{
				el.second = value;
				isKeyPresent = true;
			}
		}
		if (!isKeyPresent)
			lst.emplace_front(key, value);
	}

	void remove(std::string key)
	{
		if (isEmpty()) return;
		int hashValue = hash(key);
		std::list<std::pair<std::string, int>>& lst = table[hashValue];
		bool isKeyPresent = false;
		for (auto itr = lst.begin(); itr != lst.end(); itr ++)
		{
			if (itr->first == key)
			{
				isKeyPresent = true;
				itr = lst.erase(itr);
			}
		}
	}

	void log() const
	{
		std::cout << "[HASH TABLE]" << std::endl;
		if (isEmpty())
		{
			std::cout << "Empty Table!!\n" << std::endl;
			return;
		}
		for (std::list<std::pair<std::string, int>> lst : table)
		{
			for (std::pair<std::string, int> el : lst)
			{
				std::cout << "{ " << el.first << " : " << el.second << " } ";
			}
			if (!lst.empty()) std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};

int main()
{
	HashTable HT;

	HT.log();

	HT.input("Jim", 38);
	HT.input("Vim", 68);
	HT.input("Stink", 46);
	HT.input("Rimf", 22);
	HT.input("Rimf", 25);

	HT.log();

	HT.remove("Grock");
	HT.remove("Vim");

	HT.log();
}