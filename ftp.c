#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int main_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Create socket
    main_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (main_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to FTP server
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21); // FTP default port
    server_address.sin_addr.s_addr = inet_addr("ftp.example.com");

    if (connect(main_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to FTP server failed");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message
    bytes_received = recv(main_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    // Login to FTP server (replace 'username' and 'password' with actual credentials)
    sprintf(buffer, "USER username\r\n");
    send(main_socket, buffer, strlen(buffer), 0);
    bytes_received = recv(main_socket, buffer, BUFFER_SIZE, 0);

    sprintf(buffer, "PASS password\r\n");
    send(main_socket, buffer, strlen(buffer), 0);
    bytes_received = recv(main_socket, buffer, BUFFER_SIZE, 0);

    // Send LIST command to retrieve directory listing
    sprintf(buffer, "LIST\r\n");
    send(main_socket, buffer, strlen(buffer), 0);

    // Receive directory listing
    while ((bytes_received = recv(main_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close connection
    close(main_socket);

    return 0;
}

