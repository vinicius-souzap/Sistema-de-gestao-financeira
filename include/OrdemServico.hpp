#ifndef ORDEM_SERVICO_H
#define ORDEM_SERVICO_H

#include "Proposta.hpp"
#include "Engenheiro.hpp"

class Engenheiro;

/**
 * @brief Quando uma proposta é fechada, ou seja, o cliente deu a confirmação de que deseja trabalhar com a empresa, 
 * cria-se então uma Ordem de Serviço. Dessa forma, ela possui uma proposta vinculada. Por isso utilizamos
 * composição entre essas classes. Além disso, possui também um engenheiro responsável por ela, que é quem irá
 * gerenciar seu status de execução.
*/
class OrdemServico {
    
    private:
        int numOrdem;
        Proposta* proposta;
        int idProposta;
        std::string dataEntrega;
        std::string engResponsavel;
        bool concluida;
    
};

#endif
