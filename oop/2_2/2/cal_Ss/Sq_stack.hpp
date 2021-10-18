#pragma once

const int DEFAULT_SIZE = 100;

template<class T>
class Sqstack{
    protected:
        int top;
        int max_size;
        T  *data;;
    public:
        Sqstack(const Sqstack<T> &array_T);
        Sqstack(int size = DEFAULT_SIZE);
        ~Sqstack(){}

        int size(); 
        bool empty();
        int top();
        int push(T &i);
        int pop(T &i);

        Sqstack<T> &operator = (const Sqstack<T> &value_r);
};