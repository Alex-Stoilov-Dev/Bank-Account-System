#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <mysql/mysql.h>
#include "includes/db_manager.hpp"
#include "includes/config.hpp"

dbManager::dbManager() : database(Config::DB_name.data()),    
                user(Config::DB_user.data()),
                password(Config::DB_pass.data()),
                server(Config::DB_host.data()) {}

dbManager::dbManager(const char *DB_name, const char *DB_user, const char *DB_pass, const char *DB_host)
                    : database(DB_name), user(DB_user), password(DB_pass), server(DB_host) {}

dbManager::~dbManager() {};

MYSQL *dbManager::mysql_connection_setup() {
  MYSQL *connection = mysql_init(nullptr);

  if (!mysql_real_connect(connection, server, user, password, database, 0, NULL,
                          0)) {
    std::cout << "Connection Error: " << mysql_error(connection) << '\n';
    exit(1);
  }

  return connection;
}

MYSQL_RES *dbManager::execute_sql_query(MYSQL *connection, const char *sql_query) {
  if (mysql_query(connection, sql_query)) 
  {
    std::cout << "My SQL Query Error: " << mysql_error(connection) << '\n';
    exit(1);
  }
  return mysql_use_result(connection);
}

