#include "Orcamentista.hpp"

/**
 * @brief Construtor da classe Orcamentista
 * @param _nome Nome do orçamentista instanciado
 * @param _identificacao Número de identificação
 *do orçamentista instanciado
 * @param _idade Idade do orçamentista instanciado
 * @param _salario Salário do orçamentista instanciado
 * @param _meta Meta do orçamentista instanciado
 */
Orcamentista::Orcamentista(std::string _nome, int _identificacao, int _idade, double _salario, double _meta)
              : Funcionario(_nome, _identificacao, _idade, _salario){

                this->meta = _meta;                
};

/**
 * @brief Destrutor da classe Orcamentista
 */
Orcamentista::~Orcamentista(){};

/**
 * @brief Soma totas as propostas do orçamentista
 * que viraram contrato
 * @return Valor total dos contratos
 */
double Orcamentista::getTotalFechado(){     

    /*Como não foi automatizado o processo de fechar a proposta e somar o valor para o orcamentista responsável,
      fez-se necessário uma verificação desse montante sempre que for preciso pegar o valor*/
    
    this->totalFechado = 0;

    for(auto it = this->listaPropostas.begin(); it != this->listaPropostas.end(); it ++){
        Proposta* aux = *it;
        
        if(aux->contratoAssinado())
            this->totalFechado += aux->getValor();            
    }
    
    return this->totalFechado;
};

/**
 * @brief Retorna meta do orçamentista indicado
 * @return Meta do orçamentista
 */
double Orcamentista::getMeta(){

    return this->meta;
};

/**
 * @brief Atribui nova proposta ao orçamentista
 * @param _proposta Proposta que será atribuida
 */
void Orcamentista::adicionarProposta(Proposta* _proposta){

    this->listaPropostas.push_back(_proposta);
    _proposta->setOrcamentista(this->nome);
};

/**
 * @brief Imprime na tela todas as propostas
 * em aberto
 */
void Orcamentista::imprimirPropostasAbertas(){
    
    if(!this->listaPropostas.empty()){
        for(auto it = this->listaPropostas.begin(); it != this->listaPropostas.end(); it ++){ 
            Proposta* aux = *it;
        
            if(!aux->contratoAssinado())
                aux->printProposta();            
        }
    } else{
        throw QueueEmptyException();
    }
};

/**
 * @brief Imprime na tela todas as propostas
 * que viraram contrato
 */
void Orcamentista::imprimirPropostasFechadas(){

    if(!this->listaPropostas.empty()){
        for(auto it = this->listaPropostas.begin(); it != this->listaPropostas.end(); it ++){    
            Proposta* aux = *it;
        
            if(aux->contratoAssinado())
                aux->printProposta();            
        }  
    } else{
        throw QueueEmptyException();
    }
};

/**
 * @brief Calcula e imprime o rendimento do 
 * orçamentista de acordo com sua meta
 */
void Orcamentista::progressoMeta(){

    double porcentagem;

    porcentagem = this->getTotalFechado() / this->meta * 100;

    std::cout << "Orcamentista: " << this->nome << std::endl
              << "Total fechado: " << this->totalFechado << std::endl
              << "Meta definida: " << this->meta << std::endl
              << "Porcentagem cumprida: " << std::fixed << std::setprecision(2) << porcentagem << "%"
              << std::endl;
};

/**
 * @brief Imprime na tela todas as informações
 * do orçamentista
 */
void Orcamentista::printInfo(){
    
    std::cout << "Nome: " << this->nome << std::endl
              << "Idade: " << this->idade << std::endl 
              << "Nº Identificação: " << this->identificacao << std::endl
              << "Salário: " << this->salario << std::endl
              << "Meta: " << this->meta << std::endl;
};