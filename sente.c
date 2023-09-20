#include <stdio.h>
#include <stdlib.h>

/**
 * my_setenv this function responsible for
 * the env value
 *
 * Return : 0 or NULL return failed.
 */

int my_setenv(const char *name, const char *value, int overwrite) {

	char *existing_value = getenv(name);

	if (existing_value != NULL && !overwrite) {

		return (0);
	} else {

		char *env_var = (char *)malloc(strlen(name) + strlen(value) + 2); 
		if (env_var == NULL) {

			return (-1);
		}



		if (putenv(env_var) != 0) {

			free(env_var);
			return (-1);
		}

		return (0);
	}
}
