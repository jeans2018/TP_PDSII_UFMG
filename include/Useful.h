#ifndef USEFUL_H_INCLUDED
#define USEFUL_H_INCLUDED

#include <string>

#include "IndiceInvertido.h"

//L� as palavras do arquivo e as adiciona ao �ndice invertido
void LeArquivo(string file_name, IndiceInvertido& indice);

//Retorna true se o caractere n�o for alfa-num�rico
bool CaractereIndesejado(char c);

//Remove caracteres indesejados da string
void AjustaString(string& palavra);

#endif // USEFUL_H_INCLUDED
