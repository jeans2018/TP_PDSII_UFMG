#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main()
{
    //teste1: usando pair
    string file_name = "d1.txt";
    string word = "apartamento";

    pair<string,string> item;

    item = make_pair(word,file_name);

    cout << "teste pair:" << endl;
    cout << item.first << " " << item.second << endl << endl;

    //--------------------------------------------------------------
    //teste2: usando set

    set<string> arquivos;
    arquivos.insert("d2.txt");
    arquivos.insert("d3.txt");

    set<string>::iterator iter;

    cout << "teste set: " << endl;
    for(iter = arquivos.begin(); iter != arquivos.end(); ++iter)
    {
        cout << (*iter) << " ";
    }
    cout << endl << endl;
    //------------------------------------------------------------------
    //teste 3: usando map

    map< string,set<string> > indice_;

    indice_.insert(pair< string,set<string> >(word,arquivos));

    map< string,set<string> >::iterator iter_map;

    cout << "teste map: " << endl;
    //para imprimir o dicionario
    for(iter_map = indice_.begin(); iter_map != indice_.end(); ++iter_map)
    {
        cout << iter_map->first << " ";
        set<string> arq = iter_map->second;
        set<string>::iterator iter_set;
        //para imprimir o set da chave atual
        for(iter_set = arq.begin(); iter_set != arq.end(); ++iter_set)
        {
            cout << (*iter_set) << " ";
        }
        cout << endl;
    }
    cout << endl;
    //--------------------------------------------------------------------
    //teste 3: acha uma chave na lista; verifica se o arquivo está no set, se não
    //estiver, o adiciona

    map< string,set<string> >::iterator it;
    it = indice_.find("apartamento");
    bool is_in;

    if(it!= indice_.end())
    {
        is_in = ((it->second).find(file_name)) != ((it->second).end());
    }

    if(!(is_in))
    {
        (it->second).insert(file_name);
    }

    cout<< "teste de insercao no set de um item do dicionario: " << endl;
    for(iter_map = indice_.begin(); iter_map != indice_.end(); ++iter_map)
    {
        cout << iter_map->first << " ";
        set<string> arq = iter_map->second;
        set<string>::iterator iter_set;

        for(iter_set = arq.begin(); iter_set != arq.end(); ++iter_set)
        {
            cout << (*iter_set) << " ";
        }
        cout << endl;
    }
    cout << endl;
    //--------------------------------------------------------------------
    //teste 4: tenta inserir um item com a mesma chave, se ela ja existe
    //aumenta o seu set

    arquivos.insert(file_name);
    cout << "testa inserir chave ja existente: " << endl;
    for(iter = arquivos.begin(); iter != arquivos.end(); ++iter)
    {
        cout << (*iter) << endl;
    }
    pair<map< string,set<string> >::iterator,bool> ret;
    ret = indice_.insert(pair< string,set<string> >(word,arquivos));
    if(ret.second == false)//elemento ja esta no dicionario
    {
        ((ret.first)->second).insert("d4.txt");
    }

    for(iter_map = indice_.begin(); iter_map != indice_.end(); ++iter_map)
    {
        cout << iter_map->first << " ";
        set<string> arq = iter_map->second;
        set<string>::iterator iter_set;

        for(iter_set = arq.begin(); iter_set != arq.end(); ++iter_set)
        {
            cout << (*iter_set) << " ";
        }
        cout << endl;
    }
    cout << endl;
    //----------------------------------------------------------------------
    //teste 5: testa se o map ja insere ordenado
    indice_.insert(pair< string,set<string> >("casa",arquivos));
    indice_.insert(pair< string,set<string> >("balde",arquivos));

    cout << "testa ordenacao: "<< endl;
    for(iter_map = indice_.begin(); iter_map != indice_.end(); ++iter_map)
    {
        cout << iter_map->first << " ";
        set<string> arq = iter_map->second;
        set<string>::iterator iter_set;

        for(iter_set = arq.begin(); iter_set != arq.end(); ++iter_set)
        {
            cout << (*iter_set) << " ";
        }
        cout << endl;
    }
    return 0;
}
