
#pragma once

namespace my_queue{

    const int DEFAULT_SIZE = 100;

    template <class T>
    class Sq_queue{
        protected:
            int top,fear;
            int max_size;
            T *data;
        public:
            ~Sq_queue(){}
            Sq_queue();
            Sq_queue(Sq_queue<T> &Sq_in);
            int size() const;
            bool empty() const;
            void clear();
            T pop();
            int push(T &in);
            T front() const;
            T back() const;
    };

    template<class T>
    Sq_queue<T>::Sq_queue(){
        this->top = 0;
        this->fear = 0;
        this->max_size = DEFAULT_SIZE;
        data = new T[DEFAULT_SIZE];
    }
    
    template<class T>
    Sq_queue<T>::Sq_queue(Sq_queue<T> &Sq_in){
        this->top = Sq_in.top;
        this->fear = Sq_in.fear;
        this->max_size = Sq_in.max_size;
        this->data = new T[this->max_size];
        for(int i = 0;i < max_size;i++){
            this->data[i] = Sq_in.data[i];
        }
    }

    template<class T>
    int Sq_queue<T>::size()const{
        return (this->fear-this->top+this->max_size)%this->max_size;
    }

    template<class T>
    bool Sq_queue<T>::empty()const{
        if(this->fear == this->top)
            return 1;
        else
            return 0;
    }

    template<class T>
    T Sq_queue<T>::front()const{
        if(this->empty())
            return *data;
        return this->data[this->top];
    }

    template<class T>
    T Sq_queue<T>::back()const{
        if(this->empty())
            return *data;
        return this->data[(this->fear+this->max_size-1)%this->max_size];
    }

    template<class T>
    T Sq_queue<T>::pop(){
        if(this->empty())
            return *data;
        T temp = this->front();
        this->top = (this->top+1)%this->max_size;
        return temp;
    }

    template<class T>
    int Sq_queue<T>::push(T &in){
        if((this->fear+1)%this->max_size == this->top)
            return -1;
        this->data[this->fear] = in;
        this->fear = (this->fear+1)%this->max_size;
        return 0;
    }

    template<class T>
    void Sq_queue<T>::clear(){
        this->fear = this->top;
    }
}
