#include <iostream>

#include <lib/stack.h>
#include <lib/list.h>
#include <lib/binary_tree.h>

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

    BinaryTree<int> *binTree = new BinaryTree<int>();

    binTree->insert_node(10);
    binTree->insert_node(6);
    binTree->insert_node(14);
    binTree->insert_node(5);
    binTree->insert_node(8);
    binTree->insert_node(11);
    binTree->insert_node(18);
    
    binTree->pre_order_print();
    binTree->in_order_print();
    binTree->post_order_print();
    
    return 0;
}
