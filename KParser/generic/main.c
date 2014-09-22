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
#include <KParser.hh>
#include <KError.hh>
#include <KTree.hpp>

/* Namespace configuration if C++ */
#ifdef __cplusplus
using namespace std;
#endif


/* Customize options here.
 * Note: RETURN_* have to be set according to test.sh script.
 * By default, 0=success, 1=fail.
 */
#define ARGS_MIN		3
#define RETURN_SUCCESS	0
#define RETURN_FAIL		1

 using namespace KNM;

 void displayTree(KTree<string> &tree)
 {
  list <const string *> listnode;
  list <const string *> listleaf;

  std::list<const string *>::iterator it;

  tree.describe("/", &listleaf, &listnode);

  for (it = listnode.begin() ; it != listnode.end() ; it++)
  {
    try
    {
      cout << "node = " << **it << " // leaf = " << tree.find(**it) << endl;
    }
    catch (KError *err)
    {
      cout << "node \"" << **it << "\" has no value -- error message : " << err->what() << endl;
    }
  }

}

int 		test(	int __attribute__((__unused__))ac, 
  char __attribute__((__unused__))**av,
  char __attribute__((__unused__))**env)
{
	/* Put your code from here... */

  // av[1] = option1.cfg -> valid file

  KParser parser1;
  KTree<string>   tree1;

  KParser parser2;
  KTree<string>   tree2;

  KParser parser3;
  KTree<string>   tree3;

  KParser parser4;
  KTree<string>   tree4;

  KParser parser5;
  KTree<string>   tree5;

  KParser parser6;
  KTree<string>   tree6;

  try
  {
    parser1.set_source(av[1]);
    parser1.set_tree(&tree1);
    parser1.parse();
    cout << "========== good file ==========" << endl;

    // count lead and nodes
    cout << tree1.count_leafs("/") << endl;
    cout << tree1.count_nodes("/") << endl;

    // find differents elements
    cout << tree1.find(".var1") << endl;
    cout << tree1.find(".scope3.scope4.var1") << endl;

    // check all leaf and node
    displayTree(tree1);




    parser2.set_source(av[2]);
    parser2.set_tree(&tree2);
    parser2.parse();
    cout << "========== empty file ==========" << endl;
    displayTree(tree2);

    // count lead and nodes
    cout << tree2.count_leafs("/") << endl;
    cout << tree2.count_nodes("/") << endl;





    parser3.set_source(av[3]);
    parser3.set_tree(&tree3);
    parser3.parse();
    cout << "========== fail declarations ==========" << endl;

    // count lead and nodes
    cout << tree3.count_leafs("/") << endl;
    cout << tree3.count_nodes("/") << endl;

    // check all leaf and node
    displayTree(tree3);





    parser4.set_source(av[4]);
    parser4.set_tree(&tree4);
    parser4.parse();
    cout << "========== fail includes ==========" << endl;

    // count lead and nodes
    cout << tree4.count_leafs("/") << endl;
    cout << tree4.count_nodes("/") << endl;

    // check all leaf and node
    displayTree(tree4);





    parser5.set_source(av[5]);
    parser5.set_tree(&tree5);
    parser5.parse();
    cout << "========== fail lists ==========" << endl;

    // count lead and nodes
    cout << tree5.count_leafs("/") << endl;
    cout << tree5.count_nodes("/") << endl;

    // check all leaf and node
    displayTree(tree5);





    parser6.set_source(av[6]);
    parser6.set_tree(&tree6);
    parser6.parse();
    cout << "========== fail scopes ==========" << endl;

    // count lead and nodes
    cout << tree6.count_leafs("/") << endl;
    cout << tree6.count_nodes("/") << endl;

    // check all leaf and node
    displayTree(tree6);

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
