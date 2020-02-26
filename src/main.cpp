#include <iostream>

#include <lib/stack.h>
#include <lib/list.h>

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

    List<int> lst;

    lst.AddTail(1);
    lst.AddTail(3);
    lst.AddTail(4);
    lst.AddTail(5);
    lst.AddTail(2);
    lst.AddTail(8);

    lst.PrintList();
    
    return 0;
}
