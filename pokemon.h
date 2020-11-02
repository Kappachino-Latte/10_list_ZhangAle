#ifndef POKEMON_H
#define POKEMON_H

struct pokemon {
	char name [128];
	char type [128];
	int level;
	struct pokemon* next_poke;
};

struct pokemon* new_pokemon (char* new_name, char* new_type, int new_level);

void remove_pokemon (struct pokemon* poke);

void modify_pokemon (struct pokemon* poke, char *new_name, char * new_type, int new_level);

void print_pokemon (struct pokemon* poke);

//List functions
void print_list (struct pokemon*);

struct pokemon* insert_front (struct pokemon*, char*, char*, int);

struct pokemon* free_list (struct pokemon *);

struct pokemon* remove_node (struct pokemon*, char*);

#endif
