#include <iostream>
//#include <string>
//#include <set>

#include "IndiceInvertido.h"
#include "Useful.h"

using namespace std;

int main()
{
    IndiceInvertido indice;
    LeArquivo("hamlet.txt", indice);
    LeArquivo("kinglear.txt", indice);
    LeArquivo("macbeth.txt", indice);
    LeArquivo("othello.txt", indice);
    LeArquivo("romeoandjuliet.txt", indice);

    return 0;
}
