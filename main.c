#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pokemon.h"

int main() {

	srand(time(0));
	int level = rand() % 100 + 1;
	
	struct pokemon* team = NULL;
	team = insert_front (team, "Piplup", "Water", level);
	team = insert_front (team, "Cyndaquil", "Fire", level);
	team = insert_front (team, "Pikachu", "Electric", level);
	printf("\n");

	print_list(team);
	
	team = remove_node (team, "Cyndaquil");
	print_list (team);
	
	team = free_list (team);
	return 0;
}
