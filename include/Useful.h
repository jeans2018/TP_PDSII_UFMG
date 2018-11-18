#ifndef USEFUL_H_INCLUDED
#define USEFUL_H_INCLUDED

#include <string>
#include <utility>
#include <fstream>

#include "IndiceInvertido.h"

using std::string;
using std::pair;
using std::ifstream;

//L� as palavras do arquivo e as adiciona ao �ndice invertido
// Entradas: 
// Retorno: 
void LeArquivo(string file_name, IndiceInvertido& indice);


//Transforma as letras mai�sculas em min�sculas e remove caracteres que n�o s�o nem letras nem n�meros
// Entradas: 
// Retorno: 
string AjustaString(string s);

#endif // USEFUL_H_INCLUDED
