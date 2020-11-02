#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

struct pokemon * new_pokemon (char* new_name, char* new_type, int new_level) {

	struct pokemon* poke;
	
	poke = malloc( sizeof (struct pokemon) );
	
	strncpy (poke->name, new_name, sizeof(poke->name)-1);
	strncpy (poke->type, new_type, sizeof(poke->type)-1);
	poke->level = new_level;
	poke->next_poke = NULL;
	
	return poke;
}	

void remove_pokemon (struct pokemon* poke) {

	printf ("%s has been freed!\n", poke->name);
	free (poke);
}

void modify_pokemon (struct pokemon* poke, char* new_name, char* new_type, int new_level) {

	strncpy (poke->name, new_name, sizeof(poke->name)-1);
	strncpy (poke->type, new_type, sizeof(poke->type)-1);
	poke->level = new_level;
}

void print_pokemon (struct pokemon* poke) {

	printf ("%s's info\nType:%s\nLevel:%d\n", poke->name, poke->type, poke->level);
}

void print_list (struct pokemon* next) {

	while (next) {
		print_pokemon (next);
		printf ("\n");
		next = next->next_poke;
	}
}

struct pokemon* insert_front (struct pokemon* poke, char* new_name, char* new_type, int new_level) {

	printf ("%s is joining the team!\n", new_name);
	struct pokemon* new_poke = new_pokemon (new_name, new_type, new_level);
	new_poke->next_poke = poke;
	
	return new_poke;
}

struct pokemon* free_list(struct pokemon* poke) {
	
	printf ("Releasing Team!\n");
	
	while (poke) {
		struct pokemon* next = poke->next_poke;
		remove_pokemon (poke);
		poke = next;
		printf ("\n");
	}

}

struct pokemon* remove_node(struct pokemon* front, char* search_name) {

	if (!strcmp(front->name, search_name)) {
		struct pokemon* new_front = front->next_poke;
		remove_pokemon (front);
		printf ("\n");
		return new_front;
	}
	else {
		struct pokemon* current_poke, * previous_poke;
		current_poke = front;
			
		while (current_poke) {
			if (!strcmp(current_poke->name, search_name)) {
				previous_poke->next_poke = current_poke->next_poke;
				remove_pokemon (current_poke);
				break;
			}
			previous_poke = current_poke;
			current_poke = current_poke->next_poke;
		}
	}
	return front;
}

