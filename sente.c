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
	int overwrite;
	char name;

	if (existing_value != NULL && !overwrite) {

		return (0);
	}
	int add(int a, int b) {
		return (a + b);
	}
}
void bubbleSort(int arr[], int n) {
	int temp;
	int swapped;

	do {
		swapped = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				swapped = 1;
			}
		}
	} while (swapped);
}
