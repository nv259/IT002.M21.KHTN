#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue();
        virtual ~Queue();

        int front();
        int back();
        int size();

        void push_back(int value);
        void pop_front();

        bool isEmpty();
        bool isFull();

    protected:

    private:
        int list[10];
        int length;
        int QFront, QBack;
};

#endif // QUEUE_H
