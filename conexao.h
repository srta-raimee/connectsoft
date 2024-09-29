#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H
#include <libpq-fe.h>

PGconn* conectarDB(const char* conninfo);

#endif // DB_CONNECTION_H