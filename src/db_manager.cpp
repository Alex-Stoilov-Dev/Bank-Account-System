#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <mysql/mysql.h>
#include <vector>
#include "includes/db_manager.hpp"
#include "includes/config.hpp"

dbManager::dbManager()
              : database(Config::DB_name.data()), user(Config::DB_user.data()),
                password(Config::DB_pass.data()), server(Config::DB_host.data())
                {} // This constructor allows you to create your DB manager without requirying all your DB credentials.
                // The credentials are pulled directly from the "config.hpp" file or "example-config.hpp"

dbManager::dbManager(const char *DB_name, const char *DB_user, const char *DB_pass, const char *DB_host)
                    : database(DB_name), user(DB_user), password(DB_pass), server(DB_host)
                    {} // This constructor allows you to use a custom database.
                    // This is similar to how you would setup a database in WordPress's "wp-config.php"

dbManager::~dbManager() {};

MYSQL *dbManager::mysql_connection_setup() // This function initializes a connection to the database on the server.
{
  MYSQL *connection = mysql_init(nullptr);

  if (!mysql_real_connect(connection, server, user, password, database, 0, NULL,
                          0)) {
    std::cout << "Connection Error: " << mysql_error(connection) << '\n';
    exit(1);
  }

  return connection;
}

MYSQL_RES *dbManager::execute_sql_query(MYSQL *connection, const char *sql_query) // this function takes in a connection, and a query and executes it to the database.
{
  if (mysql_query(connection, sql_query))
  {
    std::cout << "My SQL Query Error: " << mysql_error(connection) << '\n';
    exit(1);
  }
  return mysql_use_result(connection);
}

void dbManager::create_db() // This functions creates the app's database and creates the two basic tables required by the application.
{
  MYSQL_RES *result;
  std::vector<const char*> queries = {
                    "CREATE DATABASE IF NOT EXISTS alex_banking_app;",
                    "CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, username VARCHAR(50), pin_hashed CHAR(32), balance DECIMAL(15,2) DEFAULT 0.00);",
                    "CREATE TABLE IF NOT EXISTS transaction_history (transaction_id INT AUTO_INCREMENT,"
                                                                        "user_id INT, time DATETIME,"
                                                                        "deposited DECIMAL(15, 2) default 0.00, "
                                                                        "widthdrawn DECIMAL(15, 2),"
                                                                        "FOREIGN KEY(user_id) REFERENCES users(id),"
                                                                        "PRIMARY KEY (transaction_id) )"
                                      };
  std::vector<const char*>::iterator query;
  for (query = queries.begin(); query != queries.end(); query++){
    result = this->execute_sql_query(this->mysql_connection_setup(), *query);
    if( result != nullptr){
      mysql_free_result(result);
      result = nullptr;
    }
  }
}

/*
dbManager DB{};

DB.create_db();

const char* query;

MYSQL *DB_conn = DB.mysql_connection_setup();

std::string query_str = std::format("SELECT username FROM users;");

query = query_str.c_str();

MYSQL_RES *result = DB.execute_sql_query(DB_conn, query);

std::string fetched_info;

if(result){
  MYSQL_ROW row;

  if((row = mysql_fetch_row(result)))
  {
    if (row[0]){
      fetched_info = row[0];
    }
  }
}

std::cout << fetched_info;
*/
