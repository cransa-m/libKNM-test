/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-06-08 12:17:47
* @Last update   : 2014-07-13 14:19:43
*/

#include <iostream>
#include <string>
#include <KError.hh>
#include <KTree.hpp>

using namespace std;
using namespace KNM;

int main()
{
	KTree<string> 	tree;

	try
	{
		tree.insert("/l1/var1", "41");
		tree.insert("/l1/var2", "42");

		cout << tree.count_leafs("/l1") << endl;
	}
	catch (KError *error)
	{
		error->dump();
	}
}