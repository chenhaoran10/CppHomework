#include "String.h"

String::String():m_length(0),m_string()
{
	m_string = new char[1];
	m_string[0] = '\0';
	//串结束符,空构造函数
}

String::String(char _char):m_length(1)
{
	m_string = new char[2];
	m_string[0] = _char;
	m_string[1] = '\0';
}

String::String(const char* _string)
{
	if (!_string)
	{
		m_length = 0;
		//?
		m_string = new char[0];
	}
	else
	{
		m_length = strlen(_string);
		m_string = new char[m_length + 1];
		//copy参数
		std::copy(_string, _string + m_length, m_string);
		m_string[m_length] = '\0';
	}
}

String::String(const String& _string)
{
	//?
	char* buffer = new char[_string.m_length + 1];
	std::copy(_string.m_string, _string.m_string + _string.m_length, buffer);
	buffer[_string.m_length] = '\0';

	m_string = buffer;
	m_length = _string.m_length;
}

String::String(String&& _string) noexcept
{
//右值,不抛出异常
	const auto buffer = _string.m_string;
	m_length = _string.m_length;
	m_string = buffer;
	_string.reset();
}
String::String(const char* _string1, const char* _string2)
{
	m_length = strlen(_string1) +strlen(_string2);
	m_string = new char[m_length + 1];
	//copy参数
	for (int i = 0; i < strlen(_string1); i++)
	{
		m_string[i] = _string1[i];
	}
	for (int i = strlen(_string1); i < m_length; i++)
	{
		m_string[i] = _string2[i- strlen(_string1)];
	}
	m_string[m_length] = '\0';
}



String::~String()
{
	delete[] m_string;
	m_string = nullptr;
}

void String::reset()
{
	m_length = 0;
	m_string = nullptr;
}

size_t String::length() const
{
	//?
	return m_length;
}

char* String::asCString() const
{
	//C lang string
	return m_string;
}

String::operator const char* () const
{
	//cast to (const char*)
	return m_string;
}

String::operator bool() const
{
	//cast to (bool)
	return m_length != 0;
}

char String::operator[](int _index) const
{
	//?
	if (_index < 0 || _index >= m_length)
	{
		throw std::out_of_range("String index out of bounds!");
	}
	return m_string[_index];
}
char& String::operator[](int _index)
{
	//return char&,改变了原来的值
	try
	{
		if (_index < 0 || _index >= m_length)
		{
			throw std::out_of_range("String index out of bounds!");
		}
	}
	catch (const std::exception&)
	{
		std::cout << "djfdsjaf" <<std::endl;
	}
	return m_string[_index];
}

bool String::operator==(const String& _other) const
{
	if (!_other.m_string)
		return false;
	return strcmp(m_string, _other.m_string) == 0;
}

bool String::operator==(const char* _chars) const
{
	if(!_chars)
		return false;
	return strcmp(m_string, _chars) == 0;
}

String& String::operator=(const String& _other)
{
	// TODO: insert return statement here
	//?
	if (this != &_other)
	{
		char* buffer = new char[_other.m_length + 1];
		std::copy(_other.m_string, _other.m_string + _other.m_length + 1, buffer);
		std::swap(buffer,m_string);
		m_length = _other.m_length;
		delete[] buffer;
	}
	//??
	return *this;
}

String& String::operator=(String&& _other) noexcept
{
	//??
	// TODO: insert return statement here
	if (this != &_other)
	{
		const auto buffer = _other.m_string;
		delete[] m_string;
		m_string = buffer;
		m_length = _other.m_length;
		_other.reset();
	}
	//?
	return *this;
}

String& String::operator+=(const String& _other)
{
	// TODO: insert return statement here
	//?
	if (this != &_other)
	{
		auto totalLength = m_length + _other.m_length;
		char* buffer = new char[totalLength + 1];
		std::copy(m_string, m_string + m_length, buffer);
		std::copy(_other.m_string, _other.m_string + _other.m_length, buffer+m_length);
		buffer[totalLength] = '\0';
		std::swap(m_string, buffer);
		m_length = totalLength;
		delete[] buffer;
	}
	return *this;
}

String& String::operator+=(const char* _other)
{
	// TODO: insert return statement here
	const auto charLength = strlen(_other);
	const auto totalLength = m_length + charLength;
	char* buffer = new char[totalLength + 1];
	std::copy(m_string,m_string+m_length,buffer);
	std::copy(_other,_other+charLength,buffer+m_length);
	buffer[totalLength] = '\0';

	std::swap(m_string, buffer);
	m_length = totalLength;

	delete[] buffer;

	return *this;
}

String String::operator+(const String& _other) const
{
	const auto totalLength = m_length + _other.m_length;
	char* buffer = new char[totalLength + 1];
	std::copy(m_string, m_string + m_length, buffer);
	std::copy(_other.m_string,_other.m_string + _other.m_length, buffer+m_length);
	return String(buffer);
}

String String::operator+(const char* _other) const
{
	const auto charLength = strlen(_other);
	const auto totalLength = m_length + charLength;
	char* buffer = new char[totalLength + 1];

	std::copy(m_string, m_string + m_length, buffer);
	std::copy(_other, _other+charLength, buffer+m_length);
	buffer[totalLength] = '\0';

	return String(buffer);
}

std::vector<String> String::split(const char _delimiter)
{
	//???
	std::vector<String> result;
	char* t;
	char* pch = strtok_s(m_string, &_delimiter,&t);
	while (pch != nullptr)
	{
		result.push_back(String{ pch });
		pch = strtok_s(nullptr, &_delimiter, &t);
	}
	return result;
}

void String::replace(const char _target, const char _replacement)
{
	//?
	for (int i = 0; i < m_length; i++)
	{
		if (m_string[i] == _target)
		{
			if (_replacement == 0)
			{
				removeCharacter(_target);
			}
			else
			{
				m_string[i] = _replacement;
			}
		}
	}
}

void String::removeCharacter(char _target)
{
	auto newEnd = std::remove(m_string, m_string + m_length, ' ');
	*newEnd = '\0';
}

String String::toLowerCase() const
{
	String buffer = *this;
	for (int i = 0; i < m_length; i++)
	{
		buffer[i] = tolower(buffer[i]);
	}
	return buffer;
}

String String::sub(int startIndex, int endIndex)
{
	char* buffer = new char[endIndex-startIndex + 1];
	//copy 左闭右开
	std::copy(m_string+ startIndex, m_string + endIndex, buffer);
	buffer[endIndex - startIndex] = '\0';
	return String(buffer);
}

String& String::append(const char* _char)
{
	const auto charLength = strlen(_char);
	const auto totalLength = m_length + charLength;
	char* buffer = new char[totalLength + 1];
	std::copy(m_string, m_string + m_length, buffer);
	std::copy(_char, _char + charLength, buffer + m_length);
	buffer[totalLength] = '\0';
	std::swap(m_string, buffer);
	m_length = totalLength;
	delete[] buffer;
	return *this;
}

int String::find(const char* _char)
{
	const auto charLength = strlen(_char);
	for (int i = 0; i < m_length; i++)
	{
		for (int j = 0; j < charLength; j++)
		{
			if (*(m_string +i+ j) == _char[j])
			{
				return i;
			}
		}
	}
	return -1;
}

std::ostream& operator<<(std::ostream& _os, const String& _string)
{
	// TODO: insert return statement here
	//?
	_os << _string.m_string;
	return _os;
}
