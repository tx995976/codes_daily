
#pragma once

namespace my_queue{
    
    template<class T>
    class Node{
        protected:
            T data;
            Node<T> *next;
        public:
            Node();
            Node(T data_in);
    };

    template<class T>
    class Lq_queue{
        protected:
            Node<T> *front,*fear;
            int size;
        public:
            ~Lq_queue(){}
            Lq_queue();
            Lq_queue(Lq_queue<T> &Lq_in);
            int size() const;
            bool empty() const;
            void clear();
            int pop();
            int push();
            int front() const;
            int back() const;
    };
    
}