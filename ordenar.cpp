#include "ordenar.h"

Pedro::Ordenar::Ordenar() : tamanho(0),
                            vetor(0)
{
}

void Pedro::Ordenar::setVetor(int tamanho)
{
    if (tamanho <= 0)
        throw QString("Tamanho invalido");
    try
    {
        vetor = new int[tamanho];
        this->tamanho = tamanho;

        std::srand(std::time(0));
        for (int i = 0; i < tamanho; i++)
        {
            vetor[i] = std::rand() % 101;
        }
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("memoria nao alocada");
    }
}

void Pedro::Ordenar::OrdenarFila(QString entrada)
{
    Pedro::Fila f(tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        f.inserir(vetor[i]);
    }

    for (int i = 0; i < tamanho; i++)
    {
        int minMax = f.retirar();
        for (int j = 1; j < tamanho - i; j++)
        {
            int aux = f.retirar();
            if (entrada == "Crescente")
            {
                if (aux < minMax)
                {
                    f.inserir(minMax);
                    minMax = aux;
                }
                else
                {
                    f.inserir(aux);
                }
            }
            else
            {
                if (aux > minMax)
                {
                    f.inserir(minMax);
                    minMax = aux;
                }
                else
                {
                    f.inserir(aux);
                }
            }
        }
        vetor[i] = minMax;
    }
}

QString Pedro::Ordenar::acessarVetor()
{
    QString saida = "";
    for (int i = 0; i < tamanho; i++)
    {
        saida += QString::number(vetor[i]) + '\t';
    }
    saida += '\n';
    return saida;
}

void Pedro::Ordenar::OrdenarFilaCrescente(Pedro::Fila &f)
{
    int var = f.retirar();
    for (int i = 1; i < tamanho; i++) // start from 1 instead of 0
    {
        int acess = f.acessar();
        f.retirar(); // remove the current element from the queue
        if (acess < var)
        {
            f.inserir(var);
            var = acess;
        }
        else
        {
            f.inserir(acess);
        }
    }
    f.inserir(var); // insert the first element back into the queue
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = f.retirar();
    }
}

void Pedro::Ordenar::OrdenarFilaDecrescente(Pedro::Fila &f)
{
}
