#include "Proposta.hpp"

/**
 * @brief Construtor vazio da classe Proposta
 */
Proposta::Proposta(){};

/**
 * @brief Destrutor da classe Proposta
 */
Proposta::~Proposta(){};

/**
 * @brief Construtor da classe Proposta
 * @param _nomeCliente Nome do cliente responsável
 * pela proposta
 * @param _descricao Breve descrição do projeto 
 * @param _valor Valor do projeto
 * @param _numProposta Número da proposta feita
 */
Proposta::Proposta(std::string _nomeCliente, std::string _descricao, double _valor, int _numProposta){
    
    this->nomeCliente = _nomeCliente;
    this->descricao = _descricao;
    this->numProposta = _numProposta;
    this->valor = _valor;
    this->contratoFechado = false;
};
