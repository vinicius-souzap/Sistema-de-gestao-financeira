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
