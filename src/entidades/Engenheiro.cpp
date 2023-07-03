#include "Engenheiro.hpp"

/**
 * @brief Construtor da classe Engenheiro
 * @param _nome Nome do engenheiro instanciado
 * @param _identificacao Número de identificação
 *do engenheiro instanciado
 * @param _idade Idade do engenheiro instanciado
 * @param _salario Salário do engenheiro instanciado
 */

Engenheiro::Engenheiro(std::string _nome, int _identificacao, int _idade, double _salario)
              : Funcionario(_nome, _identificacao, _idade, _salario){};

/**
 * @brief Destrutor da classe Engenheiro
 */

Engenheiro::~Engenheiro(){};

/**
 * @brief Calcula a quanatidade de tarefas do
 * engenheiro referenciado
 * @return Quantidade de tarefas do engenheiro
 */

int Engenheiro::getNumTarefas()
{
    return this->listaTarefas.size();
};

/**
 * @brief Atribui nova tarefa ao engenheiro
 * @param _ordemServico Ordem de serviço que
 * será atribuida
 */

void Engenheiro::adicionarTarefa(OrdemServico* _ordemServico)
{
    if(this->listaTarefas.size() == MAX_ATIVIDADES)
    {
        throw QueueFullException();
    } else
    {
        this->listaTarefas.push_back(_ordemServico);
        _ordemServico->setEngenheiro(this->nome);
    }
};

/**
 * @brief Finaliza tarefa que foi atribuida ao
 * engenheiro
 * @param _numOrdem Número da ordem de serviço
 * finalizada
 * @param _dataEntrega Data de finalização da 
  * ordem de serviço
 */

void Engenheiro::encerrarTarefa(int _numOrdem, std::string _dataEntrega)
{
    bool encontrado;
    
    if(!this->listaTarefas.empty())
    {
        for(int i = 0; i < this->listaTarefas.size(); i++)
        {            
            if(this->listaTarefas.at(i)->getNumOrdem() == _numOrdem && !this->listaTarefas.at(i)->getStatus())
            {
                this->listaTarefas.at(i)->setDataEntrega(_dataEntrega);
                this->listaTarefas.at(i)->setEngenheiro("");
                this->listaTarefas.erase(this->listaTarefas.begin() + i);
                encontrado = true;
            } else if(this->listaTarefas.at(i)->getNumOrdem() == _numOrdem && this->listaTarefas.at(i)->getStatus())
            {
                throw AlreadyExecuted();
            }
        }
    } else
    {
        throw QueueEmptyException();
    }
    if(!encontrado)
        throw ItemNotFoundException(); 
};
/**
 * @brief Imprime na tela todas as tarefas atribuidas
 * ao engenheiro
 */

void Engenheiro::printListaTarefas()
{
    if(!this->listaTarefas.empty())
    {
        for(auto it = this->listaTarefas.begin(); it != this->listaTarefas.end(); it ++)
        {
            OrdemServico* aux = *it;  
            aux->printTela();
        }
    } else
    {
        throw QueueEmptyException();
    }   
};

/**
 * @brief Imprime na tela todas as informações
 * do engenheiro
 */

void Engenheiro::printInfo()
{    
    std::cout << "Nome: " << this->nome << std::endl
              << "Idade: " << this->idade << std::endl 
              << "Nº Identificação: " << this->identificacao << std::endl
              << "Salário: " << this->salario << std::endl
              << "Meta: " << this->getNumTarefas() << std::endl;
};
