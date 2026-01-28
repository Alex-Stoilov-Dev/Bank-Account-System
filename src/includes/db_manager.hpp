//#include <cstddef>
//#include <cstdlib>
//#include <iostream>
#include <mysql/mysql.h>


class dbManager {

public:
  dbManager();
  dbManager(const char *serv, const char *usr, const char *pass, const char *db);
  ~dbManager();
  dbManager(const dbManager &);
  dbManager operator=(const dbManager);

  MYSQL *mysql_connection_setup();

  MYSQL_RES *execute_sql_query(MYSQL *connection, const char *sql_query);
  void create_db();

private:
  const char *database, *user, *password, *server;

};


