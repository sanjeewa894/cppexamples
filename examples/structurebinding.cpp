#include <iostream>
#include <map>
#include <string>

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value>& m, F foo) {
	for (auto& pair : m)
		pair.second = foo(pair.first);
}


void testStructBind() {
	std::map<std::string, long long int> m{
		{"a",1},
		{"b",2},
		{"c",3}
	};

	update(m, [](std::string key) {
		return std::hash<std::string>{}(key);
		});

	for (auto&& [key, value] : m)
		std::cout << key << ":" << value << std::endl;
}