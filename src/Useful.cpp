
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <fstream>
using std::ifstream;

#include <cctype> // P/ isalnum() e tolower()

#include <algorithm> // P/ remove_if

#include "Useful.h"
#include "ArquivoNaoEncontrado.h"

//
void LeArquivo(string file_name, IndiceInvertido& indice)
{
    ifstream in_file(file_name.c_str());

    // Ecerra o programa caso ifstream n tenha conseguido abrir o arquivo
    if(in_file.fail())
    {
        throw ArquivoNaoEncontrado("\n Arquivo nao encontrado.\n Programa encerrado.\n");
    }

    // Leitura dos dados do arquivo
    string palavra;
    while(in_file >> palavra)
    {
        AjustaString(palavra);
        indice.inserir(make_pair(palavra,file_name));
    }
    in_file.close();
}

//
bool CaractereIndesejado(char c)
{
    if(!isalnum(c))
        return true;
    return false;
}

//
void AjustaString(string& palavra)
{
    palavra.erase(remove_if(palavra.begin(), palavra.end(), CaractereIndesejado), palavra.end());
    for(unsigned int pos = 0; pos < palavra.length(); ++pos)
    {
        palavra[pos] = tolower(palavra[pos]);
    }
}

