#include <string>
#include <map>
#include <set>
#include <utility>

#include "IndiceInvertido.h"

using std::string;
using std::map;
using std::set;
using std::pair;

//typedef pair< string,string> parPalavraArquivo;
//typedef pair< string,set<string> > parPalavraConjArquivos;
//typedef map< string,set<string> > StrMap;
//typedef pair< StrMap::const_iterator,bool> P;

IndiceInvertido::IndiceInvertido() : indice_()
{
    /*empty*/
}

void IndiceInvertido::inserir(const pair<string,string>& item)
{
    if(!(pertence(item.first)))		//chave não esta no dicionário
    {
        set<string> arquivos;
        arquivos.insert(item.second);
        indice_.insert(pair< string,set<string> >(item.first,arquivos));
    }
    else //chave já esta no dicionário
    {
        map< string,set<string> >::iterator it;
        it = indice_.find(item.first); 		//acha a posição da chave
        (it->second).insert(item.second);	//Adiciona o nome do arquivo ao set relacionado a esta chave
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

bool IndiceInvertido::vazio() const
{
    return (indice_.empty());
}

int IndiceInvertido::tamanho() const
{
    return (indice_.size());
}

bool IndiceInvertido::pertence(const string chave)
{
    map< string,set<string> >::iterator it;
    it = indice_.find(chave);
    
    return (it != indice_.end());
}

const set<string>& IndiceInvertido::buscar(const string chave)
{
    map< string,set<string> >::iterator it;
    it = indice_.find(chave);

    return (it->second);
}

IndiceInvertido::~IndiceInvertido()
{
    /*empty*/
}

