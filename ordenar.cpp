#include "ordenar.h"

Pedro::Ordenar::Ordenar():
    tamanho(0),
    vetor(0)
{}

void Pedro::Ordenar::setVetor(int tamanho){
    if (tamanho <= 0)
        throw QString("Tamanho invalido");
    try{
        vetor = new int[tamanho];
        this->tamanho = tamanho;

        std::srand(std::time(0));
        for (int i = 0; i < tamanho; i++){
            vetor[i] = std::rand() % 101;
        }
    }
    catch(std::bad_alloc &erro)
    {
        throw QString("memoria nao alocada");
    }
}

void Pedro::Ordenar::OrdenarFila(QString entrada){
    Pedro::Fila f(tamanho);
    f.inserir(vetor[0]);

    if (entrada == "Crescente")
    {
        OrdenarFilaCrescente(f);
    }
    else
    {
        OrdenarFilaDecrescente(f);
    }
}

QString Pedro::Ordenar::acessarVetor(){
    QString saida = "";
    for (int i = 0; i < tamanho; i++){
        saida += QString::number(vetor[i]) + '\t';
    }
    saida += '\n';
    return saida;
}

void Pedro::Ordenar::OrdenarFilaCrescente(Pedro::Fila& f){
    int count = 0;
    for (int i = 0; i < f.getQuantidadeElementos(); i++)
    {
        if (vetor[i] < f.acessar() && count == 0)
        {
            f.inserir(vetor[i]);
        }
        int aux = f.retirar();
        f.inserir(aux);
        count++;
    }
    for (int i = 0; i < f.getQuantidadeElementos(); i++)
    {
        vetor[i] = f.retirar();
    }
}

void Pedro::Ordenar::OrdenarFilaDecrescente(Pedro::Fila& f){
    
}
