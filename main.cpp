#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <cstdlib> // P/ exit

#include "IndiceInvertido.h"
#include "Useful.h"

#include "ArquivoNaoEncontrado.h"
#include "TestesDeUnidade.h"

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

    cout << "\n Buscar: ";
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
        cout << " Sua pesquisa - " << chave_de_busca << " - nao encontrou nenhum documento correspondente.";
        cout << endl;
    }

    //-------------------------------------------------------------------------
    //----------------------- Testes de Unidade -------------------------------
    //-------------------------------------------------------------------------

    cout << "\n \t\t Testes de Unidade\n Testa insercao de uma palavra e um nome de arquivo:";

    IndiceInvertido ind;
    TestesDeUnidade teste;

    bool ans = false;

    string palavra("testando");
    string file_name("teste.txt");

    ans = teste.TestaInserir(palavra,file_name,ind);
    cout << "\n Resultado: Insercao " << (ans?"efetuada com sucesso.\n":"falhou.\n");

    //-------------------------------------------------------------------------
    cout << "\n Testa a insercao de varias palavras e varios arquivos:";

    vector<string> palavras;
    palavras.push_back("teste1");
    palavras.push_back("teste2");
    palavras.push_back("teste3");
    palavras.push_back("teste4");

    vector<string> file_names;
    file_names.push_back("file1.txt");
    file_names.push_back("file2.txt");
    file_names.push_back("file3.txt");
    file_names.push_back("file4.txt");

    ans = teste.TestaInserir(palavras,file_names,ind);
    cout << "\n Resultado: Insercoes " << (ans ? "efetuadas com sucesso.\n":"falharam.\n");
    //-------------------------------------------------------------------------

    cout << "\n Testa a pesquisa de \"teste3\" - palavra esta no indice, indice nao esta vazio:";

    ans = teste.TestaBusca("teste3",ind);
    cout << "\n Resultado: Busca " << (ans ? "realizada com sucesso.\n":"falhou.\n");

    //-------------------------------------------------------------------------
    cout << "\n Testa a remocao de uma palavra e dos arquivos associados a ela:";

    ans = teste.TestaRemover(palavra,ind);
    cout << "\n Resultado: Remocao " << (ans ? "efetuada com sucesso.\n":"falhou.\n");

    //-------------------------------------------------------------------------

    cout << "\n Testa a remocao de todas as palavra e de todos os arquivos:";

    ans = teste.TestaRemover(ind);
    cout << "\n Resultado: Indice " << (ans ? "esvaziado com sucesso.\n":"nao esvaziado.\n");

    //-------------------------------------------------------------------------

    cout << "\n Testa se a remocao dos caracteres diferentes de letras e numeros\n e a conversao das letras para minuscula foram feitas corretamente:";

    string palavraOriginal = "??Gu@aR#da..&.+.-cH´u^Va";
    string palavraEsperada = "guardachuva";

    ans = teste.TestaAjustaString(palavraOriginal,palavraEsperada);
    cout << "\n Resultado: A palavra \"" << palavraOriginal
         << (ans ? "\" foi ajustada corretamente para \"":"nao foi ajustada corretamente.")
         << palavraEsperada << "\".\n";

    //-------------------------------------------------------------------------

    cout << "\n Testa a pesquisa de uma palavra no indice (indice esta vazio - busca deve falhar):";

    ans = teste.TestaBusca("teste4",ind);
    cout << "\n Resultado: Busca " << (ans ? "realizada com sucesso.\n":"falhou.\n");

    //-------------------------------------------------------------------------
    //------------------ Testa o Tratamento de Exceções -----------------------
    //-------------------------------------------------------------------------

    cout << "\n \t\t Testa o Tratamento de Excecao";
    cout << "\n Tentativa de ler o arquivo hamlets.txt, que nao existe no diretorio: \n";

    try
    {
        LeArquivo("hamlets.txt", indice);
    }
    catch(ArquivoNaoEncontrado exc)
    {
        cout << exc.getMensagem() << endl;
        exit(1);
    }

    return 0;
}
