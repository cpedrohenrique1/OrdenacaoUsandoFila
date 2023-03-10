#ifndef FILA_H
#define FILA_H
#include <QString>

namespace Pedro{
    class Fila
    {
    private:
        int tamanho;
        int *array;
        int inicio;
        int fim;
        int quantidadeElementos;
    public:
        Fila(int tamanho);
        ~Fila();
        bool estaVazia()const;
        bool estaCheio()const;
        int getQuantidadeElementos()const;
        int acessar()const;
        void inserir(int entrada);
        int retirar();
    };
}

#endif // FILA_H
