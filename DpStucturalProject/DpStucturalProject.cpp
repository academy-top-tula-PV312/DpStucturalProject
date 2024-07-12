#include <iostream>
#include "Examples.h"

#include "Proxy.h"

int main()
{
	MathProxy* mp = new MathProxy();
	std::cout << mp->add(10, 20) << "\n";
	std::cout << mp->mul(10, 20) << "\n";
}
