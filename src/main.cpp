#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <cstdio>

#include "Contador.hpp"
#include "Engenheiro.hpp"
#include "Funcionario.hpp"
#include "Orcamentista.hpp"
#include "OrdemServico.hpp"
#include "Proposta.hpp"

void mostrarPropostas(std::vector<Proposta*>& propostas){
    
    if(!propostas.empty())    
        for(auto it = propostas.begin(); it != propostas.end(); it ++){
            Proposta* aux = *it;
            aux->printProposta();
        }
    else
        throw QueueEmptyException();
}
/**
 * @brief printa somentes propostas que não são ordens de serviço
 * @param propostas array de propostas que será verificado
 */ 
void mostrarPropostasAberto(std::vector<Proposta*>& propostas){
    
    if(!propostas.empty())
        for(auto it = propostas.begin(); it != propostas.end(); it ++){
            Proposta* aux = *it;
            if(aux->contratoAssinado() == false)
                aux->printProposta();
        }
    else
        throw QueueEmptyException();   
}

/**
 * @brief printa na tela todas as ordens de serviços já cadastradas
 * @param ordens array de ordens de serviços que será verificado
 */

void mostrarOrdensServico(std::vector<OrdemServico*>& ordens){
    
    if(!ordens.empty())   
        for(auto it = ordens.begin(); it != ordens.end(); it++){
            OrdemServico* aux = *it;
            aux->printTela();
        }
    else
        throw QueueEmptyException(); 
}

/**
 * @brief printa na tela somente propostas que não foram 
 * atribuídas como tarefa para um Engenheiro
 * @param ordens array de ordens de serviços que será verificado
 */
void mostrarOrdensServicoAberta(std::vector<OrdemServico*>& ordens){
    
    if(!ordens.empty())
        for(auto it = ordens.begin(); it != ordens.end(); it++){
            OrdemServico* aux = *it;
            
            if(aux->getStatus() == false)
                aux->printTela();
        }
    else
        throw QueueEmptyException();
}
