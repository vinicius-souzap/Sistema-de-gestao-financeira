#ifndef ORCAMENTISTA_H
#define ORCAMENTISTA_H

#include "Funcionario.hpp"
#include "Proposta.hpp"
#include "Exceptions.hpp"

/**
 * @brief Orçamentista é uma classe filha de funcionário, sendo responsável 
 * pela manipulação das propostas da empresa. Possui uma meta de vendas a ser 
 * alcançada e pode monitorar seu progresso através de suas funções, podendo 
 * ver quais propostas ainda não foram fechadas, bem como as que já foram, 
 * inclusive tendo um retorno quantitativo acerca do total já vendido.
 */
class Orcamentista : public Funcionario
{
    private:
        std::vector<Proposta*> listaPropostas;
        double totalFechado;
        double meta;       

};

#endif
