#pragma once
#ifndef VENDAS_H
#define VENDAS_H

#include <string>
#include <libpq-fe.h>

using namespace std;

int adicionarVenda(PGconn* conn, const string& clienteNome, float total, int quantidade, string& descricaoProdutos);

#endif // VENDAS_H
