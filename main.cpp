#include <iostream>
#include <string>
#include <set>
#include <iterator>

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

    string chaveDeBusca;
    set<string> resultBusca;
    std::ostream_iterator<string> output(cout, " ");

    cout << "\nDigite uma palavra: ";
    cin >> chaveDeBusca;

    resultBusca = indice.buscar(chaveDeBusca);

        // Imprime a lista de documentos retornada na tela
    if(!resultBusca.empty())
    {
        cout << endl;
        std::copy(resultBusca.begin(),resultBusca.end(), output);
        cout << endl;
    }

    // Imprime a lista de documentos retornada na tela
    //for()

    return 0;
}
