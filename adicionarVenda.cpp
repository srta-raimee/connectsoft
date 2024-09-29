#include "vendas.h"
#include <iostream>
#include <libpq-fe.h>  
#include <string>

using namespace std;

// PRECISA CRIAR LOGICA DE DIMINUIR ESTOQUE CASO O ITEM SEJA COMPRADO

int adicionarVenda(PGconn* conn, const string& clienteNome, float total, int quantidade, string& descricaoProdutos) {
    // query para inserir na tabela de vendas e retornar o ID gerado
    string query = "INSERT INTO vendas (cliente_nome, total) VALUES ('" +
        clienteNome + "', " + to_string(total) + ") RETURNING id;";

    PGresult* res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        cerr << "Falha na inserção de venda: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        return 2;
    }

    // pegando o primeiro resultado da primeira linha e coluna
    string venda_id = PQgetvalue(res, 0, 0);
    PQclear(res);

    // query para inserir na tabela de detalhes da venda associando o venda_id
    string query2 = "INSERT INTO detalhes_venda (venda_id, quantidade, preco_total, descricao_produtos) VALUES (" +
        venda_id + ", " + to_string(quantidade) + ", " + to_string(total) + ", '" + descricaoProdutos + "');";

    res = PQexec(conn, query2.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        cerr << "Falha na inserção de detalhes de venda: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        return 3;
    }

    cout << "Venda e detalhes adicionados com sucesso!" << endl;

    PQclear(res);
    return 0;
}
