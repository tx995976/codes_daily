#pragma once

const int DEFAULT_SIZE = 100;

template<class T>
class Sqstack{
    protected:
        int top;
        int max_size;
        T  *data;;
    public:
        Sqstack(int size = DEFAULT_SIZE,T &array_T);
        Sqstack(int size = DEFAULT_SIZE);
        ~Sqstack(){}



};