
#include <stdio.h>
#include <stdlib.h>

#include "notes.h"

void start_program() {
    // FILE *file = fopen("archivoPrueba.c", "w");
    dprintf(5, "#include <stdio.h> int main()  {");
    // printf("#include <stdio.h> int main()  {");
    // program_file = file;
}

void end_program() {
    dprintf(5, "return 0; }");
    // printf("return 0;");
    // fclose(program_file);
}

void notes_to_chord(char* note1, char* note2, char* note3) {

    int notes[3]; 
    notes[0] = (getNoteEnum(note1) % 13);
    notes[1] = (getNoteEnum(note2) % 13);
    notes[2] = (getNoteEnum(note3) % 13);

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

    printf("nota 1: %s\n", getNoteStr(chord) );
    printf("nota 2: %s\n", getNoteStr((chord + 4) % 13));
    printf("nota 3: %s\n", getNoteStr((chord + 7) % 13));

    // TODO esto es solo valido para acordes mayores,
    // no se como hariamos esto con los menores sin romper los enums
    fprintf(program_file, "printf(%s); ", getNoteStr(chord));
    fprintf(program_file, "printf(%s); ", getNoteStr(chord + 4));
    fprintf(program_file, "printf(%s); ", getNoteStr(chord + 7));
}

//ver a donde va
void print_chord(char *chord) {
    printf("acorde: %s\n", chord);
    fprintf(program_file, "printf(%s); ", chord); 
}

void print_note(char *note) {
    int note_num = getNoteEnum(note) % 13;
    printf("nota: %d", note_num);
    fprintf(program_file, "printf(%d); ", note_num); 
}