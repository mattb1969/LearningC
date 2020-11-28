## -*- Makefile -*-
##
## User: matthew
## Time: 07-Jul-2019 08:56:47
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CC = gcc
BASICOPTS = -g -Wall
CFLAGS = $(BASICOPTS)


# Define the target directories.
TARGETDIR_passingReceivingPointers=.


all: $(TARGETDIR_passingReceivingPointers)/passingReceivingPointers

## Target: passingReceivingPointers

OBJS_passingReceivingPointers =  \
	$(TARGETDIR_passingReceivingPointers)/WaitForCTS.o \
	$(TARGETDIR_passingReceivingPointers)/SendCommand.o \
	$(TARGETDIR_passingReceivingPointers)/reader.o \
	$(TARGETDIR_passingReceivingPointers)/GetResult.o \
	$(TARGETDIR_passingReceivingPointers)/SetTagMode.o \
	$(TARGETDIR_passingReceivingPointers)/SendCmds.o \
	$(TARGETDIR_passingReceivingPointers)/GetCmdResult.o
USERLIBS_passingReceivingPointers = -lwiringPi $(SYSLIBS_passingReceivingPointers) 
DEPLIBS_passingReceivingPointers =   
LDLIBS_passingReceivingPointers = $(USERLIBS_passingReceivingPointers)


# Link or archive
$(TARGETDIR_passingReceivingPointers)/passingReceivingPointers: $(TARGETDIR_passingReceivingPointers) $(OBJS_passingReceivingPointers) $(DEPLIBS_passingReceivingPointers)
	$(LINK.c) $(CFLAGS_passingReceivingPointers) -o $@ $(OBJS_passingReceivingPointers) $(LDLIBS_passingReceivingPointers)


# Compile source files into .o files
$(TARGETDIR_passingReceivingPointers)/WaitForCTS.o: $(TARGETDIR_passingReceivingPointers) WaitForCTS.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ WaitForCTS.c

$(TARGETDIR_passingReceivingPointers)/SendCommand.o: $(TARGETDIR_passingReceivingPointers) SendCommand.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ SendCommand.c

$(TARGETDIR_passingReceivingPointers)/reader.o: $(TARGETDIR_passingReceivingPointers) reader.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ reader.c

$(TARGETDIR_passingReceivingPointers)/GetResult.o: $(TARGETDIR_passingReceivingPointers) GetResult.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ GetResult.c

$(TARGETDIR_passingReceivingPointers)/SetTagMode.o: $(TARGETDIR_passingReceivingPointers) SetTagMode.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ SetTagMode.c

$(TARGETDIR_passingReceivingPointers)/SendCmds.o: $(TARGETDIR_passingReceivingPointers) SendCmds.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ SendCmds.c

$(TARGETDIR_passingReceivingPointers)/GetCmdResult.o: $(TARGETDIR_passingReceivingPointers) GetCmdResult.c
	$(COMPILE.c) $(CFLAGS_passingReceivingPointers)  -o $@ GetCmdResult.c



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_passingReceivingPointers)/passingReceivingPointers \
		$(TARGETDIR_passingReceivingPointers)/WaitForCTS.o \
		$(TARGETDIR_passingReceivingPointers)/SendCommand.o \
		$(TARGETDIR_passingReceivingPointers)/reader.o \
		$(TARGETDIR_passingReceivingPointers)/GetResult.o \
		$(TARGETDIR_passingReceivingPointers)/SetTagMode.o \
		$(TARGETDIR_passingReceivingPointers)/SendCmds.o \
		$(TARGETDIR_passingReceivingPointers)/GetCmdResult.o
# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-Linux

