#include "String.h"
#include <iostream>
#include <ostream>
int main() {
	auto str1 = String("test1");
	auto str2 = String("test2,test3");
	str1 = "test3";
	int len = str1.length();
	String str3=str1.sub(1, 2);
	str1.append("hello");
	bool equal = (str1 == str2);
	int index = str1.find("es");
	String* ans = str2.split(",");
	return 0;
}