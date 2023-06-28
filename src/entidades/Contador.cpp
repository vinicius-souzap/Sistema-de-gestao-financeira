#include "Contador.hpp"

/**
 * @brief Construtor da classe Contador
 * @param _nome Nome do contador instanciado
 * @param _identificacao Número de identificação
 *do contador instanciado
 * @param _idade Idade do contador instanciado
 * @param _salario Salário do contador instanciado
 * @param _listaOrdens Array das ordens de serviço
 */
Contador::Contador(std::string _nome, int _identificacao, int _idade, double _salario, std::vector<OrdemServico*> _listaOrdens)
          : Funcionario(_nome, _identificacao, _idade, _salario){

            this->listaOrdens = _listaOrdens;
};

/**
 * @brief Destrutor da classe Contador
 */
Contador::~Contador(){};

/**
 * @brief Indica que uma Ordem de Serviço foi paga
 * @param _numOrdem Número da Ordem de Serviço analisada
 * @param _valor Valor que deve ser pago pela Ordem de serviço
 * @param _dataPagamento Data que o pagamento foi efetuado
 */

};
