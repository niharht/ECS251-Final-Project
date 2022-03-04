# Makefile for HW1, ecs251, w2022
#

CC = g++ -std=c++17

# CFLAGS = -g
CFLAGS = -g -I/usr/include/jsoncpp

# CFLAGS = -g -Wall -Wstrict-prototypes
# CFLAGS = -O3

CORE_INCS =	Core.h Voter.h VotingOffice.h VotingMachine.h
CORE_OBJS =	Core.o Voter.o VotingOffice.o VotingMachine.o

LDFLAGS_SV = -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server
LDFLAGS_CL = -ljsoncpp -lcurl -ljsonrpccpp-common -ljsonrpccpp-client

# rules.
all: 	client machineserver officeserver

#
#

client.h:		finalProject.json
	jsonrpcstub finalProject.json --cpp-server=server --cpp-client=client

server.h:		finalProject.json
	jsonrpcstub finalProject.json --cpp-server=server --cpp-client=client

Core.o:			Core.cpp Core.h
	$(CC) -c $(CFLAGS) Core.cpp

Voter.o:		Voter.cpp $(CORE_INCS)
	$(CC) -c $(CFLAGS) Voter.cpp

VotingMachine.o:	VotingMachine.cpp $(CORE_INCS)
	$(CC) -c $(CFLAGS) VotingMachine.cpp

VotingOffice.o:        VotingOffice.cpp  $(CORE_INCS)
	$(CC) -c $(CFLAGS) VotingOffice.cpp

ShadowVotingMachine.o:	ShadowVotingMachine.cpp ShadowVotingMachine.h $(CORE_INCS) client.h
	$(CC) -c $(CFLAGS) ShadowVotingMachine.cpp

ShadowVotingOffice.o:        ShadowVotingOffice.cpp ShadowVotingOffice.h $(CORE_INCS) client.h
	$(CC) -c $(CFLAGS) ShadowVotingOffice.cpp

client.o:	client.cpp ShadowVotingMachine.h ShadowVotingOffice.h $(CORE_INCS) client.h
	$(CC) -c $(CFLAGS) client.cpp

machineserver.o:	machineserver.cpp ShadowVotingMachine.h ShadowVotingOffice.h $(CORE_INCS) server.h
	$(CC) -c $(CFLAGS) machineserver.cpp

machineserver:		$(CORE_OBJS) machineserver.o
	$(CC) -o machineserver $(CORE_OBJS) machineserver.o ShadowVotingMachine.o ShadowVotingOffice.o $(LDFLAGS_SV) $(LDFLAGS_CL)

# hw1client --> hw1server --> hw1another

officeserver.o:		officeserver.cpp ShadowVotingMachine.h ShadowVotingOffice.h $(CORE_INCS) server.h
	$(CC) -c $(CFLAGS) officeserver.cpp

officeserver:		$(CORE_OBJS) officeserver.o
	$(CC) -o officeserver $(CORE_OBJS) officeserver.o  ShadowVotingMachine.o ShadowVotingOffice.o  $(LDFLAGS_SV) $(LDFLAGS_CL)

client:		$(CORE_OBJS) client.o ShadowVotingOffice.o ShadowVotingMachine.o
	$(CC) -o client $(CORE_OBJS) client.o ShadowVotingOffice.o ShadowVotingMachine.o $(LDFLAGS_CL)

clean:
	rm -f *.o *~ core client machineserver officeserver client.h server.h

