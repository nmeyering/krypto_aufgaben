#include <iostream>
#include <ostream>

namespace
{
struct triplet
{
	int a, b, c;

	triplet(
		int _a,
		int _b,
		int _c)
	:
		a(_a),
		b(_b),
		c(_c)
	{}

	~triplet(){}
};

std::ostream &
operator<<(
	std::ostream &_os,
	triplet const &_triplet)
{
	return _os
		<< "("
		<< _triplet.a << ", "
		<< _triplet.b << ", "
		<< _triplet.c << ")";
}

int
gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		std::swap(a, b);
	}
	return a;
}

int
gcd_recursive(
	int a,
	int b)
{
	if (b == 0)
		return a;
	return gcd_recursive(b, a % b);
}

triplet
gcd_ext(int a, int b)
{
	if (a == 0)
		return triplet(b, 0, 1);

	if (b == 0)
		return triplet(a, 1 ,0);

	int x = 1, y = 0, u = 0, v = 1;
	while (b != 0)
	{
		int
			q = a / b,
			r = a % b,
			x1 = u,
			y1 = v;
		u = x - q * u;
		v = y - q * v;
		x = x1;
		y = y1;
		a = b;
		b = r;
	}
	return triplet(a, x, y);
}

triplet
gcd_ext_recursive(int a, int b)
{
	if (a == 0)
		return triplet(b, 0, 1);

	if (b == 0)
		return triplet(a, 1 ,0);

	triplet dxy(gcd_ext_recursive(b, a % b));
	return triplet(dxy.a, dxy.c, dxy.b - (a / b) * dxy.c);
}

}


int
main(
	int argc,
	char* argv[])
{
	int a, b;
	std::cout << "a? ";
	std::cin >> a;
	std::cout << "b? ";
	std::cin >> b;
	std::cout << "ggT(" << a << ", " << b << ") (EA)      : " << gcd(a, b) << std::endl;
	std::cout << "ggT(" << a << ", " << b << ") (rekursiv): " << gcd_recursive(a, b) << std::endl;
	std::cout << "ggT(" << a << ", " << b << ") (EEA)     : " << gcd_ext(a, b) << std::endl;
	std::cout << "ggT(" << a << ", " << b << ") (rekursiv): " << gcd_ext_recursive(a, b) << std::endl;
}
