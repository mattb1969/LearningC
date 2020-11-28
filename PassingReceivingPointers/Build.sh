gcc -c WaitForCTS.c  GetCmdResult.c SendCmds.c SetTagMode.c	

ar -crv utilities.a WaitForCTS.o GetCmdResult.o SendCmds.o SetTagMode.o



gcc -Wall -o reader reader.c ./utilities.a -lwiringPi 
