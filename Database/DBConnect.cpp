#include "DBConnect.hpp"  

#include <cppconn/resultset.h>
#include <cppconn/statement.h>


	
DBConnect::DBConnect()
{
	try {
            sql::Driver *driver;           
            sql::Statement *stmt;
            sql::ResultSet *res;

            /* Create a connection */
            driver = get_driver_instance();
            con = driver->connect("tcp://34.122.240.33", "root", "root");

            /* Connect to the MySQL test database */
            con->setSchema("negradb");

        
                delete res;
                delete stmt;

     } catch (sql::SQLException &e) {
            std::cout << "# ERR: SQLException ";
          
    }
}
	
DBConnect::~DBConnect()
{
	
}