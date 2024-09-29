#pragma once
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <libpq-fe.h>

using namespace std;

int addFuncionario(PGconn* conn, const string& funcNome, const string& cargo, const string& email, const string& telefone, const string& endereco);

#endif // FUNCIONARIO_H
