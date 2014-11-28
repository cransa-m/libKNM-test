/* Functions prototypes */
int 	test(int, char**, char**);

/* Default includes (C++ version) */
#ifdef __cplusplus
#include <functional>
#include <iostream>
#include <string>
#endif

/* Default includes (C version) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Put your own includes here */
#include <dyn/KDylib.hh>
#include <base/KError.hh>

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

 	KDylib dl1;
 	void (*func)();
 	int *(*retFunc)();
 	int *i;


 	cout << "set path" << endl;
 	dl1.setPath("./testDyLib.so.1.0");
 	cout << "Is lybrary opended? : " << boolalpha << dl1.isOpen() << endl;
 	cout << "Open Lybrary "<< endl;
 	dl1.open();
 	cout << "is Error ? : " << dl1.error() << endl;
 	cout << "Is lybrary opended? : " << boolalpha << dl1.isOpen() << endl;
 	cout << "add one to i with the library" << endl;
 	try
 	{
 		func = (void (*)())dl1.symbol("initFoo");
 		func();

		func = (void (*)())dl1.symbol("addOne");
 		func();

		func = (void (*)())dl1.symbol("addTen");
 		func();

		func = (void (*)())dl1.symbol("minusOne");
 		func();

 		retFunc = (int *(*)())dl1.symbol("getFoo");
 		i = retFunc();
 		cout << *i << endl;

		func = (void (*)())dl1.symbol("addTen");
 		func();

		cout << *i << endl;
 	}
 	catch (KError e)
 	{
 		cout << e.what() << endl;
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
