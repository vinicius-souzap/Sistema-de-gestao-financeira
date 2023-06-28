#ifndef ENGENHEIRO_H
#define ENGENHEIRO_H

#include "Funcionario.hpp"
#include "OrdemServico.hpp"
#include "Exceptions.hpp"

class OrdemServico;

/**
 * @brief Classe responsável por executar uma ordem de serviço. Além de 
 * realizá-la, o Engenheiro é responsável por atualizar o status das ordens
 * de serviço. Para melhor funcionamento da empresa, a quantidade de tarefas 
 * de cada engenheiro é monitorada para que nenhum fique sobrecarregado.
 */
class Engenheiro : public Funcionario
{
    private:
        static const int MAX_ATIVIDADES = 2;
        std::vector<OrdemServico*> listaTarefas;       


};

#endif
