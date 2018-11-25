
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

    // Testa a inser��o de uma palavra e um arquivo no �ndice
    bool TestaInserir(string palavra, string file_name, IndiceInvertido& idx);

    // Testa a inser��o de v�rias palavras e v�rios arquivos no �ndice
    bool TestaInserir(vector<string> palavra, vector<string> file_name, IndiceInvertido& idx);

    // Testa a remo��o de uma palavra e dos arquivos associados � ela
    bool TestaRemocao(string palavra, IndiceInvertido& idx);

    // Testa a remo��o de todas as palavra e de todos os arquivos associados � ela
    bool TestaRemocao(IndiceInvertido& idx);

    // Testa a pesquisa por um palavra
    bool TestaBusca(string palavra, IndiceInvertido& idx);

    // Testa se a remo��o dos caracteres diferentes de letras e n�mero foi feita corretamente
    bool TestaAjustaString(string palavraOriginal, string palavraAjustada);

private:
    //
};

#endif // TESTESDEUNIDADE_H
