#include <iostream>
#include <array>

template<unsigned int Size>
struct Queue
{
private:
	std::array<int, Size> queue;
	int front, rear;

public:
	Queue()
	{
		front = rear = -1;
		queue.fill(0);
	}

	void enqueue(int value)
	{
		if (isFull()) return;
		if (front == -1)
		{
			rear = ++front;
			queue[rear] = value;
			return;
		}
		rear++;
		if (rear >= Size) rear = 0;
		queue[rear] = value;
	}

	void dequeue()
	{
		if (isEmpty()) return;
		front++;
		if (front >= Size)
			front = 0;
		if (front - 1 == rear)
			front = rear = -1;
	}

	void log()
	{
		if (isEmpty())
			return;

		int temp = front, count = getSize();
		while (count)
		{
			std::cout << queue[temp] << (count == 0 ? "" : ", ");
			temp++;
			if (temp >= Size)
				temp = 0;
			count--;
		}
		std::cout << std::endl;
	}

	bool isFull() const
	{
		if (front == 0 && rear == Size - 1) return true;
		if (front - 1 == rear) return true;
		return false;
	}

	bool isEmpty() const
	{
		if (front == rear == -1) return true;
		return false;
	}

	int getSize() const
	{
        if (isEmpty()) return 0;
		int count = 0;
		if (front > rear)
			count = rear - front + 1 + Size;
		else if (front < rear)
			count = rear - front + 1;
		else
			count = 1;
		return count;
	}
};

int main()
{
	Queue<5> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.log();

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.log();

	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
    q.log();
}