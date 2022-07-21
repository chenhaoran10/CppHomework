#pragma once
class StackItem
{
public:
    void* Value = nullptr;
    ~StackItem()
    {
        this->Value = nullptr;
    }

};