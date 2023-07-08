/**
 * @file main
 * @author  João Pedro, Vinicius, Paulo, Maick  e Matheus
 * @version 1.0
 *
 * @section DESCRIPTION
 
 *
 * Este programa é um Software gratuito, com fins didáticos.
 * O objetivo é simular um sistema de gestão financeiro com
 * as funcionalidades mais básicas de um. Constituído de sete
 * classes (classe de exceções incluída) e armazenamento de 
 * dados em arquivos textos para simular banco de dados.
 */
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <cstdio>


#include "Funcionario.hpp"
#include "Engenheiro.hpp"
#include "Orcamentista.hpp"
#include "Contador.hpp"
#include "Proposta.hpp"
#include "OrdemServico.hpp"

/**
 * @brief printa na tela todas as propostas já cadastradas
 * @param propostas array de propostas que será percorrido 
*/
void mostrarPropostas(std::vector<Proposta*>& propostas)
{  
    if(!propostas.empty())    
        for(auto it = propostas.begin(); it != propostas.end(); it ++)
        {
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
void mostrarPropostasAberto(std::vector<Proposta*>& propostas)
{    
    if(!propostas.empty())
        for(auto it = propostas.begin(); it != propostas.end(); it ++)
        {
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
void mostrarOrdensServico(std::vector<OrdemServico*>& ordens)
{    
    if(!ordens.empty())   
        for(auto it = ordens.begin(); it != ordens.end(); it++)
        {
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
void mostrarOrdensServicoAberta(std::vector<OrdemServico*>& ordens)
{    
    if(!ordens.empty())
        for(auto it = ordens.begin(); it != ordens.end(); it++)
        {
            OrdemServico* aux = *it;
            
            if(aux->getStatus() == false)
                aux->printTela();
        }
    else
        throw QueueEmptyException();
}
/**
 * @brief permite o usuário cadastrar uma nova Proposta
 * @param propostas referência do array de propostas que
 * receberá o novo cadastro
 * @param numPropostaAtual inteiro que indica qual foi 
 * o número da última proposta cadastrada
 */
void cadastrarProposta(std::vector<Proposta*>& propostas, int& numPropostaAtual)
{    
    std::string nome, descricao, dataAssinatura;
    double valor;
    
    std::cout << "Digite o nome do cliente: " << std::endl;
    std::cin.get(); //limpar o buff de entrada
    std::getline(std::cin, nome);
    
    std::cout << std::endl << "Digite a descrição do contrato: " << std::endl;
    std::getline(std::cin, descricao);
    
    std::cout << std::endl;

    std::cout << "Digite o valor total do serviço descrito no contrato:" << std::endl;
    std::cin >> valor;
    
    Proposta* c1 = new Proposta(nome, descricao, valor, numPropostaAtual);
    numPropostaAtual = c1->getPropostaAtual();
    propostas.push_back(c1);

    std::cout << std::endl << "Cadastro realizado com sucesso! Retornando ao menu principal..." << std::endl;
    sleep(3);
}
/**
 * @brief permite ao usuário cadastrar uma nova ordem de serviço
 * @param ordens referência do array de ordens de serviço
 * que receberá o novo Cadastro
 * @param propostas array de propostas já cadastradas
 * @param numOrdemAtual indica qual foi o número da 
 * última ordem cadastrada
 */
void cadastrarOrdemServico(std::vector<OrdemServico*>& ordens, std::vector<Proposta*>& propostas, int& numOrdemAtual)
{
    
    std::cout << "Gerar ordem de serviço para qual contrato?" << std::endl
              << "Digite o N° da proposta do contrato:" << std::endl << std::endl;
    int id;
    std::cin >> id;
    
    std::cout << "Digite a data de assinatura do contrato: " << std::endl;

    std::string dataAssinatura;
    std::cin >> dataAssinatura;
    
    for(auto it = propostas.begin(); it != propostas.end(); it++)
    {
        
        Proposta* aux = *it;
        
        if(id == aux->getNumProposta())
        {
            OrdemServico* novaOrdem = new OrdemServico(numOrdemAtual, aux, dataAssinatura);
            numOrdemAtual = novaOrdem->getOrdemAtual();
            ordens.push_back(novaOrdem);
            break;
        }
    }
    
    std::cout << std::endl << "Cadastro realizado com sucesso! Retornando ao menu principal..." << std::endl;
    sleep(3);
}
/**
 * @brief indica quantas tarefas foram atribuídas a determinado Engenheiro
 * @param engenheiros array de Engenheiro que será percorrido
 * @param id número para identificar o engenheiro alvo
 */
void exibirQuantTarefas(std::vector<Engenheiro*>& engenheiros, int id)
{
    
    for(auto it = engenheiros.begin(); it != engenheiros.end(); it++)
    {
        
        Engenheiro* aux = *it;
        
        if(id == aux->getId())
        {
            std::cout << "Número de tarefas do Engenheiro " << id << ": "
            << aux->getNumTarefas() << std::endl;
            break;
        }
    }
}
/**
 * @brief atribui uma ordem de serviço como tarefa a um Engenheiro
 * @param ordens array de referência de ordens de serviço
 * @param engenheiros array de referência de Engenheiro
 * @param idEng número de identificação do Engenheiro alvo
 */
void adicionarOrdem(std::vector<OrdemServico*>& ordens, std::vector<Engenheiro*>& engenheiros, int idEng)
{
    
    mostrarOrdensServicoAberta(ordens);
    
    for(auto it = engenheiros.begin(); it != engenheiros.end(); it++)
    {
        
        Engenheiro* aux = *it;
        
        if(idEng == aux->getId())
        {
            
            int idOrdem;
            std::cout << "Selecione o ID da ordem a ser atribuída: " << std::endl;
            std::cin >> idOrdem;
            for(auto it2 = ordens.begin(); it2 != ordens.end(); it2++)
            {
                
                OrdemServico* aux2 = *it2;
                
                if(idOrdem == aux2->getNumOrdem())
                {
                    aux->adicionarTarefa(aux2);
                    break;
                }
            }
            system("clear");
            break;
        }
    }
    std::cout << "Ordem adicionada à sua lista de serviços!" << std::endl
    << "Retornando ao menu principal..." << std::endl;
    sleep(3);
}
/**
 * @brief encerra uma ordem de serviço de um engenheiro
 * @param engenheiros array de referência de Engenheiro
 * @param idEng indica qual a identificação do Engenheiro alvo
 */
void encerrarOrdem(std::vector<Engenheiro*>& engenheiros, int idEng)
{
    
    for(auto it = engenheiros.begin(); it != engenheiros.end(); it++)
    {
        
        Engenheiro* aux = *it;
        
        if(idEng == aux->getId())
        {
    
            int idOrdem;
                        
            aux->printListaTarefas();
            
            std::cout << "Digite o ID correspondente da ordem a ser encerrada:" << std::endl;
            std::cin >> idOrdem;
            std::string data;
            std::cout << "Digite a data de finalização desse serviço: " << std::endl;
            std::cin >> data;
            system("clear");
            aux->encerrarTarefa(idOrdem, data);
        }
    }
    std::cout << "Ordem finalizada com sucesso!" << std::endl
    << "Retornando ao menu principal..." << std::endl;
    sleep(3);
}
/**
 * @brief printa todas as tarefas atribuídas a determinado Engenheiro
 * @param engenheiros array de referência de Engenheiro
 * @param idEng indica o id do engenheiro alvo
 */
void exibirTarefasEngenheiro(std::vector<Engenheiro*>& engenheiros, int idEng)
{
    
    for(auto it = engenheiros.begin(); it != engenheiros.end(); it++)
    {
        
        Engenheiro* aux = *it;
        
        if(idEng == aux->getId())
        {
            aux->printListaTarefas();
            break;
        }
    }
}
/**
 * @brief printa as informações de um Engenheiro
 * @param engenheiros array de referência de Engenheiro
 * @param idEng indica o id do engenheiro alvo
 */
void exibirInfoEngenheiro(std::vector<Engenheiro*>& engenheiros, int idEng)
{
    
    for(auto it = engenheiros.begin(); it != engenheiros.end(); it++)
    {
        
        Engenheiro* aux = *it;
        
        if(idEng == aux->getId())
        {
            aux->printInfo();
            break;
        }
    }
}
/**
 * @brief imprime propostas de determinado Orçamentista
 * que não são ordens de serviço
 * @param orcamentistas array de referência de Orçamentista
 * @param idOrcam indica o id do orçamentista alvo
 */
void gerarPropostasAbertas(std::vector<Orcamentista*>& orcamentistas, int idOrcam)
{
    
    for(auto it = orcamentistas.begin(); it != orcamentistas.end(); it++)
    {
        Orcamentista* aux = *it;
        
        if(idOrcam == aux->getId())
        {
            aux->imprimirPropostasFechadas();
            break;
        }
    }
}
/**
 * @brief imprime propostas de determinado Orçamentista
 * que se tornaram ordens de serviço
 * @param orcamentistas array de referencia de Orcamentista
 * @param idOrcam indica o id do orçamentista alvo
 */
void gerarPropostasFechadas(std::vector<Orcamentista*>& orcamentistas, int idOrcam)
{
    
    for(auto it = orcamentistas.begin(); it != orcamentistas.end(); it++)
    {
        Orcamentista* aux = *it;
        
        if(idOrcam == aux->getId())
        {
            aux->imprimirPropostasAbertas();
            break;
        }
    }
}
/**
 * @brief atribui uma determinada proposta a um orçamentista
 * @param orcamentistas array de referência de Orçamentista
 * @param propostas array de referência de Proposta
 * @idOrcam indica o id do orçamentista alvo
 */
void adicionarProposta(std::vector<Orcamentista*>& orcamentistas, std::vector<Proposta*>& propostas, int idOrcam)
{
    
    for(auto it = orcamentistas.begin(); it != orcamentistas.end(); it++)
    {
        Orcamentista* aux = *it;
        
        if(idOrcam == aux->getId())
        {
            
            int idProp;
            std::cout << "Digite o ID correspondente da proposta:" << std::endl;
            std::cin >> idProp;
            
            for(auto it2 = propostas.begin(); it2 != propostas.end(); it2++)
            {
                
                Proposta* aux2 = *it2;
                if(idProp == aux2->getNumProposta())
                {
                    aux->adicionarProposta(aux2);
                    break;
                }
            }
            break;
        }
    }
}
/**
 * @brief exibe o progresso da meta estipulada de um 
 * determinado orçamentista
 * @param idOrcam indica o id do orçamentista alvo
 */
void exibirProgressoMeta(std::vector<Orcamentista*>& orcamentistas, int idOrcam)
{
    
    for(auto it = orcamentistas.begin(); it != orcamentistas.end(); it++)
    {
        Orcamentista* aux = *it;
        
        if(idOrcam == aux->getId())
        {
            aux->progressoMeta();
            break;
        }
    }
}
/**
 * @brief printa as informações de um orçamentista
 * @param orcamentistas array de referência de Orçamentista
 * @idOrcam indica o id do orçamentista alvo
 */
void exibirInfoOrcamentista(std::vector<Orcamentista*>& orcamentistas, int idOrcam)
{
    
    for(auto it = orcamentistas.begin(); it != orcamentistas.end(); it++)
    {
        Orcamentista* aux = *it;
        
        if(idOrcam == aux->getId())
        {
            aux->printInfo();
            break;
        }
    }
}
/**
 * @brief printa a situação de pagamento de determinada
 * ordem de serviço
 * @param ct1 contador que tem acesso às funções
 * relacionadas a faturas e pagamentos
 * @param ordensAtuais array de referência de todas as 
 * ordens de serviço atualmente cadastradas
 */
void exibirStatusPagamento(Contador* ct1, std::vector<OrdemServico*>& ordensAtuais)
{
    
    mostrarOrdensServico(ordensAtuais);
    std::cout << "Selecione a ordem correspondente:" << std::endl;
    int numOrdem;
    std::cin >> numOrdem;
    system("clear");
    ct1->printStatusPagamento(numOrdem);
}
/**
 * @brief efetua o pagamento de uma ordem de serviço
 * @param ct1 contador que tem acesso às funções
 * relacionadas a faturas e pagamentos
 * @param ordensAtuais array de referência de todas as 
 * ordens de serviço atualmente cadastradas
 */
void pagarOrdem(Contador* ct1, std::vector<OrdemServico*>& ordensAtuais)
{
    
    mostrarOrdensServico(ordensAtuais);
    int numOrdem, valor;
    std::string dataPagamento;
    
    std::cout << "Selecione a ordem correspondente:" << std::endl;
    std::cin >> numOrdem;
    std::cout << "Insira o valor do pagamento:" << std::endl;
    std::cin >> valor;
    std::cout << "Insira a data para faturamento:" << std::endl;
    std::cin >> dataPagamento;
    system("clear");
    
    ct1->setPagamento(numOrdem, valor, dataPagamento);
    
    std::cout << "Retornando ao menu principal..." << std::endl;
    sleep(3);
}
/**
 * @brief função responsável pela parada do programa
 * após os comandos feitos pelo usuário
 */
void pressionarParaContinuar()
{
    
    std::cout << "Pressione qualquer tecla para retornar:" << std::endl;
    char getEntrada;
    std::cin >> getEntrada;
}
/**
 * printa no terminal o menu principal e suas opções
 */
void abrirMenuPrincipal()
{
    
    std::cout << "BEM VINDO AO MENU DE OPÇÕES!" << std::endl
    << "Pressione: " << std::endl
    << "'Q' para sair." << std::endl 
    << "'P' para exibir os propostas cadastrados." << std::endl
    << "'O' para exibir as ordens de serviços lançadas até o momento." << std::endl
    << "'C' para realizar algum cadastro." << std::endl
    << "'E' para entrar no menu de opções do Engenheiro." << std:: endl
    << "'D' para entrar no menu de opções do Contador." << std:: endl
    << "'T' para entrar no menu de opções do Orçamentista." << std::endl;
}
/**
 * @brief printa no terminal o menu de cadastros e suas opções
 * @param propostasAtuais array de referência de Proposta
 * que guardara uma nova Proposta cadastrada
 * @param ordensAtuais array de referência de OrdemServico
 * que guardará uma nova OrdemServico
 * @param numOrdemAtual indica qual o número da última
 * ordem cadastrada
 * @param numPropostaAtual indica qual o número da 
 * última Proposta cadastrada
 */
void abrirMenuCadastros(std::vector<Proposta*>& propostasAtuais, std::vector<OrdemServico*>& ordensAtuais, int& numOrdemAtual, int& numPropostaAtual)
{
    
    std::cout << "Entrou no menu de cadastros!" << std::endl
    << "Pressione: " << std::endl
    <<"'V' para voltar ao menu principal." << std::endl
    <<"'P' para realizar o cadastro de um novo contrato." << std::endl
    <<"'O' para realizar o cadastro de uma nova ordem de serviços." << std::endl;
    
    char subComando;
    std::cin >> subComando;
    
    switch(subComando)
    {
        
        case 'p': 
         {
            system("clear");
            cadastrarProposta(propostasAtuais, numPropostaAtual);
            break;
        } 
        case 'o': 
         {
            system("clear");
            mostrarPropostasAberto(propostasAtuais);
            cadastrarOrdemServico(ordensAtuais, propostasAtuais, numOrdemAtual);
            break;
        }
        case 'v':
            break;
    }
}
/**
 * @brief abre no terminal o menu do Engenheiro e suas opções
 * @param engenheiros array de Engenheiro
 * @param ordensAtuais array que guarda as ordens de serviço
 * cadastradas
 */
void abrirMenuEngenheiro(std::vector<Engenheiro*>& engenheiros, std::vector<OrdemServico*>& ordensAtuais)
{
    
    char subComando; int idEng;
                                
    std::cout << "Entrou no menu do Engenheiro!" << std::endl
    << "Selecione seu número de identificação: (3), (4) ou (5) ?" << std::endl;
    
    std::cin >> idEng;
    
    std::cout << "Pressione: " << std::endl
    << "'M' para mostrar o número de tarefas atribuídas ao Engenheiro." << std::endl
    << "'A' para adicionar uma nova tarefa ao Engenheiro." << std::endl
    << "'E' para encerrar alguma tarefa." << std::endl
    << "'P' para exibir todas suas tarefas atuais." << std::endl
    << "'I' para exibir suas informações." << std::endl
    << "'V' para voltar ao menu principal." << std::endl;

    std::cin >> subComando;
    switch(subComando)
    {
        
        case 'm':
            system("clear");
            exibirQuantTarefas(engenheiros, idEng);
            pressionarParaContinuar();
            break;
            
        case 'a': 
         {
            system("clear");
            try
             {
                adicionarOrdem(ordensAtuais, engenheiros, idEng);
            } catch(QueueFullException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            }
            break;
        }
        case 'e': 
         {
            system("clear");
            try
             {
                encerrarOrdem(engenheiros, idEng);
            } catch(AlreadyExecuted& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            } catch(ItemNotFoundException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            }
            break;
        }
        case 'p': 
         {
            system("clear");
            try
             {
                exibirTarefasEngenheiro(engenheiros, idEng);
            } catch(QueueEmptyException& e)
             {
                std::cout << e.what() << std::endl;
            }
            pressionarParaContinuar();
            break;
        }
        case 'i': 
         {
            system("clear");
            exibirInfoEngenheiro(engenheiros, idEng);
            pressionarParaContinuar();
            break;
        }
        case 'v':
            break;    
    }
}
/**
 * @brief printa no terminal o menu do Contador e suas opções
 * @param ct1 contador responsável pelas funções
 * relacionada a faturas e pagamentos
 * @param ordensAtuais array de OrdemServico cadastradas
 */
void abrirMenuContador(Contador* ct1, std::vector<OrdemServico*>& ordensAtuais)
{
    
    char subComando;
    std::cout << "Entrou no menu do Contador!" << std::endl;
    
    std::cout << "Pressione: " << std::endl
    << "'S' para exibir o status de pagamento de alguma ordem." << std::endl
    << "'P' para realizar o pagamento de alguma ordem." << std::endl
    << "'R' para gerar relatório da receita da empresa." << std::endl
    << "'O' para exibir as ordens de serviços lançadas até o momento." << std::endl
    << "'V' para voltar ao menu principal." << std::endl;
    
    std::cin >> subComando;
    
    switch(subComando)
    {
        
        case 's': 
         {
            system("clear");
            try
             {
                exibirStatusPagamento(ct1, ordensAtuais);
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
            } catch(ItemNotFoundException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
            }
            pressionarParaContinuar();
            break;
        }    
        case 'r': 
         {
            system("clear");
            try
             {
                ct1->printHistoricoFinanceiro();
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
            }
            pressionarParaContinuar();
            break;
        } 
        case 'p': 
         {
            system("clear");
            try
             {    
                pagarOrdem(ct1, ordensAtuais);
            } catch(AlreadyExecuted& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            } catch(ItemNotFoundException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
                pressionarParaContinuar();
            }
            break;
        } 
        case 'o': 
         {
            system("clear");
            try
             {
                ct1->printListaOS();
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
            }
            pressionarParaContinuar();
            break;
        }
        case 'v':
            break;
    }
}
/**
 * @brief printa no terminal o menu do Orcamentista e suas opções
 * @param orcamentistas array de Orcamentista
 * @param propostasAtuais array de Proposta que foram cadastradas
 */
void abrirMenuOrcamentista(std::vector<Orcamentista*>& orcamentistas, std::vector<Proposta*>& propostasAtuais)
{
    
    char subComando;
    int idOrcam;
    
    std::cout << "Entrou no menu do Orçamentista!" << std::endl
    << "Selecione seu número de identificação: (1) ou (2) ?" << std::endl;
    
    std::cin >> idOrcam;
    
    std::cout << "Pressione: " << std::endl
    << "'F' para gerar relatório de propostas fechadas." << std::endl
    << "'A' para gerar relatório de propostas abertas." << std::endl
    << "'C' para adicionar uma proposta." << std::endl
    << "'P' para exibir o progresso de sua meta." << std::endl
    << "'I' para exibir suas informações." << std::endl
    << "'V' para voltar ao menu principal." << std::endl;
    
    std::cin >> subComando;
    
    switch(subComando)
    {
        
        case 'f': 
         {
            system("clear");
            try
             {
                gerarPropostasAbertas(orcamentistas, idOrcam);
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
            }
            pressionarParaContinuar();
            break;
        }
        case 'a': 
         {
            system("clear");
            try
             {
                gerarPropostasFechadas(orcamentistas, idOrcam);
            } catch(QueueEmptyException& e)
             {
                system("clear");
                std::cout << e.what() << std::endl;
            }
            pressionarParaContinuar();
            break;
        }
        case 'c': 
         {
            system("clear");
            adicionarProposta(orcamentistas, propostasAtuais, idOrcam);
            pressionarParaContinuar();
            break;
        }
        case 'p': 
         {
            exibirProgressoMeta(orcamentistas, idOrcam);
            pressionarParaContinuar();
            break;
        }
        case 'i': 
         {
            system("clear");
            exibirInfoOrcamentista(orcamentistas, idOrcam);
            pressionarParaContinuar();
            break;
        }
        case 'v':
            break;
    }
}
/**
 * função chave, responsável pela abertura de arquivos para
 * obtenção de dados, gerenciamento do terminal e todo o 
 * menu de opções, sobrescrita de dados nos arquivos após
 * finalização do programa
 */
int main()
{
    
    //todos os arquivos estão abertos inicialmente apenas para leitura e obtenção de dados
    std::fstream arq1("./database/Propostas.txt");
    std::fstream arq2("./database/Ordens.txt");
    std::fstream arq3("./database/ultimaOrdem.txt"); 
    std::fstream arq4("./database/ultimaProposta.txt");
    
    if( !arq1.is_open() || !arq2.is_open() || !arq3.is_open() || !arq4.is_open() ) 
    {
        std::cerr << "Erro ao abrir o arquivo: " << std::strerror(errno) << std::endl;
        return 1;
    }
    
    int numOrdemAtual;
    arq3 >> numOrdemAtual;
    
    int numPropostaAtual;
    arq4 >> numPropostaAtual;
    
    Engenheiro* eg1 = new Engenheiro("Vinicius", 3, 20, 7000);
    Engenheiro* eg2 = new Engenheiro("Joao Pedro", 4, 25, 10000);
    Engenheiro* eg3 = new Engenheiro("Paulo", 5, 30, 8000);
    
    Orcamentista* oc1 = new Orcamentista("Maick", 1, 24, 3000, 150000);
    Orcamentista* oc2 = new Orcamentista("Matheus", 2, 22, 4000, 200000);
    
    std::vector<OrdemServico*> ordensAtuais;
    std::vector<Proposta*> propostasAtuais;
    std::vector<Orcamentista*> orcamentistas;
    std::vector<Engenheiro*> engenheiros;
    
    engenheiros.push_back(eg1); engenheiros.push_back(eg2); engenheiros.push_back(eg3);
    orcamentistas.push_back(oc1); orcamentistas.push_back(oc2);
    
    for(int i = 0; i < numPropostaAtual; i++)
    {
        
        Proposta* c1 = new Proposta();
        arq1 >> *c1;
        propostasAtuais.push_back(c1);
        
        for(auto it = orcamentistas.begin(); it != orcamentistas.end(); it++)
        {
            
            Orcamentista* aux = *it;
            
            if(aux->getNome() == c1->getOrcamentistaResponsavel())
            {
                aux->adicionarProposta(c1);
            }
        }
    }
    
    for(int i = 0; i < numOrdemAtual; i++)
    {
    
        OrdemServico* oS1 = new OrdemServico();
        arq2 >> *oS1;
        
        for(auto it = propostasAtuais.begin(); it != propostasAtuais.end(); it++)
        {
            
            Proposta* aux = *it;
            int i = aux->getNumProposta();
            
            if(oS1->getIdProposta() == i)
            {
                oS1->setContrato(aux);
                ordensAtuais.push_back(oS1);
                break;
            }
        }
        for(auto it = engenheiros.begin(); it != engenheiros.end(); it++)
        {
            
            Engenheiro* aux = *it;
            
            if(aux->getNome() == oS1->getNomeEngenheiro())
            {
                aux->adicionarTarefa(oS1);
                break;
            }
        }
    }
    
    Contador* ct1 = new Contador("Pedro ", 6, 40, 5000, ordensAtuais);
 
    
    //obtenção de dados concluida, arquivos serão fechados
    arq1.close();
    arq2.close();
    arq3.close();
    arq4.close();
    
    char comando;
    int i = 0;
    
    numOrdemAtual += 1;
    numPropostaAtual += 1;
    
    //entra no menu de opções do usuário
    while(i != 1)
    {
        
        abrirMenuPrincipal();
        std::cin >> comando;
        
        switch(comando)
        {
            
            case 'q': 
             {
                i = 1;
                break;
            }   
            case 'p': 
             {
                system("clear");
                try
                 {
                    mostrarPropostas(propostasAtuais);
                }catch(QueueEmptyException& e)
                 {
                    std::cout << e.what() << std::endl;
                }
                pressionarParaContinuar();
                break;
            }  
            case 'o': 
             {
                system("clear");
                try
                 {
                    mostrarOrdensServico(ordensAtuais);
                }catch(QueueEmptyException& e)
                 {
                    std::cout << e.what() << std::endl;
                }
                pressionarParaContinuar();
                break;
            }  
            case 'c': 
             {
                system("clear");
                abrirMenuCadastros(propostasAtuais, ordensAtuais, numPropostaAtual, numOrdemAtual);
                break;
            }
            case 'e': 
             {
                system("clear");
                abrirMenuEngenheiro(engenheiros, ordensAtuais);
                break;
            }
         
            case 'd': 
             {
                system("clear");
                abrirMenuContador(ct1, ordensAtuais);
                break;
            }   
            case 't': 
             {
                system("clear");
                abrirMenuOrcamentista(orcamentistas, propostasAtuais);
                break;
            }
        }
        system("clear");
    }
 
    numOrdemAtual -= 1;
    numPropostaAtual -= 1;


    //reabertura dos arquivos para operações de sobrescrita
    std::ofstream arqAux1("./database/Propostas.txt", std::ios::trunc);
    std::ofstream arqAux2("./database/Ordens.txt", std::ios::trunc);
    std::ofstream arqAux3("./database/ultimaOrdem.txt", std::ios::trunc);
    std::ofstream arqAux4("./database/ultimaProposta.txt", std::ios::trunc);
    
    arqAux3 << numOrdemAtual;
    arqAux4 << numPropostaAtual;
    
    for(auto it = ordensAtuais.begin(); it != ordensAtuais.end(); it++)
    {
        arqAux2 << **it;
    }
    for(auto it = propostasAtuais.begin(); it != propostasAtuais.end(); it++)
    {
        arqAux1 << **it;
    }
    //após guardar os dados, os arquivos são fechados
    arqAux1.close();
    arqAux2.close();
    arqAux3.close();
    arqAux4.close();
    
    for(int i = 0; i < engenheiros.size(); i++)
    {
        delete engenheiros.at(i);
    }

    for(int i = 0; i < orcamentistas.size(); i++)
    {
        delete orcamentistas.at(i);
    }

    delete ct1;

    for(int i = 0; i < propostasAtuais.size(); i++)
    {
        delete propostasAtuais.at(i);
    }

    for(int i = 0; i < ordensAtuais.size(); i++)
    {
        delete ordensAtuais.at(i);
    }
    
    return 0;
}
