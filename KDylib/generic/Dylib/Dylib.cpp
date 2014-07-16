#ifdef __cplusplus

#include <iostream>

#endif

int foo;

extern "C" void	initFoo()
{
	foo = 0;
	std::cout << "foo = " << foo << std::endl;
}

extern "C" void	addOne()
{
	foo += 1;
	std::cout << "foo = " << foo << std::endl;
}

extern "C" void	minusOne()
{
	foo -= 1;
	std::cout << "foo = " << foo << std::endl;
}

extern "C" void addTen()
{
	foo += 10;
	std::cout << "foo = " << foo << std::endl;
}

extern "C" int *getFoo()
{
	return (&foo);
}