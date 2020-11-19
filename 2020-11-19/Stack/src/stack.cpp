#include "stack.h"

Stack::Stack()
{
        for (int i = 0; i < MAX_STACK_SIZE; i++) {
                items[i] = 0;
        }
        length = 0;
}

void Stack::Push(int item)
{
        if (length >= MAX_STACK_SIZE) {
                throw "Stack Overflow!";
        }

        items[length++] = item;
}

int Stack::Pop()
{
        if (IsEmpty())
                throw "Stack is Empty!";

        auto res = items[--length];
        return res;
}

bool Stack::IsEmpty()
{
        if (length == 0)
                return true;

        return false;
}

int Stack::Peek()
{
        if (IsEmpty())
                throw "Stack is Empty!";

        auto res = items[length-1];
        return res;
}

int Stack::Length()
{
        return length;
}
