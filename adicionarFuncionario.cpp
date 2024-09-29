#include "funcionario.h"
#include <iostream>
#include <libpq-fe.h>  
#include <string>

using namespace std;

int addFuncionario(PGconn* conn, const string& funcNome, const string& cargo, const string& email, const string& telefone, const string& endereco)
{
    // query para inserir na tabela de vendas e retornar o ID gerado
    string query = "INSERT INTO funcionarios (nome, cargo, contato_telefone, contato_email, endereco) VALUES ('" +
        funcNome + "', '" +
        cargo + "', '" +
        email + "', '" +
        telefone + "', '" +
        endereco + "') ;";

    PGresult* res = PQexec(conn, query.c_str());


    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        cerr << "Falha na inserção de funcionario: " << PQerrorMessage(conn) << endl;
        PQclear(res);
        return 2;
    }

  

    cout << "Funcionario adicionado com sucesso!" << endl;

    PQclear(res);
    return 0;
}
