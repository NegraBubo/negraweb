#ifndef DBCONNECT_H
#define DBCONNECT_H
#pragma once

#include <cppconn/driver.h>
#include "mysql_connection.h"

	

	
class DBConnect  
{
	private:
	sql::Connection *con;

	public:

		DBConnect();

		~DBConnect();

};
#endif