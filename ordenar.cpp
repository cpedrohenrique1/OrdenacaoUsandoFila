#include "ordenar.h"

Pedro::Ordenar::Ordenar() : tamanho(0),
                            vetor(0)
{
}

void Pedro::Ordenar::setVetor(const int &tamanho)
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

void Pedro::Ordenar::OrdenarFila(const QString &entrada)
{
    Pedro::Fila f(tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        f.inserir(vetor[i]);
    }

    if (entrada == "Crescente")
    {
        OrdenarFilaCrescente(f);
    }
    else
    {
        OrdenarFilaDecrescente(f);
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
    for (int i = 0; i < tamanho; i++)
    {
        int minMax = f.retirar();
        for (int j = 1; j < tamanho - i; j++)
        {
            int aux = f.retirar();
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
        vetor[i] = minMax;
    }
}

void Pedro::Ordenar::OrdenarFilaDecrescente(Pedro::Fila &f)
{
    for (int i = 0; i < tamanho; i++)
    {
        int minMax = f.retirar();
        for (int j = 1; j < tamanho - i; j++)
        {
            int aux = f.retirar();
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
        vetor[i] = minMax;
    }
}
