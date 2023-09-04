#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // cout << "hello" << endl;

    /* step - 1 is the creation of stack */
    stack<int> s;

    /* step - 2 is to insert something in stack */
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    /* step - 3 is to pop something from stack */
    s.pop();

    /* step - 4 is to print something on top of stack */
    cout << s.top() << endl;

    cout << s.empty() << endl;

    cout << s.size() << endl;
}