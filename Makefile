# Nom du compilateur
CC = gcc
# Argument du compilateur
CFLAGS = -Wall -Wextra -g
# Nom du dossier pour les .h  ;  précédé par un '-I' et suivi par un '/'
INCLUDES = -Ilibs/

# Nom du dossier pour les .c
SRC = src
# Nom du dossier pour les .o
OBJ = obj
# Nom de l'executable
TARGET = main

# Tout les fichiers .o à générer
OBJS = $(OBJ)/main.o $(OBJ)/binary_tree.o $(OBJ)/binary_node.o

# # Pour un nouveau exemple.o
# $(OBJ)/exemple.o: $(SRC)/exemple.c [Liste des .h dépendance (qui sont includes)]
#	 $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#
# et ajouter au OBJS : $(OBJ)/exemple.o

# make = make main
all: $(TARGET)

# Génération de main
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS)

# Pour main, on a besoin de main.o; dans main.o on utilises 2 .h
$(OBJ)/main.o: main.c libs/binary_tree.h libs/binary_node.h
	$(CC) $(CFLAGS) $(INCLUDES) -c main.c -o $@

# On dois alors faire un .o pour chaque import
# Pour binary tree
$(OBJ)/binary_tree.o: $(SRC)/binary_tree.c libs/binary_tree.h libs/binary_node.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Pour binary node
$(OBJ)/binary_node.o: $(SRC)/binary_node.c libs/binary_node.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Pour nettoyer correctement
clean:
	rm -f $(OBJ)/*.o $(TARGET)

