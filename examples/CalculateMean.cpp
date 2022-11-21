#include <iostream>

/*
* Function to calculate mean using Fold Expression
*/
template <typename ... T>
auto calmean(T ... ts) {
	return (ts + ...)/sizeof...(ts);
}


void testMean() {
	std::cout << calmean(5,5,15,15,5,5) << std::endl;
}