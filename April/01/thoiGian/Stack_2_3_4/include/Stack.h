#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        virtual ~Stack();

        void push(int value);
        void pop();

        int top();
        int Size();

        bool isFull();
        bool isEmpty();

    protected:

    private:
        int list[100];
        int length;
};

#endif // STACK_H
