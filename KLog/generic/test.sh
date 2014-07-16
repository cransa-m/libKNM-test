#!/bin/bash

# ======================== ABOUT ========================
#
# This script is used to test a part of the OCADrone Artifical Intelligence
# library (including classes, binaries, functions, scripts, ...).
# 
# Version: 4
#
#
#
# Mandatory requierments
#  - 'bash' unix command line interpreter
#  - A binary file to execute, pointed by the $BIN variable.
#
# Optionnal requierments
#  - 'xargs' binary (provided by default in all major distributions)
#  - 'make' tool
#  - A makefile, pointed by the $MAKEFILE variable
#  - A file containing a valid output, pointed by the $OUTPUT_VALID variable
# 
# Script usage
#  Just call the script (common name is 'test.sh'). The script will display
#  tests results after the execution (see 'Script process' bellow).
#  You can also use option -v (or --verbose) to print logs.
#  If the file "test.args" exists, arguments will be read LINE BY LINE
#  from this file and passed to the binary.
#
# Arguments
#  The file test.args contains arguments. File syntax is the following:
#  - ONE argument per line
#  - The following symbols ",':./; are literals
#  - An argument with whitespace MUST NOT be placed arround '' or ""
#  - The file MUST end with a new line
#
# Script process
#  1 - Configure environment: envinit() function
#  2 - Build binary file: build() function
#  3 - Execute script: test_execute and test_output functions
#  4 - Display results: result() function
#
# Script result formatting
#  4 points are listed:
#  - Environment init. result
#  - Compilation result
#  - Execution result (based on return code)
#  - Output result (based on redirected output)
#  Each point have three values: ?, SUCCESS or FAIL
#
#
# ======================== END ========================




# Binary file (test.bin) variables
# ================================
BIN="./test.bin"					# File to test (file will be executed)
VALID_CODE="0"						# Valid execution code (as returned by return() function in binary)
ARGS=""								# Default arguments list. 
ARGS_FILE="test.args"				# File containing argument ON A SINGLE LINE.

# Environment init. variables
# ===========================
ENVINIT_SRC="test.init"				# Contains your own env. configuration

# Building and executing variables
# ================================
MAKEFILE="Makefile"					# Makefile name
MAKE_CMD="re"						# Make command to perform
OUTPUT_MAKE="output_make"			# The file containing make (build) output
OUTPUT_VALID="output_valid"			# The file containing the valid output example
OUTPUT_TEST="output_test"			# The file containing the executiion output
VERBOSE="no"						# Print log message in result phase
COMMENT="no"						# Print end comments (bypass VERBOSE option)

# Default code and status
# =======================
STATUS_ENVINIT="?"					# Environment init. status
STATUS_BUILD="?"					# Default build status
STATUS_RETURN="?"					# Default execution status
STATUS_OUTPUT="?"					# Default output verification status

# Switches
# ========
DO_ENVINIT="yes"					# Should I configure environment ?
DO_BUILD="yes"						# Should I build file(s) ?
DO_TEST="yes"						# Should I test retuen code and output ?
DO_EXECUTE="yes"					# Should I execute binary ?
DO_RESULT="yes"						# Should I print results ?
DO_GENERATE="no"					# Should I use test output as reference ?


# Colors code
# ===========
BHC_DFLT='\e[0m'
BHC_GREEN='\e[0;32m'
BHC_ORANGE='\e[0;33m'
BHC_RED='\e[0;31m'


# Functions
# =========

# Print help (aka usage) informations
function help()
{
	echo "Usage: test.sh [options]"
	echo "Options:"
	echo "-c | --comment : Prints comments after execution"
	echo "-v | --verbose : Print whats happening"
	echo "--noinit       : Don't init environment"
	echo "--nobuild      : Don't perform build operations"
	echo "--notest       : Don't check return code and output"
	echo "--noexec       : Don't execute binary"
	echo "--noresult     : Don't display results"
	echo "--generate     : Write a valid output and enable --notest"
}

# Echo in green
function printSuccess()
{
	echo -e "${BHC_GREEN}$@${BHC_DFLT}"
}

# echo in orange
function printWarning()
{
	echo -e "${BHC_ORANGE}$@${BHC_DFLT}"
}

#echo in red
function printError()
{
	echo -e "${BHC_RED}$@${BHC_DFLT}"
}

# Check system environmen (tools, binary, etc.)
function checkbin()
{
	if ! command -v "$1" > /dev/null; then
		printError "System requierments error: '$1' not found"
		exit
	fi
}

