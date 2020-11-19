#include <iostream>
#include "stack.h"

int main()
{
        Stack s; // = new Stack();
        std::cout << "Starting Length: " << s.Length() << std::endl;
        s.Push(10);
        s.Push(20);
        std::cout << "Is Stack Empty? " << s.IsEmpty() << std::endl;
        std::cout << "Top Item On Stack: " << s.Peek() << std::endl;
        std::cout << "New Length After Two Successive Push: " << s.Length() << std::endl;
        std::cout << "Popped Item: " << s.Pop() << std::endl;
        std::cout << "Popped Again: " << s.Pop() << std::endl;
        std::cout << "Is Stack Empty? " << s.IsEmpty() << std::endl;
        std::cout << "New Length After Two Successive Pop: " << s.Length() << std::endl;
        return 0;
}
