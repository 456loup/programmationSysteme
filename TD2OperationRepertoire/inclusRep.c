#include <stdio.h>
#include <stdlib.h> 
#include <sys/stat.h>
#include <sys/types.h> 
#include <dirent.h> 
#include <string.h> 


/* a continuer demain (si l on peut mdrr)   */

void inclusRepV1(char *cheminEnfant , char *CheminParent , char **chaineProgression , int *index , int tailleCheminParent ){ 

    strncat(chaineProgression , "/" , 1); 
    for(*index = *index ; *index < tailleCheminParent && CheminParent[*index] == '/' ; *index++){
        strncat(chaineProgression , CheminParent[*index] , 1);
    } 
    *index++; 

   if(*index < tailleCheminParent){
  
       DIR * rep = openDir(chaineProgression); 
       struct dirent *entree; 
       struct stat buff; 

       while( (entree = readdir(rep) ) != NULL ){
       
           
       
       } 
   
   } 
}


int main(int argc , char **argv){


}
