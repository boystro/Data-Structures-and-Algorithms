#include <iostream>
#include <vector>
#include <array>

template<size_t Size>
struct Stack
{
private:
	std::array<int, Size> stack;
	size_t top;
	
public:
	Stack() : top(0)
	{
		stack.fill(0);
	}

	void push(int val)
	{
		if (top == Size) return;
		stack[top] = val;
		top++;
	}

	void pop()
	{
		if (top == 0) return;
		top--;
	}

	void log()
	{
		std::cout << "Stack: ";
		for (int i=top-1; i>=0; i--)
			std::cout << stack[i] << " ";
		std::cout << std::endl;
	}
};

int main()
{
	Stack<5> s;

	s.push(50);
	s.log();

	s.push(60);
	s.log();

	s.push(70);
	s.log();

	s.pop();
	s.log();

	s.pop();
	s.log();
}