# Compilation finale
main_test : main_test.o edition.o ui.o
	gcc -Wall -o main_test main_test.o edition.o ui.o

# Compilation des fichiers objets
main_test.o : main_test.c edition.h database.h ui.h
	gcc -Wall -c -g main_test.c

edition.o : edition.c edition.h database.h
	gcc -Wall -c -g edition.c

ui.o : ui.c ui.h database.h
	gcc -Wall -c -g ui.c

# Nettoyage des fichiers objets et exécutables 
clean :
	rm -rf *.o main_test

