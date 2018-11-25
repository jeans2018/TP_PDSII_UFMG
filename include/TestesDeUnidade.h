
#ifndef TESTESDEUNIDADE_H
#define TESTESDEUNIDADE_H

#include <vector>
using std::vector;

#include <string>
using std::string;


#include "IndiceInvertido.h"

class TestesDeUnidade
{
public:
    TestesDeUnidade();

    // Testa a inserção de uma palavra e um arquivo no índice
    bool TestaInserir(string palavra, string file_name, IndiceInvertido& idx);

    // Testa a inserção de várias palavras e vários arquivos no índice
    bool TestaInserir(vector<string> palavra, vector<string> file_name, IndiceInvertido& idx);

    // Testa a remoção de uma palavra e dos arquivos associados à ela
    bool TestaRemocao(string palavra, IndiceInvertido& idx);

    // Testa a remoção de todas as palavra e de todos os arquivos associados à ela
    bool TestaRemocao(IndiceInvertido& idx);

    // Testa a pesquisa por um palavra
    bool TestaBusca(string palavra, IndiceInvertido& idx);

    // Testa se a remoção dos caracteres diferentes de letras e número foi feita corretamente
    bool TestaAjustaString(string palavraOriginal, string palavraAjustada);

private:
    //
};

#endif // TESTESDEUNIDADE_H
