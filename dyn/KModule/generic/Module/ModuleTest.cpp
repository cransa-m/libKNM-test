#include "ModuleTest.hh"

TestModule::TestModule()
{
	_str = "string test";
	_i = 42;
	_b = true;
}

TestModule::~TestModule()
{
	
}

void	TestModule::write(const std::string &str)
{
	std::cout << str << std::endl;
}

std::string	TestModule::retString()
{
	return(_str);
}

int		TestModule::retInt()
{
	return(_i);
}

bool	TestModule::retBool()
{
	return(_b);
}

extern "C" TestModule	*getTestModule()
{
	return (new TestModule());
}

extern "C" TestModule *delTestModule(TestModule *tm)
{
	delete tm;
	return (tm);
}
