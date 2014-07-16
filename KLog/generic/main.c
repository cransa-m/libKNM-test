/* Functions prototypes */
int 	test(int, char**, char**);

/* Default includes (C++ version) */
#ifdef __cplusplus
#include <iostream>
#include <string>
#endif

/* Default includes (C version) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Put your own includes here */
#include <KLog.hh>

/* Namespace configuration if C++ */
#ifdef __cplusplus
using namespace std;
#endif


/* Customize options here.
 * Note: RETURN_* have to be set according to test.sh script.
 * By default, 0=success, 1=fail.
 */
#define ARGS_MIN		1
#define RETURN_SUCCESS	0
#define RETURN_FAIL		1

 using namespace KNM;

 int 		test(	int __attribute__((__unused__))ac, 
 	char __attribute__((__unused__))**av,
 	char __attribute__((__unused__))**env)
 {
	/* Put your code from here... */

  KLog log1;

  cout << "set logfile : \"testLog1.log\"" << endl;
  log1.setFile("testLog1.log");

  cout << "write log \"default1\" with the default (info) level" << endl;
  log1.write("default1");

  cout << "write log \"critical1\" with the critical level" << endl;
  log1.write(CRITICAL, "critical1");

  cout << "write log \"error1\" with the error level" << endl;
  log1.write(ERROR, "error1");

  cout << "write log \"warning1\" with the waring level" << endl;
  log1.write(WARNING, "warning1");

  cout << "write log \"info1\" with the info level" << endl;
  log1.write(INFO, "info1");

  cout << "set the default level to WARNING" << endl;
  log1.setLevel(WARNING);

  cout << "write log \"default2\" with the default (warning) level" << endl;
  log1.write("default2");

  cout << "set min level to ERROR" << endl;
  log1.setMinLevel(ERROR);

  cout << "write log \"info2\" with the info level (should not be written)" << endl;
  log1.write(INFO, "info2");

  cout << "write log \"warning2\" with the waring level (should not be written)" << endl;
  log1.write(WARNING, "warning2");

  cout << "write log \"critical2\" with the critical level" << endl;
  log1.write(CRITICAL, "critical2");

  cout << "write log \"error2\" with the error level" << endl;
  log1.write(ERROR, "error2");


    /* ... and stop writing here. */
  return(RETURN_SUCCESS);
}

int 		main(int ac, char **av, char **env)
{
	if (ac < ARGS_MIN)
	{
		printf("args error: %d passed, %d expected\n", ac, ARGS_MIN);
		return(RETURN_FAIL);
	}
	printf("Starting test\n");
	return(test(ac, av, env));
}
