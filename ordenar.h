#ifndef ORDENAR_H
#define ORDENAR_H
#include <QString>
#include "numerosaleatorios.h"
#include "fila.h"

namespace Pedro{
    class Ordenar
    {
    private:
        Pedro::Fila f;

    public:
        Ordenar(int tamanho);
        void OrdenarFila();
    };
}

#endif // ORDENAR_H
