#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <fstream>
using std::ifstream;

#include <cstdlib> // P/ exit

#include <cctype> // P/ isalnum() e tolower()

#include <algorithm> // P/ remove_if

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
        AjustaString(palavra);
        indice.inserir(make_pair(palavra,file_name));
    }
    inFile.close();
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

