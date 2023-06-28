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
class Proposta {

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
    
};

#endif
