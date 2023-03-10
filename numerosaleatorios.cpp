#include "numerosaleatorios.h"

Pedro::NumerosAleatorios::NumerosAleatorios(const int& min, const int& max):
    numero(0),
    min(0),
    max(0)
{
    if (max < min)
        throw QString("Numero Maximo nao pode ser menor que o minimo");
    std::srand(std::time(0));
    this->numero = 1 + (std::rand() % max);
}

int Pedro::NumerosAleatorios::getNumero()const
{
    return numero;
}

void Pedro::NumerosAleatorios::preencherFila(const int& tamanho, Pedro::Fila& f)
{
    for (int i = 0; i < tamanho; i++){
        f.inserir(getNumero());
    }
}
