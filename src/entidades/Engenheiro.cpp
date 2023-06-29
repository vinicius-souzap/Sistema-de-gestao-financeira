#include "Engenheiro.hpp"

/**
 * @brief Construtor da classe Engenheiro
 * @param _nome Nome do engenheiro instanciado
 * @param _identificacao Número de identificação
 *do engenheiro instanciado
 * @param _idade Idade do engenheiro instanciado
 * @param _salario Salário do engenheiro instanciado
 */
Engenheiro::Engenheiro(std::string _nome, int _identificacao, int _idade, double _salario)
              : Funcionario(_nome, _identificacao, _idade, _salario){};

/**
 * @brief Destrutor da classe Engenheiro
 */
Engenheiro::~Engenheiro(){};

/**
 * @brief Calcula a quanatidade de tarefas do
 * engenheiro referenciado
 * @return Quantidade de tarefas do engenheiro
 */


