#include "OrdemServico.hpp"

/**
 * @brief Construtor responsável por instanciar
 * as ordens lidas no arquivo texto
 */
OrdemServico:: OrdemServico(){
    
}

/**
 * @brief Construtor da classe OrdemServico
 * @param _numOrdem Número da ordem instanciada
 * @param _proposta Proposta fechada que irá se 
 * se tornar uma ordem de serviço
 * @param _dataAssinatura Data que a proposta foi
 * assinada
 */
OrdemServico:: OrdemServico(int _numOrdem, Proposta* _proposta, std::string _dataAssinatura) {

    this->numOrdem = _numOrdem;
    _proposta->setContratoFechado();
    _proposta->setDataAssinatura(_dataAssinatura);
    _proposta->setPrevisaoPagamento(_dataAssinatura);
    this->proposta = _proposta;
    this->idProposta = this->proposta->getNumProposta();
    this->concluida = false;
}

/**
 * @brief Verifica o número da última ordem de
 * de serviço e retorna o número que a próxima
 * ordem deve ser identificada
 * @return Número da próxima ordem de serviço
 */
int OrdemServico:: getOrdemAtual(){
    
    return this->numOrdem + 1;
}

/**
 * @brief Retorna número da ordem de serviço
 * @return Número da ordem de serviço
 */
int OrdemServico:: getNumOrdem(){

    return this->numOrdem; 
}

/**
 * @brief Verifica se a proposta foi paga
 * @return Status de pagamento
 */
bool OrdemServico::ordemPaga(){

    return this->proposta->pagamentoRecebido();
};

/**
 * @brief Retorna valor da Proposta
 * @return Valor da Proposta
 */
double OrdemServico::getValor(){

    return this->proposta->getValor();
};

/**
 * @brief Atualiza proposta fechada tornando-a
 * um contrato
 * @param _proposta Proposta que irá virar contrato
 */
void OrdemServico:: setContrato(Proposta* _proposta){
    
    this->proposta = _proposta;
    this->idProposta = this->proposta->getPropostaAtual();
    this->proposta->setContratoFechado();
}

/**
 * @brief Atualiza informações de pagamento
 * do contrato
 * @param _valor Valor do pagamento
 * @param _dataPagamento Data do pagamento
 */
void OrdemServico::setPagamento(double _valor, std::string _dataPagamento){

    this->proposta->setContratoPago(_valor,_dataPagamento);
 
};

/**
 * @brief Atualiza data da entrega da ordem de 
 * serviço
 * @param _dataEntrega Data de entrega da ordem
 */
void OrdemServico:: setDataEntrega(std::string _dataEntrega){
    
    this->dataEntrega = _dataEntrega;
    this->concluida = true;
}

/**
 * @brief Atribui engenheiro a ordem de serviço
 * @param _engResponsavel Engenheiro responsável
 */
void OrdemServico:: setEngenheiro(std::string _engResponsavel){
    
    this->engResponsavel = _engResponsavel;
}

/**
 * @brief Retorna Id da Proposta
 * @return Identificação da Proposta
 */
int OrdemServico:: getIdProposta(){
    
    return this->idProposta;
}

/**
 * @brief Retorna data de entrega da ordem
 * @return Data de entrega
 */
std::string OrdemServico:: getDataEntrega(){
    
    return this->dataEntrega;
}

/**
 * @brief Retorna nome do engenheiro
 * @return Engenheiro responsável pela ordem
 */
std::string OrdemServico:: getNomeEngenheiro(){
    
    return this->engResponsavel;
}

/**
 * @brief Retorna status da ordem 
 * @return Status da ordem de serviço
 */
bool OrdemServico:: getStatus(){
    
    return this->concluida;
}

/**
 * @brief Imprime na tela as informações de
 * todas as ordens de serviço
 */
void OrdemServico:: printTela(){
    
    std::cout << "[ORDEM DE SERVIÇO: " << this->getNumOrdem() << "]" << std::endl;
    if (this->concluida == true)
        std::cout << "Esta ordem de serviço está finalizada." << std::endl;
    else
        std::cout << "Esta ordem de serviço não foi finalizada." << std::endl;
    std::cout << "Engenheiro Responsável: " << this->engResponsavel << std::endl
              << "Data de entrega: " << this->getDataEntrega() << std::endl;

    this->proposta->printProposta();
}

/**
 * @brief Imprime arquivo texto 
 * @param out Arquivo texto com todas as ordens
 * de serviço da empresa
 */
void OrdemServico:: printArquivo(std::ostream& out){
    
    out << this->getNumOrdem() << std::endl
        << this->engResponsavel << std::endl
        << this->proposta->getNumProposta() << std::endl
        << this->concluida << std::endl;
}

/**
 * @brief Lê arquivo texto 
 * @param in Arquivo texto com todas as ordens
 * antigas da empresa
 */
void OrdemServico:: lerArquivo(std::istream& in){
    
    in >> this->numOrdem;
    in.ignore();
    getline(in, this->engResponsavel);
    in >> this->idProposta
       >> this->concluida;
}

/**
 * @brief Sobrecarrega operador << para ler objeto 
 * do tipo OrdemServico no arquivo texto
 * @param out Arquivo texto com todas as ordens
 * de serviço da empresa
 * @param os Ordem de serviço que será atribuida
 */
std::ostream& operator<< (std::ostream& out, OrdemServico& oS){
    
    oS.printArquivo(out);
    return out;
}

/**
 * @brief Sobrecarrega operador >> para enviar 
 * informações do objeto para o arquivo texto 
 * @param in Arquivo texto com todas as ordens
 * antigas da empresa
 * @param os Ordem de serviço que será atribuida
 */
std::istream& operator>> (std::istream& in, OrdemServico& oS){
    
    oS.lerArquivo(in);
    return in;
}
