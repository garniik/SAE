#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

const char *SaveGame = "SaveGame.txt";
const char *PlayerInfo = "PlayerInfo.txt";
const char *Story = "Story.txt";
const char *Histoire = "Histoire.txt";

void lecture_fichier(){
            // open the file
    FILE *in_file = fopen(PlayerInfo, "r");
    FILE *in_save = fopen(SaveGame, "r");
    FILE *in_story = fopen(Story, "r");
    FILE *in_histoire = fopen(Histoire, "r");
    // look and create file
 
    //sauvegarde Jeu
    if(in_save == NULL){
            printf("ERROR: file missing : save ! \n");
    }
    //sauvegarde histoire
    if(in_story == NULL){
            printf("ERROR: file missing : story ! \n");
    }
    if(in_histoire == NULL){
            printf("ERROR: file missing : histoire !\n");
    }
    //sauvegarde info joueur
    if(in_file == NULL){
             printf("ERROR: file missing : info_player !\n");
    }

     // read the file size
    struct stat sb;
    stat(SaveGame, &sb);
    // allocation of the character array
    char *file_contents = malloc(sb.st_size);
    // display line by line
    while (fscanf(in_file, " %[^\n] ", file_contents) != EOF) {
        printf(">%s\n", file_contents);
    }
    // closure of the file
}
int main(int argc, char *argv[])
{

        lecture_fichier();


}   