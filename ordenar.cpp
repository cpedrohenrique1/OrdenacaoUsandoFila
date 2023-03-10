#include "ordenar.h"

Pedro::Ordenar::Ordenar(int tamanho):
    f(tamanho)
{
    Pedro::NumerosAleatorios nA(0,100);
    nA.preencherFila(tamanho, f);
}

Pedro::Ordenar::OrdenarFila()
{

}
