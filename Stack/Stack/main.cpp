
#include <cassert>
#include"StackInfo.h"
#include "iostream"
using namespace std;
class Test
{
public:
    int p1 = 1;
    bool p2 = false;
    string p3 = "p33333333";

    void testWithStack(StackInfo& stack)
    {
        int v1 = 0;
        string v2;
        Test v3;
        Test* v4 = nullptr;

        stack.pop<Test*>(v4);
        stack.pop(v3);
        stack.pop(v2);
        stack.pop(v1);

        cout << "testWithStack "
            << v1 << " "
            << v2 << " "
            << v3.p3 << " "
            << v4->p3 << endl;

        stack.push(1);
    }
};

void test2()
{
    Test t1;
    StackInfo stack;
    stack.push(111);
    stack.push<string>("asdfaseaw");
    Test t2;
    t2.p3 = "t2teststring";
    stack.push(t2);
    stack.push(&t1);

    t1.testWithStack(stack);
    int ret = 0;
    stack.pop(ret);
    cout << "testWithStack ret " << ret <<endl;
}
int main()
{
    test2();
    return 0;
}