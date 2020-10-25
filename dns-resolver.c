#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("Usage: ./dns-resolver <host>\n");
        return 0;
    } else {
        struct hostnet *host = gethostbyname(argv[1]);

        if (host == NULL) {
            printf("Error...");
        } else {
            printf("Host: %s/n",inet_ntoa(*((struct in_addr *)host->h_addr)));
        }
    }

    return 0;
}