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
     
    public:
        Engenheiro(std::string _nome, int _identificacao, int _idade, double _salario);
        virtual ~Engenheiro();
        int getNumTarefas();
        void adicionarTarefa(OrdemServico* _ordemServico);
        void encerrarTarefa(int _numOrdem, std::string _dataEntrega);
        void printListaTarefas();
        virtual void printInfo() override;

};

#endif
