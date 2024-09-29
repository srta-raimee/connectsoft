#include <string>
#include <libpq-fe.h>
#include <iostream>

#include "conexao.h"
#include "produtos.h"
#include "vendas.h"
#include "menu.h"
#include "funcionario.h"

int abrirMenu() {

    int opcaoMenu;

    const char* conninfo = "dbname=connectsoft user=postgres password=3016 hostaddr=127.0.0.1 port=5432";
    // funcao definida em conexao.cpp para realizar conexao com o banco de dados
    PGconn* conn = conectarDB(conninfo);

    if (conn == nullptr) {
        return 1;
    }

    // menu para escolher a acao a ser realizada
    cout << "\n Digite a operacao que deseja realizar: \n (1) Adicionar Produto \n (2) Registrar Venda "
        << "\n (3) Registrar Funcionario \n (4) Registrar Fornecedor \n (5) Registrar Compras para o inventario \n ";
    cin >> opcaoMenu;

    // switch - case para opcoes do menu
    switch (opcaoMenu) {

    case 1: // (1) Adicionar Produto
    {
        string nomeProduto;
        float valor;
        int quantidade;


        cout << "\n Voce selecionou (1) \n";
        cout << "\n Digite o nome do produto a ser adicionado: ";
        cin.ignore();
        getline(cin, nomeProduto);

        cout << "\n Digite o valor do produto a ser adicionado: ";
        cin >> valor;

        cout << "\n Digite a quantidade do produto a ser adicionado: ";
        cin >> quantidade;

        adicionarProduto(conn, nomeProduto, valor, quantidade);

    }
    break;

    case 2: // (2) Registrar Venda
    {
        string clienteNome;
        float total;
        int quantidade;
        string descricaoProdutos;

        cout << "\n Voce selecionou (2) \n";
        cout << "\n Digite o nome do cliente: ";
        cin.ignore();
        getline(cin, clienteNome);

        cout << "\n Digite o valor total da compra: ";
        cin >> total;

        cout << "\n Digite a quantidade de produtos vendidos: ";
        cin >> quantidade;

        cout << "\n Digite a descricao dos produtos da venda: ";
        cin.ignore();
        getline(cin, descricaoProdutos);

        adicionarVenda(conn, clienteNome, total, quantidade, descricaoProdutos);
    }
    break;


    case 3: // (3) adicionar funcionario
    {
        string nome, cargo, email, telefone, endereco;

        cout << "\n Voce selecionou (3) \n";
        cout << "\n Digite o nome do funcionario: ";
        cin.ignore();
        getline(cin, nome);

        cout << "\n Digite o cargo: ";
        /*cin.ignore();*/
        getline(cin, cargo);

        cout << "\n Digite o email: ";
       /* cin.ignore();*/
        getline(cin, email);

        cout << "\n Digite o telefone: ";
       /* cin.ignore();*/
        getline(cin, telefone);

        cout << "\n Digite o endereco: ";
       /* cin.ignore();*/
        getline(cin, endereco);



        addFuncionario(conn, nome, cargo, email, telefone, endereco);
    }

    break;

    default:
    {
        cout << "Opcao invalida" << endl;
        break;
    }


    }
    PQfinish(conn);

    return 0;
}