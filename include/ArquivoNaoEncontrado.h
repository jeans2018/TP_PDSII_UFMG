
#ifndef ARQUIVONAOENCONTRADO_H
#define ARQUIVONAOENCONTRADO_H

#include <string>
using std::string;

// Classe para taratamento de exceção:
//    Arquivo a ser lido não foi encontrado no diretório especificado
class ArquivoNaoEncontrado
{
public:
    ArquivoNaoEncontrado( ){}
    ArquivoNaoEncontrado(string msg_): mensagem_(msg_){}
    string getMensagem( ) const {return mensagem_; }
private:
    string mensagem_;
};

#endif // ARQUIVONAOENCONTRADO_H
