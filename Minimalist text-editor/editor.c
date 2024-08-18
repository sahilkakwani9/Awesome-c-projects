#include <stdio.h>
#include <string.h>

void edit_line(int edit_line, char *buffer)
{
    for (int i = 0; i < edit_line; i++)
    {
        buffer = strchr(buffer, '\n') + 1;
    }
    char *line_end = strchr(buffer, '\n');

    char saved[1024] = {0};
    strcpy(saved, line_end);
    printf("enter the text edit that line with: \n");
    scanf("%s", buffer);
    strcpy(buffer + strlen(buffer), saved);
}
int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    char buffer[1024] = {0};
    fread(buffer, 1024, 1, f);
    fclose(f);
    printf("Contents: \n%s\n", buffer);
    int current_line = 0;
    printf("Enter the line number to edit\n");
    scanf("%d", &current_line);
    edit_line(current_line, buffer);
    f = fopen(argv[1], "w");
    fwrite(buffer, strlen(buffer), 1, f);
    fclose(f);
    return 0;
}