# Configure the local environment (files, hierarchy, ...)
function envinit()
{
	if [ "$DO_ENVINIT" != "yes" ]; then
		printWarning "  [!] envinit(): init process disabled"
		STATUS_ENVINIT="?"
		return
	fi

	echo "Configuring environment:"

	echo "  [*] Cleaning files"
	if [ -e $BIN ]; then rm $BIN; fi
	echo -n > $OUTPUT_TEST

	echo "  [*] Loading user's configuration"
	if [ -e $ENVINIT_SRC ]; then
		source $ENVINIT_SRC
	else
		printWarning "  [!] envinit(): info: no '$ENVINIT_SRC' found"
	fi

	STATUS_ENVINIT="SUCCESS"
	echo "  [*] Done."
}

# Build needed files
function build()
{
	if [ "$DO_BUILD" != "yes" ]; then
		printWarning "  [!] build(): build process disabled"
		STATUS_BUILD="?"
		return
	fi

	echo "Building needed file(s):"
	if [ ! -e $MAKEFILE ]; then
		printWarning "  [!] build(): warning: makefile not found"
		STATUS_BUILD="?"
		return
	else
		echo "  [*] Invoking make"
		SECONDS=0 		# Start timing
		make -f $MAKEFILE "$MAKE_CMD" &> $OUTPUT_MAKE
		RET="$?"
		echo -e "\n\n~~~test.sh log~~~" >> $OUTPUT_MAKE
		echo "make time: $SECONDS seconds" >> $OUTPUT_MAKE
		if [ "$RET" == "2" ]; then 
			printError "  [!] build(): make: error: make has returned an error"
			STATUS_BUILD="FAIL"
			return
		else
			STATUS_BUILD="SUCCESS"
		fi
	fi
	echo "  [*] Done."
}

# Test the execution (basically, test programm return)
function test_execute()
{
	if [ "$DO_EXECUTE" != "yes" ]; then
		printWarning "  [!] test_execute(): execution process disabled"
		STATUS_RETURN="?"
		return
	fi

	if [ "$STATUS_BUILD" == "FAIL" ]; then
		STATUS_RETURN="?"
		return
	fi

	echo "Executing test binary: "
	if [ ! -e $BIN ]; then
		printError "  [!] test_execute(): error: binary not found"
		STATUS_RETURN="FAIL"
		return
	fi

	echo "  [*] Loading arguments from '$ARGS_FILE'"
	if [ -e $ARGS_FILE ]; then
		local i=0
		local ARGS=()
		while read arg
		do
			ARGS[$i]="$arg"
			((i++))
		done < $ARGS_FILE
	else
		printWarning "  [!] test_execute(): info: No arguments file '$ARGS_FILE' found"
	fi

	if [ "$DO_GENERATE" == "yes" ]; then
		STATUS_RETURN="?"
		#echo $ARGS | xargs $BIN | tee $OUTPUT_VALID $OUTPUT_TEST
		$BIN "${ARGS[@]}" | tee $OUTPUT_VALID $OUTPUT_TEST
	elif [ "$DO_TEST" != "yes" ]; then
		STATUS_RETURN="?"
		#echo $ARGS | xargs $BIN &> $OUTPUT_TEST
		$BIN "${ARGS[@]}" &> $OUTPUT_TEST
	else
		#echo $ARGS | xargs $BIN &> $OUTPUT_TEST
		$BIN "${ARGS[@]}" &> $OUTPUT_TEST
		if [ "$?" == "$VALID_CODE" ]; then
			STATUS_RETURN="SUCCESS"
		else
			STATUS_RETURN="FAIL"
		fi
	fi

	echo "  [*] Done."
}

# Test the binary output
function test_output()
{
	if [ "$DO_TEST" != "yes" ]; then
		printWarning "  [!] test_output(): test process disabled"
		STATUS_OUTPUT="?"
		return
	fi

	if [ "$DO_EXECUTE" != "yes" ]; then
		printWarning "  [!] test_output(): execution process disabled"
		STATUS_OUTPUT="?"
		return
	fi

	if [ "$STATUS_BUILD" == "FAIL" ]; then
		STATUS_OUTPUT="?"
		return
	fi

	echo "Checking test output: "
	if [ ! -e $OUTPUT_VALID ]; then
		STATUS_OUTPUT="?"
		printWarning "  [!] test_output(): warning: valid output file not found"
		echo "  [*] Done."
		return
	fi

	if [ ! -e $OUTPUT_TEST ]; then
		STATUS_OUTPUT="?"
		printWarning "  [!] test_output(): warning: test output file not found"
		echo "  [*] Done."
		return
	fi

	diff $OUTPUT_VALID $OUTPUT_TEST &> /dev/null
	if [ "$?" == "0" ]; then
		STATUS_OUTPUT="SUCCESS"
	else
		STATUS_OUTPUT="FAIL"
	fi

	echo "  [*] Done."
}

