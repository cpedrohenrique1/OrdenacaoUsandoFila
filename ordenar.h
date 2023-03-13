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
        Ordenar();
        void setVetor(const int &);
        void OrdenarFila(const QString &);
        QString acessarVetor();
        void OrdenarFilaCrescente(Pedro::Fila &);
        void OrdenarFilaDecrescente(Pedro::Fila &);
    };
}

#endif // ORDENAR_H
