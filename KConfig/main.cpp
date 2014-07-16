/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-07-13 14:52:59
* @Last update   : 2014-07-16 08:40:27
*/

#include <iostream>
#include <KConfig.hh>
#include <KError.hh>

using namespace std;
using namespace KNM;

int 			main(int ac, char **av)
{
	KConfig		config;

	// Control
	if (ac < 3)
	{
		cerr << "usage: a.out <file> <opt_name>" << endl;
		exit(1);
	}

	try
	{
		config.include(av[1]);
		config.include(ac, av);
		config.load();
		cout << config.find_s(av[2], "not found") << endl;
		cout << config.find_b(av[2], false) << endl;
		cout << config.find_i(av[2], -1) << endl;
	}
	catch (KError *error)
	{
		error->dump();
	}

	return 0;
}