# Print the result in a fancy way
function result()
{
	if [ "$DO_RESULT" != "yes" ]; then
		printWarning "  [!] result(): process disabled"
		return
	fi

	echo ""
	echo "~~~ Results ~~~"
	exec >/dev/tty 2>&1

	echo -n "Envinit status   : "
	case "$STATUS_ENVINIT" in
		SUCCESS)	printSuccess "$STATUS_ENVINIT";;
		?)			printWarning "$STATUS_ENVINIT";;
		FAIL)		printError   "$STATUS_ENVINIT";;
	esac

	echo -n "Build status     : "
	case "$STATUS_BUILD" in
		SUCCESS)	printSuccess "$STATUS_BUILD";;
		?)			printWarning "$STATUS_BUILD";;
		FAIL)		printError   "$STATUS_BUILD";;
	esac


	echo -n "Execution code   : "
	case "$STATUS_RETURN" in
		SUCCESS)	printSuccess "$STATUS_RETURN";;
		?)			printWarning "$STATUS_RETURN";;
		FAIL)		printError   "$STATUS_RETURN";;
	esac


	echo -n "Execution output : "
	case "$STATUS_OUTPUT" in
		SUCCESS)	printSuccess "$STATUS_OUTPUT";;
		?)			printWarning "$STATUS_OUTPUT";;
		FAIL)		printError   "$STATUS_OUTPUT";;
	esac
}

# Print comments about test process and execution
function comment()
{
	if [ "$COMMENT" != "yes" ] ; then
		exit
	fi

	echo ""
	echo "~~~ Comments ~~~"

	if [ "$STATUS_BUILD" == "?" ]; then
		echo "Compilation seems to be disabled."
	fi

	if [ "$STATUS_RETURN" == "?" ] && [ "$STATUS_OUTPUT" == "?" ]; then
		echo "Execution checking seems to be disabled."
		echo "Results are still available in log files."
	fi

	if [ "$STATUS_BUILD" == "FAIL" ]; then
		echo "Compilation failed, execution not verified."
		exit
	fi

	if [ "$STATUS_RETURN" == "FAIL" ] && [ "$STATUS_OUTPUT" == "FAIL" ]; then
		echo "Execution code and output are wrong."
		echo "Something went wrong during the test,"
		echo "but relax: at least, compilation succeed :)"
		echo "Check for KError::dump() calls, return() function in main(),"
		echo "and for valid output content."
		exit
	fi

	if [ "$STATUS_RETURN" == "SUCCESS" ] && [ "$STATUS_OUTPUT" != "SUCCESS" ]; then
		echo "Execution code seems to be ok, but test output is wrong."
		echo "You should control:"
		echo "- Binary test output ('cat $OUTPUT_TEST')"
		echo "- KError::dump() calls"
		echo "- Debug message"
		echo "- Non-catched exceptions"
		echo "- Valid output content ('cat $OUTPUT_VALID')"
		exit
	fi

	if [ "$STATUS_RETURN" != "SUCCESS" ] && [ "$STATUS_OUTPUT" == "SUCCESS" ]; then
		echo "Execution code is wrong, but output is correct."
		echo "That's a strange situation. Maybe the valid output is empty, which"
		echo "is a bad thing. Try to have at least one line of output."
		echo "Also, double-check return() argument in main() function."
		echo "Don't forget to read manually the test output."
		exit
	fi

	if [ "$STATUS_RETURN" == "SUCCESS" ] && [ "$STATUS_OUTPUT" == "SUCCESS" ]; then
		echo "Execution code output are both OK. Good job !"
		echo "You can still dump '$OUTPUT_TEST' file to read more about"
		echo "execution process."
		exit
	fi
}


# Entry point
# ===========

# Options
while [ -n "$1" ]; do
	case $1 in
		-v|--verbose) VERBOSE="yes";;
		-c|--comment) COMMENT="yes";;
		--noinit)     DO_ENVINIT="no";;
		--nobuild)    DO_BUILD="no";;
		--notest)     DO_TEST="no";;
		--noexec)     DO_EXECUTE="no";;
		--noresult)   DO_RESULT="no";;
		--generate)	  DO_GENERATE="yes"; DO_TEST="no";;
		*)            help; exit;;
	esac
	shift
done

# Enabling or disabling verbose mode
if [ "$VERBOSE" != "yes" ]; then exec 1>/dev/null 2>/dev/null; fi

# Check the system
checkbin "xargs"
checkbin "make"
checkbin "tee"

# Start the operations
envinit 			# Configure environment
build				# Build the test binary
test_execute		# Run the binary and test return code
test_output 		# Test output
result 				# Display the result
comment 			# Display comments