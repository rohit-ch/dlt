#ifndef STACK_H_INC
#define STACK_H_INC

const int MAX_STACK_SIZE = 1000;

class Stack
{
        private:
                int items[MAX_STACK_SIZE];
                int length;

        public:
                // Default Constructor
                Stack();

                // Core Operations
                void Push(int item);
                int Pop();

                // Additional Methods
                bool IsEmpty();
                int Peek();
                int Length();
};

#endif
