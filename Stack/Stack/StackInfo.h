#pragma once
#include"StackItem.h"
class Test;



class StackInfo
{
private:
    StackItem* stack[100] = {};
    //��һ��push������Ԫ�ش�ŵ�λ��
    int pos = 0;
public:
    template<typename T>
    void push(const T& val)
    {
        StackItem* item = new StackItem();
        T* ptr = new T();
        *ptr = val;
        item->Value = (void*)ptr;
        this->stack[pos] = item;
        pos++;
    }
    template<typename T>
    void pop(T& val)
    {
        this->pos--;
        T* ptr = (T*)this->stack[this->pos]->Value;
        val = *ptr;
    }
};
