#include <iostream>
#include "ComandLineInput.h"
#include "huffmanEngiene.h"
int main(int argc, char* argv[]) {
	try
	{
		//CommandLineInput cmd(argc, argv);
		//Engiene huffmanEngiene(cmd.inputFileName,cmd.outputFileName,cmd.encoding); 
		//ngiene huffmanEngiene("i.bin", "o.bin", true);
		Engiene huffmanEngiene("in.bin", "ou.bin", false);
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 0;
	}
	
}