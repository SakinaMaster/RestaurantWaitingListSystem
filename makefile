waitingList: userInterface.o listFunctions.o listImplementation.o
	gcc -o waitingList userInterface.o listFunctions.o listImplementation.o

userInterface.o: userInterface.c waitingList.h
	gcc -c userInterface.c

listFunctions.o: listFunctions.c waitingList.h
	gcc -c listFunctions.c

listImplementation.o: listImplementation.c waitingList.h
	gcc -c listImplementation.c

clean: 
        rm userInterface.o listFunctions.o listImplementation.o waitingList
