
// figure3.cpp : 
//nazaroveg@yandex.ru

#include <iostream>
#include <string>


class figure
{
public:
	figure(const int _sides_count = 0, std::string _name = "Фигура") : sides_count(_sides_count), name(_name) { }


	virtual void print_info() const
	{
		std::cout << std::endl;
		std::cout << name << std::endl;
		std::cout << (ckeck() ? "Правильная" : "Неправильная") << std::endl;
		std::cout << "число сторон: " << sides_count << std::endl;

	}
	virtual bool ckeck() const
	{
		return sides_count == 0;
	}


private:

protected:
	std::string name = { };
	int sides_count = 0;

};


//////////////////////////////////////////////////////////////////////////////////////////


class triangle : public figure //треугольник
{
public:
	triangle( int A, int B, int C, int a, int b, int c, std::string name = "Треугольник") : figure(3, name), corner_a(A), corner_b(B), corner_c(C), Length_a(a), Length_b(b), Length_c(c) {}

	void print_info() const override
	{

		figure::print_info();
		std::cout << "Стороны: " << "a=" << Length_a << " " << "b=" << Length_b << " " << "c=" << Length_c << " " << std::endl;
		std::cout << "Углы: " << "A=" << corner_a << " " << "B=" << corner_b << " " << "C=" << corner_c << "\n" << std::endl;
	}
	 bool ckeck() const override
	{
		return sides_count == 3 && (corner_a + corner_b + corner_c ==180);
	}

private:

protected:
	int corner_a = 0, corner_b = 0, corner_c = 0;
	int Length_a = 0, Length_b = 0, Length_c = 0;

};

class Right_triangle : public triangle  // прямоугольный треугольник  один 90 гр
{
public:
	Right_triangle(const int A, int B, int a, int b, int c) : triangle(A, B, 90, a, b, c, "Прямоугольный треугольник") { } 

private:

protected:

};
class Isosceles_triangle : public triangle  //Равнобедренный треугольник 2 ст =
{
public:
	Isosceles_triangle(const int A, int B, int a, int b) : triangle(A, B, A, a, b, a, "Равнобедренный треугольник") {} 


private:

protected:

};
class Equilateral_triangle : public triangle //Равносторонний треугольник  всё равно
{
public:
	Equilateral_triangle(const int A, int a) : triangle(A, A, A, a, a, a, "Равносторонний треугольник") {  }




private:

protected:

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Quadrilateral : public figure  //Четырёхугольник  все !=
{
public:

	Quadrilateral(const int A, int B, int C, int D, int a, int b, int c, int d, std::string name = "Четырёхугольник") :
		figure(4, name), corner_a(A), corner_b(B), corner_c(C), corner_d(D),
		Length_a(a), Length_b(b), Length_c(c), Length_d(d) {}


	void print_info() const
	{
		figure::print_info();
		std::cout << "Стороны: " << "a=" << Length_a << " " << "b=" << Length_b << " " << "c=" << Length_c << " " << "d=" << Length_d << std::endl;
		std::cout << "Углы: " << "A=" << corner_a << " " << "B=" << corner_b << " " << "C=" << corner_c << " " << "D=" << corner_d << "\n" << std::endl;
	}
	bool ckeck() const override
	{
		return sides_count == 4 && (corner_a + corner_b + corner_c + corner_d == 360);
	}


private:

protected:
	int corner_a = 0, corner_b = 0, corner_c = 0, corner_d = 0;
	int Length_a = 0, Length_b = 0, Length_c = 0, Length_d = 0;
};




class Parallelogram : public Quadrilateral //Параллелограмм четугол попарно равны кривой от 4 уол
{
public:

	Parallelogram(const int A, int B, int a, int b, std::string name = "Параллелограмм:") : Quadrilateral(A, B, A, B, a, b, a, b, name) {}


private:

protected:

};
class Rectangle : public Parallelogram //Прямоугольник  углы равны
{
public:
	Rectangle(const int a, int b, std::string name = "Прямоугольник:") :Parallelogram(90, 90, a, b, name) { }



private:

protected:

};

class Square : public Rectangle  //Квадрат  рано всё
{
public:
	Square(const int a, std::string name = "Квадрат:") : Rectangle(a, a, name) {}


private:

protected:

};


class Rhombus : public Parallelogram //Ромб   пар все стороны равны
{
public:
	Rhombus(const int A, int B, int a) : Parallelogram(A, B, a, a, "Ромб:") {}



private:

protected:

};






int main()
{
	setlocale(LC_ALL, "RUS");
	figure fi{};
	triangle tr{ 50,60,70,10,20,30 };
	Right_triangle Rt{ 50, 60, 10, 20, 30 };
	Isosceles_triangle It{ 50, 60, 10, 20 };
	Equilateral_triangle Et{ 60,30 };
	Quadrilateral Ql{ 50,60,70,80,10,20,30,40 };
	Parallelogram Pl{ 30, 40, 20, 30 };
	Rectangle Re{ 20,30 };
	Rhombus Rh{ 30,40,30 };
	Square Sq{ 20 };



	fi.print_info();
	tr.print_info();
	Rt.print_info();
	It.print_info();
	Et.print_info();
	Ql.print_info();
	Pl.print_info();
	Re.print_info();
	Sq.print_info();
	Rh.print_info();

	return 0;
}
