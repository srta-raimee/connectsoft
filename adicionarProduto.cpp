#include "produtos.h"
#include <iostream>
#include <libpq-fe.h>  
#include <string>

using namespace std;

int adicionarProduto(PGconn* conn, const string& nomeProduto, float valorProduto, int quantidade) {
    string query = "INSERT INTO produtos (nome, valor, quantidade) VALUES ('" +
        nomeProduto + "', " + to_string(valorProduto) + ", " + to_string(quantidade) + ");";

    // Executar a consulta SQL
    PGresult* res = PQexec(conn, query.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        cerr << "Falha na inserção de dados: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        return 2; 
    }

    std::cout << "Produto adicionado com sucesso!" << std::endl;

    // apenas para limpar o resultado/memoria
    PQclear(res);
    return 0; 
}
