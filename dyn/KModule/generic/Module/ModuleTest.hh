#ifndef __TESTMODULE_HH__
#define __TESTMODULE_HH__

#include <string>
#include <iostream>

class TestModule
{
public:
	TestModule();
	~TestModule();
	void		write(const std::string &);
	std::string retString();
	int			retInt();
	bool		retBool();
private:
	std::string _str;
	int 		_i;
	bool 		_b;
};

#endif /* __TESTMODULE_HH__ */
