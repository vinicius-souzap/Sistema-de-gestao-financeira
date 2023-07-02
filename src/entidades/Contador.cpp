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
void Contador::setPagamento(int _numOrdem, double _valor, std::string _dataPagamento){

    bool encontrado;
    bool sucessoPagamento;

    if(!this->listaOrdens.empty()){
        for(auto it = this->listaOrdens.begin(); it != this->listaOrdens.end(); it ++){
            OrdemServico* aux = *it;

            if(aux->getNumOrdem() == _numOrdem && !aux->ordemPaga()){
                aux->setPagamento(_valor, _dataPagamento);
                encontrado = true;
            } else if(aux->getNumOrdem() == _numOrdem && aux->ordemPaga()){
                throw AlreadyExecuted();
            }  
        }
    } else{
        throw QueueEmptyException();
    }

    if(!encontrado)
        throw ItemNotFoundException();
};

/**
 * @brief Imprime na tela o status do pagamento da Ordem de 
 * Serviço indicada
 * @param _numOrdem Número da Ordem de Serviço que será impressa
 */
void Contador::printStatusPagamento(int _numOrdem){
    
    bool encontrado;

    if(!this->listaOrdens.empty()){
        for(auto it = this->listaOrdens.begin(); it != this->listaOrdens.end(); it ++){
            OrdemServico* aux = *it;

            if(aux->getNumOrdem() == _numOrdem){
                if(aux->ordemPaga())
                    std::cout << "Ordem de Serviço já teve seu contrato pago." << std::endl;
                else
                    std::cout << "Pagamento da Ordem de Serviço ainda está pendente." << std::endl;

                encontrado = true;
            }  
        }
    } else{
        throw QueueEmptyException();
    }

    if(!encontrado)
        throw ItemNotFoundException();

};

/**
 * @brief Imprime na tela todas as Ordens cadastradas
 */
void Contador::printListaOS(){

    if(!this->listaOrdens.empty()){
        for(auto it = this->listaOrdens.begin(); it != this->listaOrdens.end(); it ++){
            OrdemServico* aux = *it;  
            aux->printTela();
        }
    } else{
        throw QueueEmptyException();
    }   
};

/**
 * @brief Imprime na tela a soma dos pagamentos recebidos
 * e a soma dos pagamentos pendentes
 * Serviço indicada
 */
void Contador::printHistoricoFinanceiro(){

    this->receitaBruta = 0;
    this->receitaPendente = 0;

    if(!this->listaOrdens.empty()){
        for(auto it = this->listaOrdens.begin(); it != this->listaOrdens.end(); it ++){
            OrdemServico* aux = *it;  
            
            if(aux->ordemPaga())
                this->receitaBruta += aux->getValor();
            else
                this->receitaPendente += aux->getValor();
        }

        std::cout << "Receita Bruta: R$" << std::fixed << std::setprecision(2) << this->receitaBruta;
        std::cout << std::endl;

        std::cout << "Receita Pendente: R$" << std::fixed << std::setprecision(2) << this->receitaPendente;
        std::cout << std::endl;

    } else{
        throw QueueEmptyException();
    }     
};

