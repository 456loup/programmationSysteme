#include <stdio.h>
#include <sys/types.h> 
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h> 


#define TAILLE_CHAINE 500



void listFilesRecursively(char *basePath , int indent)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
	    for(int i = 0 ; i < indent ; i++){
            
		printf("  "); 
	    }

            printf("%s\n", dp->d_name);
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path , indent+2);
        }
    }

    closedir(dir);
}



int main(int argc , char **argv){

    //listRep(argv[1] , 0);

    listFilesRecursively(argv[1] , 0 ); 


}
