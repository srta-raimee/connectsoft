## Para conectar C++ Visual Studio ao banco de dados POSTGRESQL:

- Certifique-se que a pasta BIN do POSTGRESQL está em Variáveis de Ambiente.

- Com o projeto aberto, vá para:
Projeto -> Connectsoft Propriedades -> C/C++ -> Geral 

- Adicione o diretório INCLUDE do Postgres em "Diretórios de Inclusão Adicionais"
exemplo: C:\Program Files\PostgreSQL\16\include

- Na mesma janela, vá para:
Vinculador -> Geral

- Em "Diretórios de Biblioteca Adicionais", adicione o diretório LIB do Postgres.
exemplo: C:\Program Files\PostgreSQL\16\lib

- Ainda em Vinculador, vá até Entrada e adicione em "Dependências Adicionais" o arquivo libpq.lib.

Pronto! Ele estará conectado e pronto para uso.

### Exemplo de arquivo de conexão:

include "conexao.h"
include <iostream>

using namespace std;

PGconn* conectarDB(const char* conninfo) {
    PGconn* conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        cerr << "Falha na conexão com o banco de dados: " << PQerrorMessage(conn) << endl;
        PQfinish(conn);
        return nullptr;
    }
    else cout << "Conectado ao Banco de Dados com sucesso!";

    return conn;
}
