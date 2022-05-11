#ifndef Triangle_h 
#define Triangle_h

class Triangle
{
	int a, b, c;
public:
	Triangle(int a = 0, int b = 0, int c = 0);
	double perimetr();
	double area();
};

Triangle::Triangle(int a, int b, int c): a(a), b(b), c(c) {

}

double Triangle::perimetr() {
	return a + b + c;
}

double Triangle::area() {
	double p;
	p = perimetr() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
#endif 
