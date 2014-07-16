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
#include <KAlert.hh>

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

//init static variable
KAlert::list KAlert::lst;

 int 		test(	int __attribute__((__unused__))ac, 
 	char __attribute__((__unused__))**av,
 	char __attribute__((__unused__))**env)
 {
	/* Put your code from here... */

    //      LOG,INFO,WARNING,ERROR,CRITICAL

    // first form to set KAlert
    KAlert kalert1;
    kalert1.setLevel(LOG);
    kalert1.setOrig("orig1");
    kalert1.setType("type1");
    kalert1.setData("data1");
    // insert inside the static list
    KAlert::lst.insert(kalert1);

    // second form to set KAlert
    KAlert kalert2;
    kalert2.set(LOG, "orig2", "type2", "data2");
    // insert inside the static list
    KAlert::lst.insert(kalert2);

    KAlert kalert3;
    kalert3.set(INFO, "orig3", "type3", "data3");
    KAlert::lst.insert(kalert3);

    KAlert kalert4;
    kalert4.set(WARNING, "orig4", "type4", "data4");
    KAlert::lst.insert(kalert4);

    KAlert kalert5;
    kalert5.set(ERROR, "orig5", "type5", "data5");
    KAlert::lst.insert(kalert5);

    KAlert kalert6;
    kalert6.set(CRITICAL, "orig6", "type6", "data6");
    KAlert::lst.insert(kalert6);

    KAlert kalert7;
    kalert7.set(INFO, "orig7", "type7", "data7");
    KAlert::lst.insert(kalert7);

    KAlert kalert8;
    kalert8.set(CRITICAL, "orig8", "type8", "data8");
    KAlert::lst.insert(kalert8);

    KAlert kalert9;
    kalert9.set(ERROR, "orig9", "type9", "data9");
    KAlert::lst.insert(kalert9);

    KAlert kalert10;
    kalert10.set(WARNING, "orig10", "type10", "data10");
    KAlert::lst.insert(kalert10);

    KAlert kalert11;
    kalert11.set(CRITICAL, "orig11", "type11", "data11");
    KAlert::lst.insert(kalert11);

    KAlert kalert12;
    kalert12.set(INFO, "orig12", "type12", "data12");
    KAlert::lst.insert(kalert12);

    KAlert kalert13;
    kalert13.set(LOG, "orig13", "type13", "data13");
    KAlert::lst.insert(kalert13);

    KAlert kalert14;
    kalert14.set(LOG, "orig14", "type14", "data14");
    KAlert::lst.insert(kalert14);

    cout << "list limit : " << KAlert::lst.getLimit() << endl;
    cout << "Get Last alert (expected \"data14\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "get first priority alert (expected \"data11\") : " << KAlert::lst.getPrior().getData() << endl;
    cout << "set limit to 5" << endl;
    KAlert::lst.setLimit(5);
    cout << "get first priority alert (expected \"data8\") : " << KAlert::lst.getPrior().getData() << endl;
    cout << "get first priority alert (expected \"data6\") : " << KAlert::lst.getPrior().getData() << endl;
    cout << "get first priority alert (expected \"data9\") : " << KAlert::lst.getPrior().getData() << endl;
    cout << "Get Last alert (expected \"data13\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "Get Last alert (expected \"data12\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "Get Last alert (expected \"data10\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "Get Last alert (expected \"data7\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "insert 3 new alerts" << endl;

    KAlert kalert15;
    kalert15.set(WARNING, "orig15", "type15", "data15");
    KAlert::lst.insert(kalert15);

    KAlert kalert16;
    kalert16.set(CRITICAL, "orig16", "type16", "data16");
    KAlert::lst.insert(kalert16);

    KAlert kalert17;
    kalert17.set(INFO, "orig17", "type17", "data17");
    KAlert::lst.insert(kalert17);


    cout << "get first priority alert (expected \"data16\") : " << KAlert::lst.getPrior().getData() << endl;
    cout << "get first priority alert (expected \"data5\") : " << KAlert::lst.getPrior().getData() << endl;
    cout << "Get Last alert (expected \"data17\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "Get Last alert (expected \"data15\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "Get Last alert (expected \"data4\") : " << KAlert::lst.getLast().getData() << endl;
    cout << "Get Last alert (expected empty) : " << KAlert::lst.getLast().getData() << endl;
    cout << "get first priority alert (expected empty) : " << KAlert::lst.getPrior().getData() << endl;


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
