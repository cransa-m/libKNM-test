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
#include <dyn/KModule.hpp>
#include <base/KError.hh>
#include "Module/ModuleTest.hh"

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

 	string pathLib = "./testModule.so.1.0";
 	string mod = "TestModule";
 	KModule<TestModule> k;
 	k.set_module(pathLib);
 	k.set_builder("get" + mod);
 	k.set_destroyer("del" + mod);

 	try
 	{
 		k.init();
 	}
 	catch (KError *e)
 	{
 		cout << e->what() << endl;
 	}

 	TestModule *tm = k.create();
	if (tm == NULL)
	  cout << "Test Failed, module == null" << endl;
	
	tm->write("ceci est un test");
// 	cout << tm->retString() << endl;
// 	cout << tm->retInt() << endl;
// 	cout << boolalpha << tm->retBool() << endl;


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
