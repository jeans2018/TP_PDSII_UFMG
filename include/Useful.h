#ifndef USEFUL_H_INCLUDED
#define USEFUL_H_INCLUDED

#include <string>
#include <utility>
#include <fstream>

#include "IndiceInvertido.h"

using std::string;
using std::pair;
using std::ifstream

//Transforma as letras maiúsculas em minúsculas e remove caracteres de pontuação da string
void AjustaString(string& s);
//Lê as palavras do arquivo e as adiciona ao índice invertido
void LeArquivo(string file_name, IndiceInvertido& indice);

#endif // USEFUL_H_INCLUDED
