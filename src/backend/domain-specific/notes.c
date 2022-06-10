
#include <stdio.h>
#include <stdlib.h>

#include "notes.h"
#include "variable.h"

FILE* program_file;

void start_program() {
    FILE *file = fopen("archivoPrueba.c", "w");
    fprintf(file, "#include <stdio.h> int main()  {");
    program_file = file;
}

void end_program() {
    fprintf(program_file, "return 0; }");
    fclose(program_file);
}

void notes_to_chord(char* note1, char* note2, char* note3) {

    int notes[3]; 
    notes[0] = (getNoteEnum(note1) % 12);
    notes[1] = (getNoteEnum(note2) % 12);
    notes[2] = (getNoteEnum(note3) % 12);

    bubbleSort(notes, 3);

    if (notes[1] - notes[0] == 4 && notes[2] - notes[1] == 3) {
        printf("Acorde valido\n");
        printf("El acorde es: %s\n",getChordStr(notes[0]));
        fprintf(program_file, "printf(%s); ", getChordStr(notes[0]));
    }
    // TODO esto funciona para acordes menores, pero no se si vale la pena incorporarlo
    // else if (notes[1] - notes[0] == 3 && notes[2] - notes[1] == 4) {
    //     printf("Acorde valido\n");
    //     printf("El acorde es: %sm\n",getChordStr(notes[0]));
    //     fprintf(program_file, "El acorde es: %sm\n",getChordStr(notes[0]));
    // }
    else {
        printf("Acorde invalido\n");
    }

}

void chord_to_notes(char* chord_string) {
    
    int chord = getChordEnum(chord_string);

    printf("nota 1: %c\n", chord );
    printf("nota 2: %s\n", chord + 4);
    printf("nota 3: %s\n", chord + 7);

    // TODO esto es solo valido para acordes mayores,
    // no se como hariamos esto con los menores sin romper los enums
    fprintf(program_file, "printf(%s); ", getNoteStr(chord));
    fprintf(program_file, "printf(%s); ", getNoteStr(chord + 4));
    fprintf(program_file, "printf(%s); ", getNoteStr(chord + 7));
}