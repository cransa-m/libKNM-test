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
#include <base/KUtils.hh>

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
  string s1("\"Once uppon a time\"");
  string s2("Hello World !");
  string s3("42.56");
  string s4("42");
  string s5("true");
  string s6("false");
  string s7("  \n   \n    \t \t Test               Space   \n   \t \t \t \t    \n    ");
  string s8("filetext.txt");
  string s9("exec.bin");
  string s10("/bin/ls");
  string s11("/usr/local/include/KNM/");

  int i1 = 0;
  int i2 = -42;
  int i3 = 42;
  int i4 = 424242424;

  float f1 = 0.0;
  float f2 = -42.42;
  float f3 = 13.37;
  float f4 = 424242424242424242;
  float f5 = 0.424242424242424242;
  float f6 = 0.000000000042;

  bool b1 = true;
  bool b2 = false;

   cout << "=== unquoted method ===" << endl;
  cout << s1 << "| unquoted -> " << *KUtils::unquote(s1) << endl;

   cout << "=== quoted method ===" << endl;
  cout << s2 << "| quoted -> " << *KUtils::quote(s2) << endl;

  cout << "=== ToInt method ===" << endl;
  cout << s1 << "| ToInt -> " << KUtils::to_int(s1) << endl;
  cout << s2 << "| ToInt -> " << KUtils::to_int(s2) << endl;
  cout << s3 << "| ToInt -> " << KUtils::to_int(s3) << endl;
  cout << s4 << "| ToInt -> " << KUtils::to_int(s4) << endl;
  cout << s5 << "| ToInt -> " << KUtils::to_int(s5) << endl;
  cout << s6 << "| ToInt -> " << KUtils::to_int(s6) << endl;

  cout << "=== ToFloat method ===" << endl;
  cout << s1 << "| ToFloat -> " << KUtils::to_float(s1) << endl;
  cout << s2 << "| ToFloat -> " << KUtils::to_float(s2) << endl;
  cout << s3 << "| ToFloat -> " << KUtils::to_float(s3) << endl;
  cout << s4 << "| ToFloat -> " << KUtils::to_float(s4) << endl;
  cout << s5 << "| ToFloat -> " << KUtils::to_float(s5) << endl;
  cout << s6 << "| ToFloat -> " << KUtils::to_float(s6) << endl;

  cout << "=== ToBool method ===" << endl;
  cout << s1 << "| ToBool -> " << KUtils::to_bool(s1) << endl;
  cout << s2 << "| ToBool -> " << KUtils::to_bool(s2) << endl;
  cout << s3 << "| ToBool -> " << KUtils::to_bool(s3) << endl;
  cout << s4 << "| ToBool -> " << KUtils::to_bool(s4) << endl;
  cout << s5 << "| ToBool -> " << KUtils::to_bool(s5) << endl;
  cout << s6 << "| ToBool -> " << KUtils::to_bool(s6) << endl;

  cout << "=== ToString (KNM::types) method ===" << endl;
  cout << *KUtils::to_string(KUtils::VOID) << endl;
  cout << *KUtils::to_string(KUtils::BYTE) << endl;
  cout << *KUtils::to_string(KUtils::BOOLEAN) << endl;
  cout << *KUtils::to_string(KUtils::INTEGER) << endl;
  cout << *KUtils::to_string(KUtils::FLOAT) << endl;
  cout << *KUtils::to_string(KUtils::STRING) << endl;
  cout << *KUtils::to_string(KUtils::LIST) << endl;

  cout << "=== ToString (int) method ===" << endl;
  cout << i1 << "| ToString -> " << *KUtils::to_string(i1) << endl;
  cout << i2 << "| ToString -> " << *KUtils::to_string(i2) << endl;
  cout << i3 << "| ToString -> " << *KUtils::to_string(i3) << endl;
  cout << i4 << "| ToString -> " << *KUtils::to_string(i4) << endl;

  cout << "=== ToString (float) method ===" << endl;
  cout << f1 << "| ToString -> " << *KUtils::to_string(f1) << endl;
  cout << f2 << "| ToString -> " << *KUtils::to_string(f2) << endl;
  cout << f3 << "| ToString -> " << *KUtils::to_string(f3) << endl;
  cout << f4 << "| ToString -> " << *KUtils::to_string(f4) << endl;
  cout << f5 << "| ToString -> " << *KUtils::to_string(f5) << endl;
  cout << f6 << "| ToString -> " << *KUtils::to_string(f6) << endl;

  cout << "=== ToString (bool) method ===" << endl;
  cout << boolalpha << b1 << "| ToString -> " << *KUtils::to_string(b1) << endl;
  cout << boolalpha << b2 << "| ToString -> " << *KUtils::to_string(b2) << endl;

  cout << "=== type_Name method ===" << endl;
  cout << s1 << "| TypeName -> " << *KUtils::type_name(s1) << endl;
  cout << s2 << "| TypeName -> " << *KUtils::type_name(s2) << endl;
  cout << s3 << "| TypeName -> " << *KUtils::type_name(s3) << endl;
  cout << s4 << "| TypeName -> " << *KUtils::type_name(s4) << endl;
  cout << s5 << "| TypeName -> " << *KUtils::type_name(s5) << endl;
  cout << s6 << "| TypeName -> " << *KUtils::type_name(s6) << endl;

  cout << "=== EndlikeUnix method ===" << endl;
  cout << s1 << "| EndlikeUnix (no endl) -> " << *KUtils::endlike_unix(s1);
  cout << s2 << "| EndlikeUnix (no endl) -> " << *KUtils::endlike_unix(s2);
  cout << s3 << "| EndlikeUnix (no endl) -> " << *KUtils::endlike_unix(s3);
  cout << s4 << "| EndlikeUnix (no endl) -> " << *KUtils::endlike_unix(s4);
  cout << s5 << "| EndlikeUnix (no endl) -> " << *KUtils::endlike_unix(s5);
  cout << s6 << "| EndlikeUnix (no endl) -> " << *KUtils::endlike_unix(s6);

  cout << "=== EndlikeUnix method ===" << endl;
  cout << s1 << "| EndlikeDos (no endl) -> " << *KUtils::endlike_dos(s1);
  cout << s2 << "| EndlikeDos (no endl) -> " << *KUtils::endlike_dos(s2);
  cout << s3 << "| EndlikeDos (no endl) -> " << *KUtils::endlike_dos(s3);
  cout << s4 << "| EndlikeDos (no endl) -> " << *KUtils::endlike_dos(s4);
  cout << s5 << "| EndlikeDos (no endl) -> " << *KUtils::endlike_dos(s5);
  cout << s6 << "| EndlikeDos (no endl) -> " << *KUtils::endlike_dos(s6);

  cout << "=== EndlikeNone method ===" << endl;
  cout << s1 << "| EndlikeNone -> " << *KUtils::endlike_none(s1) << endl;
  cout << s2 << "| EndlikeNone -> " << *KUtils::endlike_none(s2) << endl;
  cout << s3 << "| EndlikeNone -> " << *KUtils::endlike_none(s3) << endl;
  cout << s4 << "| EndlikeNone -> " << *KUtils::endlike_none(s4) << endl;
  cout << s5 << "| EndlikeNone -> " << *KUtils::endlike_none(s5) << endl;
  cout << s6 << "| EndlikeNone -> " << *KUtils::endlike_none(s6) << endl;

  cout << "=== replace method ===" << endl;
  cout << s2 << "| replace \" \" with \";\"  -> " << *KUtils::replace(s2, " ", ";") << endl;
  cout << s2 << "| replace \"y\" with \";\"  -> " << *KUtils::replace(s2, "y", ";") << endl;
  cout << s2 << "| replace \"lo Worl\" with \"\"  -> " << *KUtils::replace(s2, "lo Worl", "") << endl;
  cout << s2 << "| replace \"Hello\" with \"Welcome\"  -> " << *KUtils::replace(s2, "Hello", "Welcome") << endl;
  cout << s2 << "| replace \"World !\" with \"Everybody !\"  -> " << *KUtils::replace(s2, "World !", "Everybody !") << endl;
  cout << s2 << "| replace \"Hello World !\" with \"Welcome Everybody !\"  -> " << *KUtils::replace(s2, "Hello World !", "Welcome Everybody !") << endl;

  cout << "===clearReturn method===" << endl;
  cout << "line with 10 \\n | clearReturn -> " << *KUtils::clear_return("1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 9\n 10\n") << endl;
  cout << "1\\n 2\\n 3\\n| (with two \\) | clearReturn -> " << *KUtils::clear_return("1\\n 2\\n 3\\n") << endl;

  /*cout << "=== epur method ===" << endl;
  cout << s1 << "| epur -> " << *KUtils::epur(s1) << endl;
  cout << s2 << "| epur -> " << *KUtils::epur(s2) << endl;
  cout << s3 << "| epur -> " << *KUtils::epur(s3) << endl;
  cout << s7 << "| epur -> " << *KUtils::epur(s7) << endl;
  

  cout << "=== ungroup method ===" << endl;
  cout << s1 << "| ungroup -> " << *KUtils::ungroup(s1, ' ') << endl;
  cout << s2 << "| ungroup -> " << *KUtils::ungroup(s2, ' ') << endl;
  cout << s3 << "| ungroup -> " << *KUtils::ungroup(s3, ' ') << endl;
  */

  cout << "=== getFileExtension method ===" << endl;
  cout << s2 << "| get_file_ext -> " << *KUtils::get_file_ext(s2) << endl;
  cout << s8 << "| get_file_ext -> " << *KUtils::get_file_ext(s8) << endl;
  cout << s9 << "| get_file_ext -> " << *KUtils::get_file_ext(s9) << endl;

  cout << "=== dirname method ===" << endl;
  cout << s9 << "| dirname -> " << *KUtils::dirname(s9) << endl;
  cout << s10 << "| dirname -> " << *KUtils::dirname(s10) << endl;
  cout << s11 << "| dirname -> " << *KUtils::dirname(s11) << endl;
  
  cout << "=== basename method ===" << endl;
  cout << s9 << "| basename -> " << *KUtils::basename(s9) << endl;
  cout << s10 << "| basename -> " << *KUtils::basename(s10) << endl;
  cout << s11 << "| basename -> " << *KUtils::basename(s11) << endl;
  
  cout << "=== findFirst method ===" << endl;
  cout << s9 << "| findFirst \'.\' -> " << KUtils::find_first(s9, '.') << endl;
  cout << s9 << "| findFirst \'\\0\' -> " << (int)KUtils::find_first(s9, '\0') << endl;
  cout << s9 << "| findFirst \'\o\' -> " << (int)KUtils::find_first(s9, 'o') << endl;
  cout << s10 << "| findFirst \'s\' -> " << KUtils::find_first(s10, 's') << endl;
  cout << s11 << "| findFirst \'/\' -> " << KUtils::find_first(s11, '/') << endl;
  
  


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
