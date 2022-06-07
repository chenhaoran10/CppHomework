#pragma once
#include<iostream>
#include<ostream>
#include<vector>
class String
{
private:
	unsigned int m_length;
	char* m_string;
public:
	String();
	String(char _char);
	String(const char* _string);
	//£¿
	String(const String& _string);
	String(const char* _string1, const char* _string2);
	String(String&& _string)noexcept;
	~String();

	void reset();
	//unsigned int
	size_t length()const;
	char* asCString()const;

	//Cast to const char??
	operator const char* ()const;

	operator bool() const;
	//Bracket Operator overloads
	char operator[](int _index)const;
	char& operator[](int _index);

	//Compare
	bool operator==(const String& _other)const;
	bool operator==(const char* _chars)const;

	//copy assignment operator
	String& operator=(const String& _other);

	//Move Assignment operator
	String& operator=(String&& _other)noexcept;

	//add operators
	String& operator+=(const String& _other);
	String& operator+=(const char* _other);
	String operator+(const String& _other)const;
	String operator+(const char* _other)const;

	//Stream Operator???
	friend std::ostream& operator<<(std::ostream& _os, const String& _string);
	//????
	std::vector<String> split(const char _delimiter);
	void replace(const char _target, const char _replacement);
	void removeCharacter(char _target);
	String toLowerCase()const;
	String sub(int startIndex, int endIndex);
	String& append(const char* _char);
	int find(const char* _char);


};

