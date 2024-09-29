#pragma once
#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string>
#include <libpq-fe.h>

using namespace std;

int adicionarProduto(PGconn* conn, const string& nomeProduto, float valorProduto, int quantidade);

#endif // PRODUTOS_H
