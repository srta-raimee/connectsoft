#include "conexao.h"
#include <iostream>

using namespace std;

PGconn* conectarDB(const char* conninfo) {
    PGconn* conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        cerr << "Falha na conex�o com o banco de dados: " << PQerrorMessage(conn) << endl;
        PQfinish(conn);
        return nullptr;
    }
    else cout << "Conectado ao Banco de Dados com sucesso!";

    return conn;
}
