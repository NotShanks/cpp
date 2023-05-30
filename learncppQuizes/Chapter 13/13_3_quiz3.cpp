#include <iostream>
#include <array>
#include <cassert>
/*
A private array of integers of length 10.
A private integer to keep track of the size of the stack.
A public member function named reset() that sets the size to 0.
A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
A public member function named print() that prints all the values in the stack.
*/

class Stack
{
private:
	std::array<int, 10> m_arr{};
	std::array<int, 10>::size_type m_size{ 0 };

public: 
	void reset()
	{
		m_size = 0;
	}

	bool push(int x)
	{
		if (m_size == m_arr.size())
		{
			return false;
		}
		this->m_arr[m_size++] = x;
	}

	int pop()
	{
		assert(m_size > 0 && "Empty stack.");

		return this->m_arr[m_size--];
	}

	void print()
	{
		std::cout << "( ";
		for (std::array<int, 10>::size_type i{ 0 }; i < m_size; ++i)
			std::cout << m_arr[i] << ' ';
			std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
