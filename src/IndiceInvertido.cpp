#include <string>
#include <map>
#include <set>
#include <utility>

#include "IndiceInvertido.h"

using std::string;
using std::map;
using std::set;
using std::pair;

IndiceInvertido::IndiceInvertido()
{
    //ctor
}

void IndiceInvertido::inserir(const pair<string,string>& item)
{
    if(!(pertence(item.first)))//chave não esta no dicionário
    {
        set<string> arquivos;
        arquivos.insert(item.second);
        indice_.insert(pair< string,set<string> >(item.first,arquivos));
    }
    else //chave já esta no dicionário
    {
        map< string,set<string> >::iterator it;
        it = indice_.find(item.first); //acha a posição da chave
        bool is_in;

        if(it!= indice_.end())
        {
            //Arquivo já esta no set relacionado à essa chave?
            is_in = ((it->second).find(item.second)) != ((it->second).end());
        }

        if(!(is_in))
        {
            //Adiciona arquivo ao set desta chave
            (it->second).insert(item.second);
        }
    }

}

void IndiceInvertido::remover(const string chave)
{
    if(pertence(chave))
    {
        map< string,set<string> >::iterator it;
        it = indice_.find(chave);
        indice_.erase(it);
    }
}

bool IndiceInvertido::vazio()const
{
    return (indice_.empty());
}

int IndiceInvertido::tamanho()const
{
    return (indice_.size());
}

bool IndiceInvertido::pertence(const string chave)
{
    map< string,set<string> >::iterator it;
    it = indice_.find(chave);

    if(it!= indice_.end())
        return true;
    return false;
}

const set<string>& IndiceInvertido::buscar(const string chave)
{
    map< string,set<string> >::iterator it;
    it = indice_.find(chave);

    return (it->second);
}

IndiceInvertido::~IndiceInvertido()
{
    //dtor
}
