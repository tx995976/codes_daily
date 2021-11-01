
#pragma once

namespace my_queue{
    
    template<class T>
    class Node{
        protected:
            T data;
            Node<T> *next;
        public:
            Node();
            Node(T &data_in);
    };

    template<class T>
    Node<T>::Node(){
        this->data = nullptr;
        this->next =nullptr;
    }

    template<class T>
    Node<T>::Node(T &data_in){
        this->data = data_in;
        this->next = nullptr;
    }
////////////////////////////////////////////////////////
    template<class T>
    class Lq_queue{
        protected:
            Node<T> *top,*fear;
            int length;
        public:
            ~Lq_queue(){}
            Lq_queue();
            Lq_queue(Lq_queue<T> &Lq_in);
            int size() const;
            bool empty() const;
            void clear();
            int push(T &in);
            T pop();
            T front() const;
            T back() const;
            void visit(void (*method_visit)(T &in));
    };


    template<class T>
    Lq_queue<T>::Lq_queue(){
        this->length = 0;
        this->top = new Node<T>;
        this->fear = this->top;
    }

    template<class T>
    Lq_queue<T>::Lq_queue(Lq_queue<T> &Lq_in){
        this->length = Lq_in.length;
        this->top = new Node<T>(Lq_in.top->data);
        Node<T> * temp = Lq_in.top->next,*temp2 = this->top;

        while(temp != nullptr){
            temp2 = temp2->next;
            temp2 = new Node<T>(temp->data);
            temp = temp->next;
        }
        this->fear = temp2;
    }

    template<class T>
    int Lq_queue<T>::size()const{
        return this->length;
    }

    template<class T>
    bool Lq_queue<T>::empty()const{
        if(this->fear == this->top)
            return 1;
        else
            return 0;
    }
    
    template<class T>
    void Lq_queue<T>::clear(){
        Node<T> *temp = this->top->next,*temp2 = temp;
        this->top->next =nullptr;
        while(temp != nullptr){
            temp2 = temp2->next;
            delete temp;
            temp = temp2;
        }
        this->fear = this->top;
        this->length = 0;
    }

    template<class T>
    int Lq_queue<T>::push(T &in){
        this->fear->next = new Node<T>(in);
        this->fear = this->fear->next;
        this->length--;
        return 0;
    }

    template<class T>
    T Lq_queue<T>::pop(){
        if(this->empty())
            return nullptr;
        T pop_data = this->top->next->data;
        Node<T> *pop_node = this->top->next;
        this->top->next = pop_node->next;
        delete pop_node;
        return pop_data;
    }

    template<class T>
    T Lq_queue<T>::front()const{
        return this->top->next->data;
    }

    template<class T>
    T Lq_queue<T>::back()const{
        return this->fear->data;
    }

    template<class T>
    void Lq_queue<T>::visit(void (*method_visit)(T &in)){
        if(this->empty())
            return;
        Node<T> *temp = this->top->next;
        while(temp != nullptr){
            method_visit(temp->data);
            temp = temp->next;
        }
    }
}
