#include <stdio.h>
#include <dirent.h>
#include <errno.h>
int main() {
 struct dirent *entry;
 DIR *dir;
 char dirname[100];
 printf("Enter directory name: ");
 scanf("%s", dirname);
 if ((dir = opendir(dirname)) == NULL) {
 perror("Failed to open directory");
 return 1;
 }
 while ((entry = readdir(dir)) != NULL) {
 printf("%s\n", entry->d_name);
 }
 closedir(dir);
 return 0;
}
