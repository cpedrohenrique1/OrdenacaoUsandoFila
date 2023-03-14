#ifndef ORDENAR_H
#define ORDENAR_H
#include <QString>
#include <ctime>
#include "fila.h"

namespace Pedro
{
    class Ordenar
    {
    private:
        int tamanho;
        int *vetor;

    public:
        Ordenar(const int& tamanho);
        ~Ordenar();
        QString acessarVetor();
        void OrdenarCrescente();
        void OrdenarDecrescente();
    };
}

#endif // ORDENAR_H
