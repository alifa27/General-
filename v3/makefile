# Compilation finale
main : main.o edition.o ui.o traitement.o
	gcc -Wall -o main main.o edition.o ui.o traitement.o

# Compilation des fichiers objets
main.o : main.c edition.h database.h ui.h
	gcc -Wall -c -g main.c

edition.o : edition.c edition.h database.h
	gcc -Wall -c -g edition.c

ui.o : ui.c ui.h database.h
	gcc -Wall -c -g ui.c
	
traitement.o : traitement.c traitement.h database.h
	gcc -Wall -c -g traitement.c

# Nettoyage des fichiers objets et exécutables 
clean :
	rm -rf *.o main

