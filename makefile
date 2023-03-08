# Commandes disponibles :
#   make        commande qui lance la compilation
#   make all    idem
#   make clean  nettoie le répertoire

# compilateur gcc pour le C++
CC = g++

# options du compilateur
#   -g          insère des informations de déboguage dans l'exécutable
#   -Wall       affiche tous les warnings lors de la compilation
#   -std=c++14  impose la norme C++14 du langage
CFLAGS  = -g -Wall -std=c++14

# fichiers issus de la compilation composant le programme exécutable
#   on appelle les .o des fichiers objets, ils contiennent le code
#   exécutable des opérations dans les fichiers sources associés
OBJ = test.o matrice.o

# programme exécutable
TARGET = test

# la cible (ou les cibles s'il y en a plusieurs)
all: $(TARGET)

# génération de l'exécutable (édition de liens)
#   > sur la première ligne on a la cible (main) suivie de ":" suivie
#     de la dépendance (liste de fichiers), ce qui signifie que si un fichier
#     objet est modifié alors le programme exécutable sera généré à nouveau
#   > sur la deuxième ligne on a l'instruction de compilation (attention
#     il y doit y avoir une TABULATION ou plusieurs en début de ligne)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# compilation de main.cpp générant le fichier objet main.o
#   > sur la première ligne on a la cible (main.o) suivie de ":" suivie
#     de la dépendance (liste de fichiers), ce qui signifie que si on modifie
#     main.cpp ou consigne.h alors le fichier main.cpp sera compilé à nouveau
#   > sur la deuxième ligne on a l'instruction de compilation (attention
#     il y doit y avoir une TABULATION ou plusieurs en début de ligne)
test.o: test.cpp matrice.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c test.cpp -o test.o

# compilation de consigne.cpp générant consigne.o
matrice.o: matrice.cpp matrice.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c matrice.cpp -o matrice.o

# cible pour nettoyer le répertoire
clean:
	rm -f *~ *.o main
