
#pragma once

namespace my_queue{

    const int DEFAULT_SIZE = 100;

    template <class T>
    class Sq_queue{
        protected:
            int front,fear;
            int max_size;
            T *data;
        public:
            ~Sq_queue(){}
            Sq_queue();
            Sq_queue
            int size() const;
            bool empty() const;
            void clear();
            int pop();
            int push();
            int front() const;
            int back() const;
    };

    





}
