#include <iostream>

#include <lib/stack.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Stack<int> s(3);

    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    s.pop();

    s.push(3);

    cout<<"Top element is: "<< s.peek() << endl;
    cout<<"Stack size is "<< s.size() << endl;

    s.pop();

    if(s.isEmpty()){
        cout<<"Stack is empty!"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}
