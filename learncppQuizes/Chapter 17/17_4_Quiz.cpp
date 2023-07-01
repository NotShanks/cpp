#include <iostream>
#include <string>

/*
Create a Fruit base class that contains two private members: a name (std::string), and a color (std::string). 
Create an Apple class that inherits Fruit. Apple should have an additional private member: fiber (double). 
Create a Banana class that also inherits Fruit. Banana has no additional members.
*/

class Fruit
{
private: 
	std::string m_name{};
	std::string m_color{};

public:
	// Fruit(std::string_view, std::string_view)
	Fruit(const std::string name, const std::string color)
		: m_name{ name }, m_color{ color } {}

	// const std::string& getName() const { return m_name; }
	std::string_view getName() const { return m_name; }
	// const std::string& getColor() const { return m_color; }
	std::string_view getColor () const { return m_color; }
};

class Apple : public Fruit
{
private:
	double m_fiber{};

public:
	// Apple(std::string_view) to avoid copies
	Apple(std::string name, std::string color, double fiber)
		: Fruit{ name, color }, m_fiber{ fiber } {}

	// Overload operator<<
	// No need to use friend?
	friend std::ostream& operator<< (std::ostream& out, const Apple& a)
	{
		// Instead of a.m_fiber, can use a.getFiber() function
		out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.m_fiber << ")";

		return out;
	}

};

class Banana : Fruit
{

public:
	// Banana(std::string_view)
	Banana(const std::string name = "", std::string color = "")
		: Fruit{ name, color } {}

	// Overload operator<<
	friend std::ostream& operator<< (std::ostream& out, const Banana& b)
	{
		out << "Banana(" << b.getName() << ", " << b.getColor() << ")";

		return out;
	}
};

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
