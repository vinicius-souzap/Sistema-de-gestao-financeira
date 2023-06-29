#include "Funcionario.hpp"

/**
 * @brief Construtor da classe Funcionario
 * @param _nome Nome do funcionario instanciado
 * @param _identificacao Número de identificação
 *do funcionario instanciado
 * @param _idade Idade do funcionario instanciado
 * @param _salario Salário do funcionario instanciado
 */
Funcionario::Funcionario(std::string _nome, int _identificacao, int _idade, double _salario){

    this->nome = _nome;
    this->identificacao = _identificacao;
    this->idade = _idade;
    this->salario = _salario;
};
