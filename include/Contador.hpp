#ifndef CONTADOR_H
#define CONTADOR_H

#include "Funcionario.hpp"
#include "OrdemServico.hpp"
#include "Exceptions.hpp"

class OrdemServico;

/**
 * @brief Classe responsável por gerenciar os pagamentos dos contratos.
 * Com acesso a todas as ordens de serviço, o Contador é responsável por
 * confirmar o pagamento dos contratos e gerar relatórios relacionados ao
 * financeiro da empresa
 */
class Contador : public Funcionario
{
    private:
        std::vector<OrdemServico*> listaOrdens;
        double receitaBruta;                       //trata-se do total de pagamentos recebidos;
        double receitaPendente;                    //trata-se do total pendente das OS cujos clientes
                                                   //ainda não realizaram o pagamento;
    public:
        Contador(std::string _nome, int _identificacao, int _idade, double _salario, std::vector<OrdemServico*> _listaOrdens);
        virtual ~Contador();
        void setPagamento(int _numOrdem, double _valor, std::string _dataPagamento);
        void printStatusPagamento(int _numOrdem);
        void printListaOS();
        void printHistoricoFinanceiro();
        
};

#endif
