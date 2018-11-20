#include <iostream>
#include <string>
#include <set>
#include <iterator>

#include "IndiceInvertido.h"
#include "Useful.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    IndiceInvertido indice;
    LeArquivo("hamlet.txt", indice);
    LeArquivo("kinglear.txt", indice);
    LeArquivo("macbeth.txt", indice);
    LeArquivo("othello.txt", indice);
    LeArquivo("romeoandjuliet.txt", indice);

    string chave_de_busca;
    set<string> result_busca;
    std::ostream_iterator<string> output(cout, "\n");

    cout << "\nBuscar: ";
    cin >> chave_de_busca;

    result_busca = indice.buscar(chave_de_busca);

        // Imprime a lista de documentos retornada na tela
    if(!result_busca.empty())
    {
        cout << endl;
        cout << result_busca.size() << " resultados:";
        cout << endl << endl;
        std::copy(result_busca.begin(),result_busca.end(), output);
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "Sua pesquisa - " << chave_de_busca << " - nao encontrou nenhum documento correspondente.";
        cout << endl;
    }

    return 0;
}
