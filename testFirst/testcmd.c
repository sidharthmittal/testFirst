#include "base/main/main.h"
#include "testfirst.h"

ABC_NAMESPACE_IMPL_START

static int TestFirst_CommandTestFirst (Abc_Frame_t * pAbc, int argc, char ** argv);


void TestFirst_Init(Abc_Frame_t * pAbc)
{
	Cmd_CommandAdd (pAbc, "Various", "firstcmd", TestFirst_CommandTestFirst, 0);
} 


int TestFirst_CommandTestFirst (Abc_Frame_t * pAbc, int argc, char ** argv)
{
	int fVerbose;
	int c;
	int result;

	//set defaults
	fVerbose=0;

	// get arguments

	Extra_UtilGetoptReset();
	while ((c = Extra_UtilGetopt(argc, argv, "vh"))!= EOF)
	{
		switch(c)
		{
			case 'v':
				fVerbose ^=1;
				break;
			case 'h':
				goto usage;
			default:
				goto usage;
		}
	}

//call the main function

result=TestFirst_FirstFunctionAbc(pAbc);

// print Verbose info if verbose mode on

if(fVerbose)
{
	Abc_Print(1, "\nVerbose mode is on.\n");

	if(result)
			Abc_Print(1, "The commannd finished successfully.\n");
	else
			Abc_Print(1, "The command failed.\n");
}

return 0;

usage:
	Abc_Print(-2, "usage: firstcmd [-vh] \n");
	Abc_Print(-2, "\t Our first command in ABC. it Prints inffor aobout the function read into ABC \n");
	Abc_Print(-2, "\t -v : toggle printing verbose info [default = %s]\n", fVerbose ? "yes":"no");
	Abc_Print(-2, "\t -h : Print the command usage\n");
return 1;
}