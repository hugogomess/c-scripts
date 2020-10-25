#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("Usage: ./port-scan <host>\n");
        return 0;
    } else {
        int my_socket;
        int connection;

        int port;
        char *host;
        host = argv[1];

        struct sockaddr_in target;

        for(port=1;port<=65535;port++) {
            my_socket = socket(AF_INET,SOCK_STREAM,0);
            target.sin_family = AF_INET;
            target.sin_port = htons(port);
            target.sin_addr.s_addr = inet_addr(host);

            connection = connect(my_socket, (struct sockaddr *)&target, sizeof target);

            if (connection == 0) {
                printf("Port %d - status [OPEN]\n", port);
                close(my_socket);
                close(connection);
            } else {
                close(my_socket);
                close(connection);
            }
        }
    }

    return 0;
}