#include <iostream>

template <typename ... T>
auto calmean(T ... ts) {
	return (ts + ...)/sizeof...(ts);
}


int main() {
	std::cout << calmean(5,5,15,15,5,5) << std::endl;



}