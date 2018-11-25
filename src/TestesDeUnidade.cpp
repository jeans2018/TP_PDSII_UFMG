#include <utility>
using std::pair;

#include "TestesDeUnidade.h"
#include "Useful.h"

TestesDeUnidade::TestesDeUnidade()
{ /*empty*/ }

// Testa a inserção de uma palavra e um arquivo no índice
bool TestesDeUnidade::TestaInserir(string palavra, string file_name, IndiceInvertido& idx)
{
    idx.inserir(make_pair(palavra,file_name));
    return(idx.indice_.find(palavra) != idx.indice_.end());
}

// Testa a inserção de várias palavras e vários arquivos no índice
bool TestesDeUnidade::TestaInserir(vector<string> palavra, vector<string> file_name, IndiceInvertido& idx)
{

    for(size_t i = 0; i < palavra.size(); i++)
    {
        if(!TestaInserir(palavra[i],file_name[i],idx))
            return false;
    }
    return true;
}

// Testa a remoção de uma palavra e dos arquivos associados à ela
bool TestesDeUnidade::TestaRemover(string palavra, IndiceInvertido& idx)
{
    idx.remover(palavra);

    return (idx.indice_.find(palavra) == idx.indice_.end());
}

// Testa a remoção de todas as palavra e de todos os arquivos associados à ela
bool TestesDeUnidade::TestaRemover(IndiceInvertido& idx)
{
    while(!idx.indice_.empty())
    {
        idx.remover( (idx.indice_.begin())->first );
    }
    return (idx.indice_.empty());
}

// Testa a busca por um palavra
bool TestesDeUnidade::TestaBusca(string palavra, IndiceInvertido& idx)
{
    set<string> busca = idx.buscar(palavra);

    return (!busca.empty());
}

// Testa se a remoção dos caracteres diferentes de letras e número foi feita corretamente
bool TestesDeUnidade::TestaAjustaString(string palavraOriginal, string palavraAjustada)
{
    AjustaString(palavraOriginal);
    return (palavraOriginal == palavraAjustada);
}
