#ifndef PROPOSTA_H
#define PROPOSTA_H

#include <string>
#include <vector>
#include <iostream> 
#include <iomanip>
#include <sstream>
#include <ctime>

/**
 * @brief Classe responsável por representar todas as propostas recebidas
 * pela empresa. Nela possui informações como o nome do cliente e a descrição
 * do projeto desejado por ele. A partir da proposta, é elaborado um orçamento
 * que, se aprovado pelo cliente, vira uma ordem se serviço.
 */

class Proposta
{
    private:
        static int const prazoPagamento = 30;
        std::string nomeCliente;
        std::string descricao;
        std::string dataAssinatura;
        std::string previsaoPagamento;
        std::string dataPagamento;  
        std::string orcResponsavel;
        double valor; 
        int numProposta; 
        bool contratoFechado; //indica se a proposta se tornou uma ordem de serviço
        bool contratoPago;
     
    public:
        Proposta(std::string _nomeCliente, std::string _descricao, double _valor, int _numProposta);
        Proposta();
        ~Proposta();

        std::string getNomeCliente();
        std::string getDescricao();
        std::string getDataAssinatura();
        std::string getDataPagamento();
        std::string getOrcamentistaResponsavel();

        double getValor();
        int getNumProposta();
        int getPropostaAtual();
        bool contratoAssinado();
        bool pagamentoRecebido();

        void setOrcamentista(std::string _orcResponsavel);
        void setContratoFechado();
        void setContratoPago(double _valor, std::string _dataPagamento);
        void setDataAssinatura(std::string _dataAssinatura);
        void setPrevisaoPagamento(std::string _dataPagamento);
        void setDataPagamento(std::string _dataPagamento);
        void printProposta();
        
        void printArquivo(std::ostream& out);
        void lerArquivo(std::istream& in);
        friend std::ostream& operator<< (std::ostream& out, Proposta& contrato);
        friend std::istream& operator>> (std::istream& in, Proposta& contrato); 
};

#endif
