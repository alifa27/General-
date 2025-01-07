# Compilation finale
main_test : main_test.o edition.o
	gcc -Wall -o main_test main_test.o edition.o

# Compilation des fichiers objets
main_test.o : main_test.c edition.h database.h
	gcc -Wall -c -g main_test.c

edition.o : edition.c edition.h database.h
	gcc -Wall -c -g edition.c

# Nettoyage des fichiers objets et exécutables
clean :
	rm -rf *.o

# Informations sur les options utilisées :
# - `-c` : Compile les fichiers source sans les lier (produit des fichiers `.o`).
# - `-g` : Génère des informations pour le débogage.
# - `-Wall` : Active tous les avertissements.
