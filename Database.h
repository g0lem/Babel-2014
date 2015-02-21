#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

class DB
{
public:
	static int callback(void *data, int argc, char **argv, char **azColName)
	{
		int i;
		fprintf(stderr, "%s: ", (const char*)data);
		for (i = 0; i<argc; i++){
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	}	

	static void ConsoleOutput()
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int rc;
		char *sql;
		const char* data = "Callback function called";

		rc = sqlite3_open("Insight.db", &db);
		if (rc){
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			exit(0);
		}
		else{
			fprintf(stderr, "Opened database successfully\n");
		}

		sql = "SELECT * from StaticObjects";

		rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else{
			fprintf(stdout, "Operation done successfully\n");
		}
		system("pause");
		sqlite3_close(db);
	}

	static void Load_Data(sf::RenderWindow &Window, b2World *&world)
	{
		sqlite3 *db;
		sqlite3_stmt *res;
		const char *tail;
		int count = 0;

		if (sqlite3_open("Insight.db", &db))
		{
			sqlite3_close(db);
			printf("Can't open database: %s\n", sqlite3_errmsg(db));
			
		}

		printf("Database connection okay!\n");

		if (sqlite3_prepare_v2(db, "SELECT * FROM StaticObjects", 128, &res, &tail) != SQLITE_OK)
		{
			sqlite3_close(db);
			printf("Can't retrieve data: %s\n", sqlite3_errmsg(db));
		}

		printf("Reading data...\n");
		
		while (sqlite3_step(res) == SQLITE_ROW)
		{
			std::cout << sqlite3_column_int(res, 1) << " " << sqlite3_column_int(res, 2) << std::endl;
			Engine::createBox(Window, *world, (float)(sqlite3_column_int(res, 1)), (float)(sqlite3_column_int(res, 2)), 40, 40, 1);					
		}	

		sqlite3_finalize(res);

		sqlite3_close(db);
	}


	static void AddStaticBox(int id, int x, int y, int width, int height)
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int rc;

		rc = sqlite3_open("Insight.db", &db);
		if (rc){
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			exit(0);
		}
		else{
			fprintf(stderr, "Opened database successfully\n");
		}

		sqlite3_stmt *stmt;
		const char* sql = "insert into StaticObjects values(?,?,?,?,?)";
		sqlite3_prepare(db, sql, strlen(sql), &stmt, 0);
		sqlite3_bind_int(stmt, 1, id);
		sqlite3_bind_int(stmt, 2, x);
		sqlite3_bind_int(stmt, 3, y);
		sqlite3_bind_int(stmt, 4, width);
		sqlite3_bind_int(stmt, 5, height);
		sqlite3_step(stmt);
		sqlite3_finalize(stmt);

		if (rc != SQLITE_OK){
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else{
			fprintf(stdout, "Records created successfully\n");
		}
		sqlite3_close(db);
	}

};
#endif