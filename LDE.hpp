#include <iostream>
#include "No.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

template <typename T>
class LDE{
    private:
        int n;
        No<T>* primeiro;

    public:
        LDE(): n(0), primeiro(nullptr){

        }

        bool insere(T valor){
            No<T>* novo = new No<T>(valor);
            if(novo == nullptr)
                return false;

            No<T>* anterior = nullptr;
            No<T>* atual = primeiro;

            while(atual && valor > atual->valor){
                anterior = atual;
                atual = atual->proximo;
            }

            novo->proximo = atual;
            if(anterior!=nullptr){
                anterior->proximo = novo;
            }else{
                primeiro = novo;
            }
            n++;
            return true;
        }

        No<T>* busca(int valor){

            No<T>* atual = primeiro;
            while(atual && atual->valor < valor){
                atual = atual->proximo;
            }

            if(atual && atual->valor == valor){
                return atual;
            } else{
                return nullptr;
            }
        }

        bool deleta(int valor){
            No<T>* atual = primeiro;
            No<T>* reserva = primeiro->proximo;

            while(atual && reserva->valor < valor){
                atual = atual->proximo;
                reserva = atual->proximo;
            }

            if(reserva->valor == valor){
                atual->proximo = reserva->proximo;
                delete reserva;
                n = n-1;
                return true;
            }
        }

    void imprime(){
        No<T>* atual = primeiro;
        while(atual){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    virtual ~LDE(){
        No<T>* atual = primeiro;
        No<T>* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif