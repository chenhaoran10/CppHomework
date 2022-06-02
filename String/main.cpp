#include "String.h"
#include <iostream>
#include <ostream>
int main() {

	//String temp = String();
	//try
	//{
	//temp[5];
	//}
	//catch (const std::exception&)
	//{
	//	std::cout << "abcdef" << std::endl;

	//}
	auto str1 = String("test1");
	auto str2 = String("test2,test3");
	str1 = "test3";
	int len = str1.length();
	String str3=str1.sub(1, 2);
	std::cout << str1 << std::endl;
	std::cout << str3 << std::endl;
	str1.append("hello");
	std::cout << str1 << std::endl;
	bool equal = (str1 == str2);
	std::cout << equal << std::endl;
	int index = str1.find("es");
	std::cout << index << std::endl;
	std::vector<String> res = str2.split(',');
	return 0;
}