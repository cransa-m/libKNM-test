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
#include <KError.hh>

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

  try
  {
    throw KError("first message", "second message");
  }
  catch (KError e)
  {
    cout << "exexute dump : ";
    e.dump();
    cout << "write what : " << e.what() << endl;
    cout << "error number : " << e.errnum() << endl;
  }

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
