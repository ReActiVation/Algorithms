#ifndef H_LIST
#define H_LIST
#include <iostream>
#include <cstdlib>

template<typename T>
struct Node
{
    Node *previous, *next;
    T data;
};

template<typename T>
class List
{
    private:
        Node<T> * Head, * Tail;
        int Size;
    
    public:
        List();
        List(const List<T>&);
        ~List();

        int GetSize();
        Node<T> * GetElement(int);

        void DeleteList();

        void DeleteElement(int position);

        void AddElement(int position, T data);

        void AddTail(T data);

        void AddHead(T data);

        void PrintList();

        void PrintElement(int position);

        List<T>& operator = (const List<T>&);

        List<T> operator + (const List<T>&);

        bool operator == (const List<T>&);
        bool operator != (const List<T>&);
        bool operator <= (const List<T>&);
        bool operator >= (const List<T>&);
        bool operator < (const List<T>&);
        bool operator > (const List<T>&);

        List<T> operator - ();
};

template<typename T>
List<T>::List()
{
    Head = Tail = NULL;
    Size = 0;
}

template<typename T>
List<T>::List(const List<T>& LST)
{
    Head = Tail = NULL;
    Size = 0;

    Node<T> * elementToCopy = LST.Head;

    while(elementToCopy != 0)
    {
        AddTail(elementToCopy->data);
        elementToCopy = elementToCopy->next;
    }
}

template<typename T>
List<T>::~List()
{
    DeleteList();
}

template<typename T>
void List<T>::AddHead(T data)
{
    Node<T> * newElement = new Node<T>;

    newElement->previous = 0;
    newElement->data = data;
    newElement->next = Head;

    if(Head != 0)
    {
        Head->previous = newElement;
    }

    if(Size = 0)
    {
        Head = Tail = newElement;
    }else
    {
        Head = newElement;
    }

    Size++;
}

template<typename T>
void List<T>::AddTail(T data)
{
    Node<T> * newELement = new Node<T>;

    newELement->next = 0;
    newELement->data = data;
    newELement->previous = Tail;

    if(Tail != 0)
    {
        Tail->next = newELement;
    }

    if(Size == 0)
    {
        Head = Tail = newELement;
    }else
    {
        Tail = newELement;
    }

    Size++;
}

template<typename T>
void List<T>::AddElement(int position, T data)
{
    if(position <= 0 || position > Size + 1)
    {
        std::cout<<"Out of range!"<<std::endl;
        exit(EXIT_FAILURE);
    }

    if(position == Size + 1)
    {
        AddTail(data);
        return;
    }else if(position == 1)
    {
        AddHead(data);
        return;
    }

    int counter = 0;

    Node<T> * InsertBefore = Head;

    while(counter < position)
    {
        InsertBefore = InsertBefore->next;
        counter++;
    }

    Node<T> * InsertAfter = InsertBefore->previous;

    Node<T> * newElement = new Node<T>;

    newElement->data = data;

    if(InsertAfter != 0 && Size != 1)
    {
        InsertAfter->next = newElement;
    }

    newElement->next = InsertBefore;
    newElement->previous = InsertAfter;
    InsertBefore->previous = newElement;

    Size++;
}

template<typename T>
void List<T>::DeleteElement(int position)
{
    if(position <= 0 || position > Size)
    {
        std::cout<<"Out of range!"<<std::endl;
        return;
    }

    int counter = 1;

    Node<T> * Deletable = Head;

    while(counter < position)
    {
        Deletable = Deletable->next;
        counter++;
    }

    Node<T> * DeletablePrevious = Deletable->previous;

    Node<T> * DeletableAfter = Deletable->next;

    if(DeletablePrevious != 0 && Size != 1)
    {
        DeletablePrevious->next = DeletableAfter;
    }
    if(DeletableAfter != 0 && Size != 1)
    {
        DeletableAfter->previous = DeletablePrevious;
    }

    if(position == 1)
    {
        Head = DeletableAfter;
    }
    if(position == Size)
    {
        Tail = DeletablePrevious;
    }
    
    delete Deletable;
    Deletable = 0;

    Size--;
}

