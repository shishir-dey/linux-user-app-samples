#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
	int sockfd, status;
	struct sockaddr_in addr;

	char *html_data = (char *)malloc(1000 * sizeof(char));
	char *alias = html_data;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(80);
	char *cp = "192.168.1.1";
	inet_aton(cp, &addr.sin_addr);

	status = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));

	if (status < 0) {
		fprintf(stderr, "Unable to connect\n");
	}
	recv(sockfd, html_data, 1000 * sizeof(char), MSG_CMSG_CLOEXEC);
	for (char *pc = alias; pc < (alias + 1000); pc++) {
		printf("%c", *pc);
	}
	printf("\n");
	free(alias);
	return 0;
}
