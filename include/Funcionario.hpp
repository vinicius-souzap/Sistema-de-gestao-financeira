#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Exceptions.hpp"

/**
 * @brief  Classe criada para reunir as características semelhantes das 
 * classes Contadores, Orçamentistas e Engenheiros, de forma a implementar 
 * os conceitos de modularização vistos em sala de aula.
*/
class Funcionario
{
    protected:
        std::string nome;
        int identificacao;
        int idade;
        double salario;
};

#endif