template<typename T>
void List<T>::PrintElement(int position)
{
    if(position <= 0 || position > Size)
    {
        std::cout<<"Out of range!"<<std::endl;
        return;
    }

    Node<T> * TargetElement;

    if(position <= Size/2)
    {
        TargetElement = Head;
        int counter = 1;

        while(counter < position)
        {
            TargetElement = TargetElement->next;
            counter++;
        }
    }else
    {
        TargetElement = Tail;
        int counter = 1;
        while(counter <= Size - position)
        {
            TargetElement = TargetElement->previous;
            counter++;
        }
    }
    
    std::cout<<"Element number: "<<position<<" data: " << TargetElement->data<<std::endl;
}

template<typename T>
void List<T>::PrintList()
{
    if(Size != 0)
    {
        Node<T> * ElementIterator = Head;
        std::cout<<"List content: { ";
        while(ElementIterator->next != 0)
        {
            std::cout<<ElementIterator->data<<", ";
            ElementIterator = ElementIterator->next;
        }

        std::cout<<ElementIterator->data<<" }"<<std::endl;
    }
}

template<typename T>
void List<T>::DeleteList()
{
    while(Size != 0)
    {
        DeleteElement(1);
    }
}

template<typename T>
int List<T>::GetSize()
{
    return Size;
}

template<typename T>
Node<T> * List<T>::GetElement(int position)
{
    if(position <= 0 || position > Size)
    {
        std::cout<<"Out of range!"<<std::endl;
        return 0;
    }

    Node<T> * TargetElement = Head;
    int counter = 0;

    while(counter < position && TargetElement != 0)
    {
        TargetElement = TargetElement->next;
        counter++;
    }

    if(TargetElement == 0)
    {
        return 0;
    }else
    {
        return TargetElement;
    }
}

template<typename T>
List<T>& List<T>::operator = (const List<T> & LST)
{
    if(this == &LST)
    {
        return *this;
    }

    this->~List();

    Node<T> * CopyVariable = Head;

    while(CopyVariable != 0)
    {
        AddTail(CopyVariable->data);
        CopyVariable = CopyVariable->next;
    }

    return *this;
}

template<typename T>
List<T> List<T>::operator+ (const List<T>& LST)
{
    List<T> TargetList(*this);

    Node<T> * InsertingElements = LST.Head;

    while(InsertingElements != 0)
    {
        TargetList.AddTail(InsertingElements->data);
        InsertingElements = InsertingElements->next;
    }

    return TargetList;
}

template<typename T>
bool List<T>::operator== (const List<T>& LST)
{
    if(Size != LST.Size)
    {
        return false;
    }

    Node<T> * Target, * Comparable;

    while(Target != 0)
    {
        if(Target->data != Comparable->data)
        {
            return false;
        }

        Target = Target->next;
        Comparable = Comparable->next;
    } 

    return true;
}

template<typename T>
bool List<T>::operator!= (const List<T>& LST)
{
    return !(*this == LST);
}

template<typename T>
bool List<T>::operator>= (const List<T>& LST)
{
    if(Size > LST.Size)
    {
        return true;
    }

    if(*this == LST)
    {
        return true;
    }

    return false;
}

template<typename T>
bool List<T>::operator<= (const List<T>& LST)
{
    if(Size < LST.Size)
    {
        return true;
    }
    if(*this == LST)
    {
        return true;
    }

    return false;
}

template<typename T>
bool List<T>::operator> (const List<T>& LST)
{
    if(Size > LST.Size)
    {
        return true;
    }

    return false;
}

template<typename T>
bool List<T>::operator< (const List<T>& LST)
{
    if(Size < LST.Size)
    {
        return true;
    }

    return false;
}

template<typename T>
List<T> List<T>::operator- ()
{
    List<T> Target;

    Node<T> * ElementIterator = Head;

    while(ElementIterator != 0)
    {
        Target.AddTail(ElementIterator->data);
        ElementIterator = ElementIterator->next;
    }

    return Target;
}
#endif