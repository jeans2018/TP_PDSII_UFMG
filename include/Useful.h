#ifndef USEFUL_H_INCLUDED
#define USEFUL_H_INCLUDED

#include <string>
#include <utility>
#include <fstream>

#include "IndiceInvertido.h"

using std::string;
using std::pair;
using std::ifstream;

//Lê as palavras do arquivo e as adiciona ao índice invertido
// Entradas: 
// Retorno: 
void LeArquivo(string file_name, IndiceInvertido& indice);


//Transforma as letras maiúsculas em minúsculas e remove caracteres que não são nem letras nem números
// Entradas: 
// Retorno: 
string AjustaString(string s);

#endif // USEFUL_H_INCLUDED
