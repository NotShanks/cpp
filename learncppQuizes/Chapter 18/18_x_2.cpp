// Chapter 18 quiz last question.
#include <iostream>
#include <vector>

// Create an abstract class named Shape. This class should have three functions: 
// a pure virtual print function that takes and returns a std::ostream&, 
// an overloaded operator<< and an empty virtual destructor.

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<< (std::ostream& out, const Shape& s)
	{
		return s.print(out);
	}

	virtual ~Shape() = default;
};

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

// Derive two classes from Shape: a Triangle, and a Circle. 
// The Triangle should have 3 Points as members. 
// The Circle should have one center Point, and an integer radius.

class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle(Point p1, Point p2, Point p3)
		: m_p1{ p1 }, m_p2{ p2 }, m_p3{ p3 } {}

	std::ostream& Shape::print(std::ostream& out) const
	{
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";

		return out;
	}
};

class Circle : public Shape
{
private:
	Point m_centerPoint;
	int m_radius{};

public:
	Circle(Point cP, int radius)
		: m_centerPoint{ cP }, m_radius{ radius } {}

	std::ostream& Shape::print(std::ostream& out) const
	{
		out << "Circle(" << m_centerPoint << ", radius " << m_radius << ")";
			
		return out;
	}

	int getRadius() const
	{
		return m_radius;
	}
};

int getLargestRadius(const std::vector<Shape*>& shape)
{
	int largestRadius = 0;

	for (const Shape* shape : shape)
	{
		if (const Circle* circle = dynamic_cast<const Circle*>(shape))
		{
			int radius = circle->getRadius();
			if (radius > largestRadius)
				largestRadius = radius;
		}
	}
	return largestRadius;
}


int main()
{
	std::vector<Shape*> v{
		new Circle{ Point{ 1, 2 }, 7 },
			new Triangle{ Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 } },
			new Circle{ Point{ 7, 8 }, 3 }
	};

	// print each shape in vector v on its own line here

	for (const auto* element : v)
	{
		std::cout << *element << '\n';
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here

	for (Shape* i : v)
	{
		delete i;
	}

	return 0;
}
