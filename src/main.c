#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>

void print_system_info(FILE *out) {
    char hostname[256];
    struct utsname sys_info;
    time_t t;
    struct tm *tm_info;
    char time_buffer[64];

    if (gethostname(hostname, sizeof(hostname)) != 0) {
        strcpy(hostname, "Unknown");
    }

    time(&t);
    tm_info = localtime(&t);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    uname(&sys_info);

    fprintf(out, "=== System Information ===\n");
    fprintf(out, "Hostname: %s\n", hostname);
    fprintf(out, "Current Time: %s\n", time_buffer);
    fprintf(out, "OS System: %s\n", sys_info.sysname);
    fprintf(out, "OS Release: %s\n", sys_info.release);
    fprintf(out, "OS Version: %s\n", sys_info.version);
    fprintf(out, "Hardware: %s\n", sys_info.machine);
    fprintf(out, "==========================\n");
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [file_name]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        const char *filename = argv[1];
        
        if (access(filename, F_OK) == 0) {
            printf("Warning: file '%s' is already exist. Data will writed end of file.\n", filename);
        }

        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            perror("Error opening file.");
            return EXIT_FAILURE;
        }

        print_system_info(f);
        fclose(f);
        printf("Succefuly writen information in file '%s'.\n", filename);
    } else {
        print_system_info(stdout);
    }

    return EXIT_SUCCESS;
}
