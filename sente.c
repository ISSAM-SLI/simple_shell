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
	}
	int add(int a, int b) {
		    return a + b;
	}
}
