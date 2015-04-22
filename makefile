EXEC = calculatrice
CFLAGS = -g -Wall
CC = gcc

INC_PATH = include/
OBJ_PATH = obj/
OBJECTS = main.o ExpressionsAlgebriques.o chaine.o 
OBJECTS_DIR = $(patsubst %.o, obj/%.o, $(OBJECTS))
vpath %.h include/
vpath %.c src/
vpath %.o obj/
vpath %.a lib/
vpath %.so lib/
vpath $(EXEC) bin/

calculatrice : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_DIR)
	mv $@ bin/.
	
main.o : ExpressionsAlgebriques.h type.h
ExpressionsAlgebriques.o :  ExpressionsAlgebriques.h chaine.h type.h
chaine.o : chaine.h type.h

%.o : %.c
	$(CC) $(CFLAGS) -c $<  -I $(INC_PATH)
	mv $@ obj/.
	
archive :
	tar -czvf Projet-SDA-Hamida_Zanzi.tar.gz ./* 
	
clean : 
	rm obj/* bin/* lib/* 
EXEC = calculatrice
CFLAGS = -g -Wall
CC = gcc

INC_PATH = include/
OBJ_PATH = obj/
OBJECTS = main.o ExpressionsAlgebriques.o chaine.o 
OBJECTS_DIR = $(patsubst %.o, obj/%.o, $(OBJECTS))
vpath %.h include/
vpath %.c src/
vpath %.o obj/
vpath %.a lib/
vpath %.so lib/
vpath $(EXEC) bin/

calculatrice : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_DIR)
	mv $@ bin/.
	
main.o : ExpressionsAlgebriques.h type.h
ExpressionsAlgebriques.o :  ExpressionsAlgebriques.h chaine.h type.h
chaine.o : chaine.h type.h

%.o : %.c
	$(CC) $(CFLAGS) -c $<  -I $(INC_PATH)
	mv $@ obj/.
	
archive :
	tar -czvf Projet-SDA-Hamida_Zanzi.tar.gz ./* 
	
clean : 
	rm obj/* bin/* lib/* 
