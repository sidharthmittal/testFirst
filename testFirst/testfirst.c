#include "base/main/main.h"
//#define Aig_ManForEachCo( p, pObj, i ) Vec_PtrForEachEntry( Aig_Obj_t *, p->vCos, pObj, i )
ABC_NAMESPACE_IMPL_START

int TestFirst_FirstFunction (Abc_Ntk_t * pNtk);

int TestFirst_FirstFunctionAbc (Abc_Frame_t * pAbc)
{
	Abc_Ntk_t * pNtk;
	int result;
	//pNtk= Abc_FrameReadNtk (pAbc);	
	pNtk=Io_ReadVerilog("adder.v",1);
	if (pNtk == NULL)
			{
				Abc_Print (-1, "TestFirst_FirstFunctionAbc : getting the target network has failed. \n");
				return 0;
			}

	result = TestFirst_FirstFunction(pNtk);

	return result;
}

int TestFirst_FirstFunction (Abc_Ntk_t * pNtk1)
{
	Abc_Obj_t * pObj;
	/*if(!Abc_NtkIsStrash(pNtk1))
	{
		Abc_Print(-1, "TestFirst_FirstFunction : the command is only appliacble to strashed network. \n");
		return 0;
	}*/
	//pNtk1= Io_ReadVerilog( "adder.v",1 );
	pNtk1= Abc_NtkFlattenLogicHierarchy( pNtk1 );
	FILE * pFile;
	pFile = fopen( "abc.v", "w" );

	int i=0;
    
    printf("no of objects %d\n",pNtk1->nObjs);
	Abc_NtkForEachObj( pNtk1, pObj, i )
    {
        if ( Abc_ObjIsLatch(pObj) )
            printf("latched\n");
       	else
       		printf("printing..........%d\n",i );
    }

    if ( pFile == NULL )
    {
        fprintf( stdout, "Io_WriteVerilog(): Cannot open the output file \"%s\".\n", "abc.v" );
        return 0;
    }

	// print about the network

	Abc_Print(1, "The network with name %s has : \n", Abc_NtkName(pNtk1));
	Abc_Print(1, "\t - %d primary inputs; \n", Abc_NtkPiNum(pNtk1));
	Abc_Print(1, "\t - %d primary outputs; \n", Abc_NtkPoNum(pNtk1));
	Abc_Print(1, "\t - %d AND gates; \n", Abc_NtkNodeNum(pNtk1));
	Abc_NtkPrintIo( pFile, pNtk1, 10);
	Io_WriteVerilog(pNtk1, "abc1.v" );
	return 1;
}

ABC_NAMESPACE_IMPL_END