/*Código fonte - LDE
 * Lista Dinâmica Encadeada
 * Centro Universitário FEI - SBC
 * Autor: Guilherme Ferreira - 22216024-4
*/

#include <iostream>
#include "LDE.hpp"

int main() {

    LDE<int> l;
    for(int i=100;i>=0;i--)
        l.insere(i);

    l.imprime(); // imprime todos os elementos

    cout << l.busca(10)->getValor() << endl; // realiza a busca de um elemento

    l.deleta(69); // deleta um elemento

    l.imprime(); // imprime todos os elementos

    return 0;
}