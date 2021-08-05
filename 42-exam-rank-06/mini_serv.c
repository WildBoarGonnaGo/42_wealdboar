#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

fd_set      writeSet;
fd_set      readSet;
fd_set      active;
char        buffRead[4096 * 42];
char        buffWrite[4096 * 42];
char        str[4096 * 42];
int         idClient[64 * 1024];
int         max = 0;
int         next_id = 0;

uint16_t    ft_htons(uint16_t rvalue) {
    return (((rvalue & 0xFF) << 8) | ((rvalue & 0xFF00) >> 8));
}

uint32_t    ft_htonl(uint32_t rvalue) {
    return (((rvalue & 0xFF) << 24) | ((rvalue & 0xFF00) << 8)
             | ((rvalue & 0xFF0000) >> 8) | ((rvalue & 0xFF000000) >> 24));
}

void        fatal_error_output() {
    char        fatal_error[] = "Fatal Error\n";
    write(2, fatal_error, strlen(fatal_error));
    exit(1);
}

void        sendMsg(int es) {
    for (int i = 0; i < max; ++i) {
        if (FD_ISSET(i, &writeSet) && i != es)
            send(i, buffWrite, strlen(buffWrite), 0);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }
    int port = atoi(argv[1]);
    (void)port;

    bzero(idClient, sizeof(idClient));
    FD_ZERO(&active);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        fatal_error_output();
    max = server_fd;
    FD_SET(server_fd, &active);
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_port = ft_htons(port);
    addr.sin_addr.s_addr = ft_htonl(INADDR_LOOPBACK);

    if (bind(server_fd, (const struct sockaddr *)&addr, sizeof(addr)) < 0)
        fatal_error_output();
    if (listen(server_fd, 128) < 0)
        fatal_error_output();
    while (1) {
        writeSet = readSet = active;
        if (select(max + 1, &readSet, &writeSet, NULL, NULL) < 0)
            continue ;
        for (int s = 0; s < max + 1; ++s) {
            if (FD_ISSET(s, &readSet) && s == server_fd) {
                int client_fd = accept(server_fd, (struct sockaddr *)&addr, &addr_len);
                if (client_fd < 0)
                    continue;
                max = (client_fd > max) ? client_fd : max;
                idClient[client_fd] = next_id++;
                FD_SET(client_fd, &active);
                sprintf(buffWrite, "server: client %d just arrived\n", idClient[client_fd]);
                sendMsg(client_fd);
                break;
            }
            if (FD_ISSET(s, &readSet) && s != server_fd) {
                int rbyte = recv(s, buffRead, 42 * 4096, 0);
                if (rbyte <= 0) {
                    sprintf(buffWrite, "server: client %d just left\n", idClient[s]);
                    sendMsg(s);
                    FD_CLR(s, &active);
                    close(s);
                    break;
                } else {
                    for (int i = 0, j = 0; i < rbyte; ++i, ++j) {
                        str[j] = buffRead[i];
                        if (str[j] == '\n') {
                            str[j] = '\0';
                            sprintf(buffWrite, "client %d: %s\n", idClient[s], str);
                            sendMsg(s);
                            j = -1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
