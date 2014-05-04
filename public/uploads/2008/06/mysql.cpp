#include <stdio.h>
#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main() {

    char host[30] = "localhost";
    char user[30] = "c";
    char pass[30] = "test";
    char db[30] = "c";
    char sql[100] = "SELECT * FROM users";
    long result;
        
    MYSQL dblink;
    MYSQL_RES *rs;
    MYSQL_ROW r;
    
    cout << "MySQL init ";
    if(mysql_init(&dblink)) {
	cout << "OK" << endl;
    } else {
	cout << "blad: " << mysql_error(&dblink) << endl;
    }
    
    cout << "MySQL connect ";
    if(mysql_real_connect(&dblink, host, user, pass, db, 0, NULL, 0)) {
	cout << "OK" << endl;
	cout << "MySQL query ";
        result = mysql_real_query(&dblink, sql, strlen(sql));
	if(result != 0) {
	    cout << "blad: " << mysql_error(&dblink) << endl;
        } else {
	    cout << "OK" << endl;
	    cout << "MySQL store result ";
	    rs = mysql_store_result(&dblink);
	    if(rs) {
		cout << "OK" << endl;
		unsigned int num_fields;
		num_fields = mysql_num_fields(rs);
		while(r = mysql_fetch_row(rs)) {
		    unsigned long *lengths;
		    lengths = mysql_fetch_lengths(rs);
		    
		    unsigned int i;
		    for(i = 0; i < num_fields; i++) {
			printf("[%.*s] ", (int) lengths[i], r[i] ? r[i] : "NULL");
		    }

		}
		mysql_free_result(rs);
		cout << endl;
	    } else {
		if(mysql_field_count(&dblink) == 0) {
		    result = mysql_affected_rows(&dblink);
		} else {
		    cout << "blad: " << mysql_error(&dblink);
		}
	    }
        }
    } else {
	cout << "blad: " << mysql_error(&dblink) << endl;
    }

    mysql_close(&dblink);
    cout << "MySQL disconnect OK" << endl;    
    return 0;
}
