#include <iostream>
using std::cout;

#include <string>
using std::string;

#include <utility>
using std::pair;
using std::make_pair;

#include <fstream>
using std::ifstream;

#include <cstdlib>
using std::exit;

#include <cctype> // P/ isalpha(), isdigit() e tolower()

#include "Useful.h"

//
void LeArquivo(string file_name, IndiceInvertido& indice)
{
    ifstream inFile(file_name.c_str());

    // Ecerra o programa caso ifstream n tenha conseguido abrir o arquivo
    if(inFile.fail())
    {
        cout << "\nFile could not be opened\n" << endl;
	exit(1);
    }
    
    // Leitura dos dados do arquivo
    string palavra;
    while(inFile >> palavra)
    {
        indice.inserir(make_pair(AjustaString(palavra),file_name));
    }
    inFile.close();
}



//
string AjustaString(string palavra)
{
    string palavraAjustada = palavra;
    for(int pos = 0; pos < s.length(); ++pos)
    {
	if((!isalpha(palavra[pos])) || (!isdigit(palavra[pos])))
            palavraAjustada.replace(pos,1,"");
	else
	    palavraAjustada[pos] = tolower(palavraAjustada[pos]);
    }
    return palavraAjustada;
}

