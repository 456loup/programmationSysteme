#include <stdio.h>
#include <stdlib.h> 
#include <sys/stat.h>
#include <sys/types.h> 
#include <dirent.h> 
#include <string.h> 


int makedir(int argc , char **argv){

    int i = 0; 
    int reussite = 0; 
    for(int i = 1 ; i < argc ; i++){
        reussite = mkdir(argv[i] , S_IRWXU); 
	if(reussite != 0){
	    printf(" IMPOSSIBLE DE CREER LE FICHIER %s " , argv[i]); 
	    exit(1); 
	}else{
	    printf(" repertoire %s cree avec succes " , argv[i]); 
	}
    }
    return reussite; 
}


int afficherNom(char *nomRepertoire){

    DIR * rep  = opendir(nomRepertoire);
    struct dirent *entree ;  
    int i = 0; 

    while((entree = readdir(rep)) != NULL){
       i++; 
       printf(" entree : %d vaut %s  " , i , entree->d_name);  
    }

    closedir(rep); 

    return 0; 
}

/*
 *
 * L 'appel récursif fonctionne désormais  
 *
 *
 * */
void afficherNomRec(char *nomRepertoire){

    DIR * rep  = opendir(nomRepertoire);
    char transition[500]; 
    struct dirent *entree; 
    struct stat buff;  
    int i = 0;

    if(rep != NULL){
   	 while((entree = readdir(rep)) != NULL && strcmp("..", entree->d_name ) != 0 && strcmp("." , entree->d_name) != 0){
	
		strcpy(transition , nomRepertoire);  
		strcat(transition , "/"); 
		strcat(transition , entree->d_name);
		lstat(transition , &buff); 
		if(S_ISDIR(buff.st_mode)){
		    printf("\n\n le repertoire %s a pour enfant %s  \n " , nomRepertoire , entree->d_name);
		}	
		afficherNomRec(transition);
    	}
   }

   closedir(rep);     

}





int main(int argc , char **argv){

 
     afficherNomRec(argv[1]);  

    return 0; 
}
