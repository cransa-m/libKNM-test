/* Functions prototypes */
int 	test(int, char**, char**);

/* Default includes (C++ version) */
#ifdef __cplusplus
#include <iostream>
#include <string>
#include <list>
#endif

/* Default includes (C version) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Put your own includes here */
#include <KFS.hh>

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

 bool compare_nocase (const std::string* str1, const std::string* str2)
 {
 	unsigned int i=0;
 	string first = *str1;
 	string second = *str2;
 	while ( (i < first.length()) && (i < second.length()) )
 	{
 		if (tolower(first[i]) < tolower(second[i]))
 			return true;
 		else if (tolower(first[i]) > tolower(second[i]))
 			return false;
 		++i;
 	}
 	return ( first.length() < second.length() );
 }

 void		affCurrentFolder(KFS &k)
 {
 	list<string *> list = k.list();
 	list.sort(compare_nocase);
 	std::list<string *>::iterator it;
 	cout << "=====current folder : " << endl;
 	for (it = list.begin(); it != list.end() ; ++it)
 	{
 		cout << **it << endl;
 	}
 	cout << "=====" << endl;
 }


 int 		test(	int __attribute__((__unused__))ac, 
 	char __attribute__((__unused__))**av,
 	char __attribute__((__unused__))**env)
 {
	/* Put your code from here... */

 	KFS k;
 	cout << "Current path = " << k.pwd() << endl;
 	cout << "Create a new folder : \"testFolder\"" << endl;
 	k.mkdir("testFolder");
 	affCurrentFolder(k);
 	cout << "Current path = " << k.pwd() << endl;

 	cout << "Go to the folder created (\"testFolder\")" << endl;
 	k.chdir("./testFolder");
 	cout << "Current path = " << k.pwd() << endl;
 	
 	cout << "Create new file : \"testFile\"" << endl;
 	k.mkfile("testFile");
 	affCurrentFolder(k);

 	cout << "Copy \"testFile\" to \"testFileCopy\"" << endl;
 	k.copy("testFile", "testFileCopy");
 	affCurrentFolder(k);

 	cout << "Move \"testFileCopy\" to \"testFileMove\"" << endl;
 	k.move("testFileCopy", "testFileMove");
 	affCurrentFolder(k);

	cout << "Temove \"testFileMove\"" << endl;
 	k.remove("testFileMove");
 	affCurrentFolder(k);

 	cout << "Try create file : \"testFile\" to generate a error" << endl;
 	k.mkfile("testFile");
 	affCurrentFolder(k);

 	cout << "Is last instruction ok ? : " << boolalpha << k.success() << endl;
 	cout << "Error is : " << k.getError() << endl;

 	cout << "Go to the parent folder" << endl;
 	k.chdir("..");
 	cout << "Current path = " << k.pwd() << endl;
	affCurrentFolder(k);

 	cout << "Delete folder : \"testFolder\"" << endl;
 	k.remove("testFolder");
 	affCurrentFolder(k);

 	cout << "Is last instruction ok ? : " << boolalpha << k.success() << endl;
 	cout << "Error is : " << k.getError() << endl;

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
