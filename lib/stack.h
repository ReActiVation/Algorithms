#include <cstdlib>
#include <iostream>

#ifndef H_STACK
#define H_STACK

template<typename T>
class Stack{
    private:
        T * array;
        int top;
        int capacity;
    public:
        Stack(int size);
        ~Stack();

        void push(T element);
        T pop();
        T peek();

        int size();
        bool isEmpty();
        bool isFull();
};

template<typename T>
Stack<T>::Stack(int size){
    array = new T[size];
    capacity = size;
    top = -1;
}

template<typename T>
Stack<T>::~Stack(){
    delete [] array;
    array = 0;
}

template<typename T>
void Stack<T>::push(T element){
    if(isFull()){
        std::cout<<"UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    array[++top] = element;
}

template<typename T>
T Stack<T>::pop(){
    if(isEmpty()){
        std::cout<<"UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);       
    }

    peek();

    return array[top--];
}

template<typename T>
T Stack<T>::peek(){
    if(!isEmpty()){
        return array[top];
    }else{
        exit(EXIT_FAILURE);
    }
}

template<typename T>
int Stack<T>::size(){
    return top + 1;
}

template<typename T>
bool Stack<T>::isEmpty(){
    return top == -1;
}

template<typename T>
bool Stack<T>::isFull(){
    return top == capacity - 1;
}

#endif