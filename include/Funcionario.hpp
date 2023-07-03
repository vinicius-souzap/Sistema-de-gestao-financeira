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

    public:
        Funcionario(std::string _nome, int _identificacao, int _idade, double _salario);
        virtual ~Funcionario();
        virtual std::string getNome();
        virtual int getId();
        virtual int getIdade();
        virtual double getSalario();
        virtual void printInfo();
};

#endif
