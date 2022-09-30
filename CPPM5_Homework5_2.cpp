#include <iostream>

class Figure
{
public:
	Figure()
	{
		_name = "Фигура";
	}

	std::string& getName()
	{
		return _name;
	}

	unsigned int getSideCount()
	{
		return _sideCount;
	}

	void printString()
	{
		std::cout << getName() << std::endl;
		printSideInfo();
		printAngleInfo();
		std::cout << std::endl;
	}

protected:
	std::string _name;
	unsigned int _sideCount = 0;

	virtual void printSideInfo()
	{

	}

	virtual void printAngleInfo()
	{

	}
};

class Triangle : public Figure
{
public:
	Triangle(double a, double b, double c, double A, double B, double C)
	{
		_a = a;
		_b = b;
		_c = c;
		_A = A;
		_B = B;
		_C = C;
		_name = "Треугольник";
		_sideCount = 3;
	}

	double geta()
	{
		return _a;
	}

	double getb()
	{
		return _b;
	}

	double getc()
	{
		return _c;
	}

	double getA()
	{
		return _A;
	}

	double getB()
	{
		return _B;
	}

	double getC()
	{
		return _C;
	}
protected:
	void printSideInfo() override
	{
		std::cout << "Стороны: ";
		std::cout << "a = " << geta() << ", ";
		std::cout << "b = " << getb() << ", ";
		std::cout << "c = " << getc() << std::endl;
	}

	void printAngleInfo()
	{
		std::cout << "Углы: ";
		std::cout << "A = " << getA() << ", ";
		std::cout << "B = " << getB() << ", ";
		std::cout << "C = " << getC() << std::endl;
	}

private:
	double _a, _b, _c, _A, _B, _C;
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
	{
		_name = "Прямоугольный треугольник";
	}
};

class IsoScelesTriangle : public Triangle
{
public:
	IsoScelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
	{
		_name = "Равнобедренный треугольник";
	}
};

class EquilateralTriangle : public IsoScelesTriangle
{
public:
	EquilateralTriangle(double a) : IsoScelesTriangle(a, a, 60, 60)
	{
		_name = "Равносторонний треугольник";
	}
};

// четырехугольник не наследуется от треугольника
class Quadrangle : public Figure
{
public:
	Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
	{
		_a = a;
		_b = b;
		_c = c;
		_d = d;
		_A = A;
		_B = B;
		_C = C;
		_D = D;
		_name = "Четырехугольник";
		_sideCount = 4;
	}

	double geta()
	{
		return _a;
	}

	double getb()
	{
		return _b;
	}

	double getc()
	{
		return _c;
	}

	double getd()
	{
		return _d;
	}

	double getA()
	{
		return _A;
	}

	double getB()
	{
		return _B;
	}

	double getC()
	{
		return _C;
	}

	double getD()
	{
		return _D;
	}

protected:
	virtual void printSideInfo()
	{
		std::cout << "Стороны: ";
		std::cout << "a = " << geta() << ", ";
		std::cout << "b = " << getb() << ", ";
		std::cout << "c = " << getc() << ", ";
		std::cout << "d = " << getd() << std::endl;
	}

	virtual void printAngleInfo()
	{
		std::cout << "Углы: ";
		std::cout << "A = " << getA() << ", ";
		std::cout << "B = " << getB() << ", ";
		std::cout << "C = " << getC() << ", ";
		std::cout << "D = " << getD() << std::endl;
	}

private:
	double _a, _b, _c, _d, _A, _B, _C, _D;
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		_name = "Паралелограмм";
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
	{
		_name = "Прямоугольник";
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double a, double A, double B) : Parallelogram(a, a, A, B)
	{
		_name = "Ромб";
	}
};

class Square : public Rectangle
{
public:
	Square(double a) : Rectangle(a, a)
	{
		_name = "Квадрат";
	}
};

namespace FigureUtils
{
	void printInfo(Figure* figure)
	{
		figure->printString();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Triangle triangle(10, 20, 30, 50, 60, 70);
	RightTriangle rightTriangle(10, 20, 30, 50, 60);
	IsoScelesTriangle isoScelesTriangle(10, 20, 50, 60);
	EquilateralTriangle equilateralTriangle(30);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhombus rhombus(30, 30, 40);

	FigureUtils::printInfo(&triangle);
	FigureUtils::printInfo(&rightTriangle);
	FigureUtils::printInfo(&isoScelesTriangle);
	FigureUtils::printInfo(&equilateralTriangle);
	FigureUtils::printInfo(&quadrangle);
	FigureUtils::printInfo(&rectangle);
	FigureUtils::printInfo(&square);
	FigureUtils::printInfo(&parallelogram);
	FigureUtils::printInfo(&rhombus);

}
