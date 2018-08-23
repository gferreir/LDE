#ifndef NO_HPP
#define NO_HPP

#include <iostream>
using namespace std;

template <typename T>
class LDE;

template <typename T>
class No{
    private:
        T valor;
        No<T>* proximo;
        No(T valor): valor(valor), proximo(nullptr){

        }
    public:
        ~No(){

        }
        T getValor(){
            return this->valor;
        }

    friend class LDE<T>;

};


#endif