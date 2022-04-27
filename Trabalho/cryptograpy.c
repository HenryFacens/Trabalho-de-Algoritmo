#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

#define TEMP_FILE_NAME "FACENS PROJECT"

bool CopyFile(char INPUT_FILE_NAME[255], char OUTPUT_FILE_NAME[255]) {

    FILE *input_file, *output_file;
    char character;

    input_file = fopen(INPUT_FILE_NAME, "r");
    output_file = fopen(OUTPUT_FILE_NAME, "w");
    if ((input_file == NULL) || (output_file == NULL)) {
        return false;
    }

    character = fgetc(input_file);
    while (character != EOF) {   //EOF=erro
		fputc(character, output_file);
        character = fgetc(input_file);
    }

    fclose(input_file);
    fclose(output_file);
}


bool encryption(char key[], char INPUT_FILE_NAME[], int method){

    FILE *original_file, *temp_file;
    char character;

    //CopyFile(INPUT_FILE_NAME, "backup.txt");

    original_file = fopen(INPUT_FILE_NAME, "r");
    temp_file = fopen(TEMP_FILE_NAME, "w");
    if ((original_file == NULL) || (temp_file == NULL)) {
        return 0;
    }
    
    character = fgetc(original_file);
    int position_key = 0;
    while (character != EOF) {
    	
		character += key[position_key]*method;
		
        fputc(character, temp_file);
        
        if (key[position_key] == '\0') {
            position_key = 0;
            
        }
        else {
            position_key += 1;
            
        }
        
        character = fgetc(original_file);
        
    }

    fclose(original_file);
    
    fclose(temp_file);
	
    CopyFile(TEMP_FILE_NAME, INPUT_FILE_NAME);

    if (!remove(TEMP_FILE_NAME)) {
        return true;
    }
    else {
        return false;
    }
}


bool Encode(char key[], char INPUT_FILE_NAME[]) {
    return encryption(key, INPUT_FILE_NAME, 1);
}

bool Decode(char key[], char INPUT_FILE_NAME[]) {
    return encryption(key, INPUT_FILE_NAME, -1);
}
