#pragma once
class Test;
class StackInfo
{
private:
    void* stack[100] = {};
    int pos = 0;
public:
    template<typename T>
    void push(const T& val)
    {
        stack[pos++] = (void*)&val;    
    }
    template<typename T>
    void pop(T& val)
    {
         val=*(T*)(stack[--pos]);
    }
};
