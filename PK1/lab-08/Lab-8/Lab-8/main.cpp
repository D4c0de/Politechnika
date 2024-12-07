#include "commandLineInput.h"
#include "FileIO.h"

int main(int argc,char* argv[]) {

	CommandLineInput cmd(argc, argv);
	FileIO file(cmd.inputFileName, cmd.outputFileName);
	file.RW(cmd.command);

}