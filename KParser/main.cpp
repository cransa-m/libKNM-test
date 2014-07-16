/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-07-09 14:39:35
* @Last update   : 2014-07-15 10:47:25
*/

#include <iostream>
#include <KParser.hh>
#include <KTree.hpp>

using namespace std;

int 					main(int ac, char **av)
{
	KParser 			parser;
	KTree<string>		tree;
	string 				data;

	string 				*test = new string("MYTEST");

	// Control
	if (ac < 3)
	{
		cerr << "usage: a.out <file> <opt_name>" << endl;
		exit(1);
	}

	try
	{
		// Setup parser source
		//parser.set_source(av[1], KParser::CFG);
		parser.set_source(av[1]);
		parser.set_tree(&tree);

		// Start parse operations
		parser.parse();

		// Shrot
		tree.insert(".var", *test);

		// Check tree content
		data = tree.find(av[2]);
		cout << data << endl;
	}
	catch (KError *error)
	{
		error->dump();
	}

	return 0;
}