#ifndef NUMEROSALEATORIOS_H
#define NUMEROSALEATORIOS_H
#include <QString>
#include <ctime>
#include "fila.h"

namespace Pedro{
    class NumerosAleatorios
    {
    private:
        int numero;
        int min;
        int max;

    public:
        NumerosAleatorios(const int& min, const int& max);
        int getNumero()const;
        void preencherFila(const int& tamanho, Pedro::Fila&);
    };
}

#endif // NUMEROSALEATORIOS_H
