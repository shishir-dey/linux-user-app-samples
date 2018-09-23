#include <stdlib.h>

int main(void) {
	int count = 0;
	for (;;count++) {
		if (count == 32767) {
			goto exit;
		}
	}
exit:
	exit(0);
	return 0;
}
