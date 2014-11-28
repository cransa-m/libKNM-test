/**
 * Test main for libKNM.
 * This code can compile with GCC and G++.
 */

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
//#include <data/KTree.hpp>
#include <base/KError.hh>
#include <data/KTree.hpp>

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

 	KTree<string>	tree1;
 	KTree<string>	*tree2;
 	KTree<string>::leaf<string>	*leaf1;

 	list<const string* > listnodes;
 	list<const string* > listleaves;
 	std::list<const string* >::iterator it;

 	try
 	{
 		tree1.insert(".n1.l1", "value1" );
 		tree1.insert(".n1.l2", "value2" );
 		tree1.insert(".n1.l3", "value3" );
 		tree1.insert(".n1.l4", "value4" );
 		tree1.insert(".n1.n3.l1", "value1" );
 		tree1.insert(".n1.n3.l2", "value2" );
 		tree1.insert(".n1.n3.l3", "value3" );
 		tree1.insert(".n1.n3.l4", "value4" );

 		tree1.insert(".n2.l10", "value5" );
 		tree1.insert(".n2.l20", "value6" );
 		tree1.insert(".n2.l30", "value7" );
 		tree1.insert(".n2.l40", "value8" );

 		tree1.insert(".l5", "value9" );
 		tree1.insert(".l6", "value10" );
 		tree1.insert(".l7", "value11" );
 		tree1.insert(".l8", "value12" );
 		tree1.mknode(".n4");

 		cout << "Number of leaves at the racine : " << tree1.count_leafs(".") << endl;
 		cout << "Number of nodes at the racine : " << tree1.count_nodes(".") << endl;

 		cout << "Number of leaves at \"n1\" : " << tree1.count_leafs(".n1") << endl;
 		cout << "Number of nodes at \"n1\" : " << tree1.count_nodes(".n1") << endl;

 		cout << "Number of leaves at \"n2\" : " << tree1.count_leafs(".n2") << endl;
 		cout << "Number of nodes at \"n2\" : " << tree1.count_nodes(".n2") << endl;

 		cout << boolalpha << "is n1 a node?" << tree1.is_node(".n1") << endl;
 		cout << boolalpha << "is n1 a leaf?" << tree1.is_leaf(".n1") << endl;

 		cout << boolalpha << "is l5 a node?" << tree1.is_node(".l5") << endl;
 		cout << boolalpha << "is l5 a leaf?" << tree1.is_leaf(".l5") << endl;

 		cout << boolalpha << "is .n1.l1 a node?" << tree1.is_node(".n1.l1") << endl;
 		cout << boolalpha << "is .n1.l1 a leaf?" << tree1.is_leaf(".n1.l1") << endl;

 		cout << "find l5 : " << tree1.find("l5") << endl;
 		
		try
 		{
 			cout << "find value9 : " << tree1.find("value9") << endl;
 		}
 		catch (KError *e)
 		{
 			e->dump();
		}

 		tree1.describe(".", &listleaves, &listnodes);

 		cout << "nodes at the racines : " << endl;
 		for (it = listnodes.begin() ; it != listnodes.end() ; it++)
 		{
 			cout << "- " << **it << endl;
 		}

 		cout << "leaves at the racines : " << endl;
 		for (it = listleaves.begin() ; it != listleaves.end() ; it++)
 		{
 			cout << "- " << **it << endl;
 		}

 		tree2 = tree1.getNode("n1");
 		if (tree2 == NULL)
 			cout << "tree2 == NULL" << endl;
 		listleaves.clear();
 		listnodes.clear();

 		cout << "Number of leaves at \"n1\" : " << tree2->count_leafs(".") << endl;
 		cout << "Number of nodes at \"n1\" : " << tree2->count_nodes(".") << endl;


 		tree2->describe(".", &listleaves, &listnodes);

 		cout << "nodes at \".n1\" : " << endl;
 		for (it = listnodes.begin() ; it != listnodes.end() ; it++)
 		{
 			cout << "- " << **it << endl;
 		}

 		cout << "leaves at \".n1\" : " << endl;
 		for (it = listleaves.begin() ; it != listleaves.end() ; it++)
 		{
 			cout << "- " << **it << endl;
 		}

 		leaf1 = tree2->getLeaf("l1");
 		if (leaf1 == NULL)
 			cout << "leaf1 == NULL" << endl;

 		cout << "===== leaf1 infos =====" << endl;
 		cout << "name = " << leaf1->getName() << endl;
 		cout << "data = " << leaf1->getData() << endl;
 		leaf1->rename("leafRenamed");
 		leaf1->assign("leafReassigned");
 		cout << "name = " << leaf1->getName() << endl;
 		cout << "data = " << leaf1->getData() << endl;
 		*leaf1 = "leafReassignedwithequal";
 		cout << "name = " << leaf1->getName() << endl;
 		cout << "data = " << leaf1->getData() << endl;
 	}
 	catch (KError *e)
	{
	 	e->dump();
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
