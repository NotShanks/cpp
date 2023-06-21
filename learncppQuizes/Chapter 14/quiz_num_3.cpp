#include <iostream>
#include <cassert>
/*
Write your own integer array class named IntArray from scratch (do not use std::array or std::vector).
Users should pass in the size of the array when it is created, and the array should be dynamically allocated. 
Use assert statements to guard against bad data. 
Create any constructors or overloaded operators needed to make the following program operate correctly:
*/

class IntArray
{
private:
	int m_size;
	int* m_array;

public:
	IntArray(int size) : m_size{ size } { assert(size > 0);  m_array = new int[m_size]; }

	IntArray(const IntArray& arr) : m_size{ arr.m_size }
	{
		m_array = new int[m_size];
		for (int i{ 0 }; i < m_size; ++i)
		{
			m_array[i] = arr.m_array[i];
		}
	}

	~IntArray() { delete[] m_array; }

	friend std::ostream& operator<< (std::ostream& out, const IntArray& arr)
	{
		for (int i{ 0 }; i < arr.m_size; ++i)
		{
			out << arr.m_array[i] << ' ';
		}
		return out;
	}

	int& operator[](int index)
	{
		assert(index > 0 && index < m_size);
		return m_array[index];
	}

	IntArray& operator= (const IntArray& arr)
	{
		if (this == &arr)
			return *this;
		
		delete[] m_array;
		m_size = arr.m_size;
		m_array = new int[m_size];

		for (int i{ 0 }; i < m_size; ++i)
		{
			m_array[i] = arr.m_array[i];
		}
		return *this;
	}
};

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}
