#ifndef USEFUL_H_INCLUDED
#define USEFUL_H_INCLUDED

#include <string>

#include "IndiceInvertido.h"

//Lê as palavras do arquivo e as adiciona ao índice invertido
void LeArquivo(string file_name, IndiceInvertido& indice);

//Retorna true se o caractere não for alfa-numérico
bool CaractereIndesejado(char c);

//Remove caracteres indesejados da string
void AjustaString(string& palavra);

#endif // USEFUL_H_INCLUDED
