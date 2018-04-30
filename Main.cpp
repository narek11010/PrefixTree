#include <iostream>
#include <vector>
#include "PrefixTreer.h"

int main()
{
	PrefixTree test;
	test.insert("abcdez", 1);
	test.insert("a", 2);
	test.insert("ab", 3);
	test.insert("abc", 4);
	test.insert("abcd", 5);
	test.insert("abcd", 6);
	test.insert("abcdez", 7);
	test.insert("z", 8);

	if (test.find("abcdez") == nullptr) { std::cout << "no abcdez" << '\n'; }
	if (test.find("a")   == nullptr) { std::cout << "no a" << '\n'; }
	if (test.find("ab")   == nullptr) { std::cout << "no ab" << '\n'; }
	if (test.find("aaa")   == nullptr) { std::cout << "no aaa" << '\n'; }
	if (test.find("abcde")   == nullptr) { std::cout << "no abcde" << '\n'; }
	if (test.find("qq")   == nullptr) { std::cout << "no qq" << '\n'; }
	if (test.find("wqswq")   == nullptr) { std::cout << "no wqswq" << '\n'; }
	if (test.find("z") == nullptr) { std::cout << "no z" << '\n'; }
	if (test.find("abcdeza")   == nullptr) { std::cout << "no abcdeza" << '\n'; }
	if (test.find("abcdeza") == nullptr) { std::cout << "no abcdeza" << '\n'; }

	PrefixTree t = test;
	return 0;
}