
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

/**
 * @brief Destrutor da classe Funcionario
 */
Funcionario::~Funcionario(){};

/**
 * @brief Retorna nome do funcionário indicado
 * @return Nome do funcionário
 */
std::string Funcionario::getNome(){
    
    return this->nome;
};

/**
 * @brief Retorna identificação do funcionário indicado
 * @return Id do funcionário
 */
int Funcionario::getId(){

    return this->identificacao;
};

/**
 * @brief Retorna idade do funcionário indicado
 * @return Idade do funcionário
 */
int Funcionario::getIdade(){

    return this->idade;
};

/**
 * @brief Retorna salário do funcionário indicado
 * @return Salário do funcionário
 */
double Funcionario::getSalario(){

    return this->salario;
};

/**
 * @brief Imprime na tela todas as informações
 * do funcionário
 */
void Funcionario::printInfo(){
    
    std::cout << "Nome: " << this->nome << std::endl
              << "Idade: " << this->idade << std::endl 
              << "Nº Identificação: " << this->identificacao << std::endl
              << "Salário: " << this->salario << std::endl;
};
