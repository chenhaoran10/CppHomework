#pragma once
template<typename DataType>
class iterator {
private:
	DataType* ptr;
public:
	iterator(DataType* ptr):
		ptr(ptr){}

	iterator& operator++()
	{
		//overload ++it;
		ptr++;
		return *this;
	}

	iterator& operator++(int)
	{
		//overload it++;
		ptr++;
		return *this;
	}

	iterator& operator--()
	{
		//overload --it;
		ptr--;
		return *this;
	}

	iterator& operator--(int)
	{
		//overload it--;
		ptr--;
		return *this;
	}

	bool operator!=(const iterator& other)const
	{
		return (ptr != other.ptr);
	}

	const DataType& operator*()const
	{
		return *ptr;
	}
};

template<typename DataType>
class Array
{
private:
	int len;
	int size;
	DataType* val;
public:
	//类似于typedef,把后面的简写成=前的
	using iterator = iterator<DataType>;

	Array():len(0),size(0),val(nullptr){}
	Array(int _size)
	{
		len = _size;
		size = (_size) * 1.5;
		val = new DataType[size];
	}
	Array(const Array<DataType>& src)
	{
		len = src.len;
		size = len * 1.5;
		this->val = new DataType[size];
		for (int i = 0; i < len; i++)
		{
			val[i] = src[i];
		}
	}
	~Array()
	{
		delete[]val;
		val = nullptr;
		len = 0;
		size = 0;
	}
	iterator begin()const
	{
		return iterator(val);
	}

	iterator end()const
	{
		return iterator(val + len);
	}
	DataType& operator[](const int index)
	{
		return val[index];
	}
	void reserve(const int& _size)
	{
		if (_size > size)
		{
			size = _size;
			DataType* temp = new DataType[size];
			for (int i = 0; i < len; i++)
			{
				temp[i] = val[i];
			}
			delete[]val;
			val = temp;
		}
	}
	void push(const DataType& num)
	{
		if (size == 0)
		{
			size = 1;
			val = new DataType[1];
		}else if(len+1>size){
			size = 2 * size;
			DataType* tmp = new DataType[size];
			for (int i = 0; i < len; i++)
			{
				tmp[i] = val[i];
			}
			delete[]val;
			val = tmp;
		}
		len++;
		val[len] = num;
	}

	void insert(const int& index, const DataType& data)
	{
		if ((index >= 0) && (index < len + 1))
		{
			for (int i=len;i>index;i--)
			{
				val[i] = val[i-1];
			}
			len++;
			val[index] = data;
		}
		else
		{

		}
	}
	void remove(const DataType& data)
	{
		bool flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (val[i] == data)
			{
				for (int j = i; j < len-1; j++)
				{
					val[j] = val[j + 1];
					i--;
				}
			}
		}
	}
	DataType pop()
	{
		if (len > 0)
		{
			len--;
			return val[len];
		}

	}

	void clear()
	{
		delete[]val;
		len = 0;
	}
	int findIndex(const int& data)const
	{
		for (int i = 0; i < len; i++)
		{
			if (val[i] == data)
			{
				return i;
			}
		}
	}
};




















