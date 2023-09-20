#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIAS_LEN 100
#define MAX_COMMAND_LEN 200

typedef struct Alias {
	char alias[MAX_ALIAS_LEN];
	char command[MAX_COMMAND_LEN];
	struct Alias* next;
} Alias;

#define HASH_TABLE_SIZE 100

Alias* aliasTable[HASH_TABLE_SIZE] = { NULL };
unsigned int hash(char* alias) {
	unsigned int hashval = 0;
	for (; *alias != NULL; alias++) {
		hashval = *alias + (hashval << 5) - hashval;
	}
	return hashval % HASH_TABLE_SIZE;
}
void addAlias(char* alias, char* command) {
	unsigned int index = hash(alias);
	Alias* current = aliasTable[index];
	while (current != NULL) {
		if (strcmp(current->alias, alias) == 0) {
			strcpy(current->command, command);
			return (0) ;
		}
		current = current->next;
	}
	Alias* newAlias = (Alias*)malloc(sizeof(Alias));
	if (newAlias == NULL) {
		perror("error check memory allocation");
		exit(EXIT_FAILURE);
	}
	strcpy(newAlias->alias, alias);
	strcpy(newAlias->command, command);
	newAlias->next = aliasTable[index];
	aliasTable[index] = newAlias;
}
void executeAlias(char* alias) {
	unsigned int index = hash(alias);
	Alias* current = aliasTable[index];
	while (current != NULL) {
		if (strcmp(current->alias, alias) == 0) {
			system(current->command);
			return;
		}
		current = current->next;
	}
	printf("Alias not found: %s\n", alias);
}

int main() {
	char input[MAX_COMMAND_LEN];
	while (1) {
		printf("Your Command: ");
		fgets(input, sizeof(input), stdin);
		size_t len = strlen(input);
		if (len > 0 && input[len - 1] == '\n') {
			input[len - 1] = '\0';
		}
		if (strncmp(input, "alias", 5) == 0) {
			char alias[MAX_ALIAS_LEN];
			char command[MAX_COMMAND_LEN];
			if (sscanf(input + 5, "%s = \"%[^\"]\"", alias, command) == 2) {
				addAlias(alias, command);
				printf("Alias added: %s -> %s\n", alias, command);
			} else {
				printf("Invalid alias format.\n");
			}
		} else {
			executeAlias(input);
		}
	}
	return 0;
}

