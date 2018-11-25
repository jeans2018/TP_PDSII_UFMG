
#ifndef ARQUIVONAOENCONTRADO_H
#define ARQUIVONAOENCONTRADO_H

#include <string>
using std::string;

// Classe para taratamento de exce��o:
//    Arquivo a ser lido n�o foi encontrado no diret�rio especificado
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
