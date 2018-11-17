#ifndef INDICEINVERTIDO_H
#define INDICEINVERTIDO_H

#include <string>
#include <map>
#include <set>
#include <utility>

using std::string;
using std::map;
using std::set;
using std::pair;

class IndiceInvertido
{
    public:
        IndiceInvertido();
        ~IndiceInvertido();
        //Insere um item no dicionário de forma ordenada, caso a chave já pertença
        //ao dicionário, a lista associada à ele é atualizada
        void inserir(const pair<string,string>& item);
        //Remove um item do dicionário, se ele lá estiver
        void remover(const string chave);
        //Verifica se o dicionário está vazio
        bool vazio()const;
        //Retorna a quantidade de itens no dicionário
        int tamanho()const;
        //Verifica se a string chave pertence ao índice
        bool pertence(const string chave);
        //Retorna o set indexado por chave
        const set<string>& buscar(const string chave)const;

    private:
       map< string,set<string> > indice_;
};

#endif // INDICEINVERTIDO_H
