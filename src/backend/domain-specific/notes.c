
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notes.h"

void introPartiture();
void createNewExtract();
void finishPartiture();
char* notesFromChord(char * chordStr, int sum);
char* replace_char(char* str, char find, char replace);

void notes_to_chord(char* note1, char* note2, char* note3) {

    int notes[3]; 
    notes[0] = (getNoteEnum(note1) % 13);
    notes[1] = (getNoteEnum(note2) % 13);
    notes[2] = (getNoteEnum(note3) % 13);

    bubbleSort(notes, 3);

    if (notes[1] - notes[0] == 4 && notes[2] - notes[1] == 3) {
        printf("Acorde valido\n");
        printf("El acorde es: %s\n",getChordStr(notes[0]));
        dprintf(FD, "printf(%s); ", getChordStr(notes[0]));
    }
    else {
        printf("Acorde invalido\n");
    }

}

void chord_to_notes(char* chord_string) {
    
    int chord = getChordEnum(chord_string);

    printf("nota 1: %s\n", getNoteStr(chord) );
    printf("nota 2: %s\n", getNoteStr((chord + 4) % 13));
    printf("nota 3: %s\n", getNoteStr((chord + 7) % 13));
}

//ver a donde va
void print_chord(char *chord) {
    dprintf(FD, "printf(\"Acorde: %s\\n\")", chord); 
}

void print_note(char *note) {
    // int note_num = getNoteEnum(note) % 13;
    dprintf(FD, "printf(\"Nota: %s\\n\")", note); 
}

void print_string(char *str) {
    dprintf(FD, "printf(\"%s\\n\")", str); 
}

void print_integer(int num) {
    dprintf(FD, "printf(\"%%d\\n\")", num); 
}

int is_chord(char *value) {
    char aux[20];
    strcpy(aux, value);
    char *note1 = strtok(aux, " ");
    char *note2 = strtok(NULL, " ");
    char *note3 = strtok(NULL, " ");

    replace_char(note1, ';','\0');
    replace_char(note2, ';','\0');
    replace_char(note3, ';','\0');

    int valid1 = getNoteEnum(note1);
    int valid2 = getNoteEnum(note2);
    int valid3 = getNoteEnum(note3);

    if(valid1 == -1 || valid2 == -1 || valid3 == -1) {
        return -1;
    }

    if (valid2 - valid1 == 4 && valid3 - valid2 == 3) {
        return 1;
    }

    return 0;
}

int is_chord_simple(char *value) {
    return getNoteEnum(value);
}

int is_chord_given_notes(char * note1, char * note2, char * note3) {
    
}

void concat_notes(char * note1, char * note2, char * note3) {

}

int is_note(char *note) {
    return getNoteEnum(note) != -1;
}

char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

int remove_duplicate(int arr[], int n) {
  if (n == 0 || n == 1)
    return n;

  int temp[n];

  int j = 0;
  int i;
  for (i = 0; i < n - 1; i++)
    if (arr[i] != arr[i + 1])
      temp[j++] = arr[i];
  temp[j++] = arr[n - 1];

  for (i = 0; i < j; i++)
    arr[i] = temp[i];

  return j;
}

void print_to_chords(char *notes) {
    char delimiter[2] = " ";
    char *token = strtok(notes, delimiter);

    int notesArray[20];

    int x = 0;
    while (token != NULL) {
        notesArray[x] = getNoteEnum(replace_char(token, ';','\0'));
        token = strtok(NULL, delimiter);
        x++;
    }

    int resultArray[10];
    int count = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            for (int h = 0; h < x; h++) {
                if (notesArray[j] - notesArray[i] == 4 && notesArray[h] - notesArray[j] == 3) {
                    resultArray[count++] = notesArray[i];
                }
            }
        }
    }
    int n = remove_duplicate(resultArray, count);
    for (int i = 0; i < n; i++) {
        printf("Acorde: %s\n", getChordStr(resultArray[i]));
    }
}

void create_partiture(char * input) {
    char delimiter[] = " ";
    int note_count = 0;
    int error = 0;
    int chord_enum;
    char note1[5];
    char note2[5];

    introPartiture();

    // Returns first musical note/chord
    char * token = strtok(input, delimiter);

    while(token != NULL) {
        if((note_count % 4) == 0  && note_count > 0)
            dprintf(LATEX_FD, "\\bar\n");

        if((note_count % 16) == 0 && note_count > 0) {
            createNewExtract();
        }

        if(getNoteEnum(token) != -1) {
            if(isSharp(token)) {
                token[strlen(token) - 1] = '\0';
                int note_num = getNoteNumber(token);
                dprintf(LATEX_FD, "\\NOtes \\qu{^%c} \\en\n", 'c' + note_num);
            }
            else {
                int note_num = getNoteNumber(token);
                dprintf(LATEX_FD, "\\NOtes \\qu{%c} \\en\n", 'c' + note_num);
            }
        } else if((chord_enum = getChordEnum(token)) != -1) {
            dprintf(LATEX_FD, "\\NOtes\\zqu{{%c}", 'c' + chord_enum);

            strcpy(note1, notesFromChord(token, 4));
            if(isSharp(note1)) {
                // int n = (int) (strchr(note1, '#') - note1);
                // note1[n] = '\0';
                // int note1_num = getNoteNumber(note1);
                // dprintf(LATEX_FD, "{^%c}} \\en\n", 'c' + note1_num);
            } else {
                int note1_num = getNoteNumber(note1);
                dprintf(LATEX_FD, "{%c}", 'c' + note1_num);
            }

            strcpy(note2, notesFromChord(token, 7));
            if(isSharp(note2)) {
                // int n = (int) (strchr(note2, '#') - note2);
                // note2[n] = '\0';
                // int note2_num = getNoteNumber(note2);
                // dprintf(LATEX_FD, "{^%c}} \\en\n", 'c' + note2_num);
            } else {
                int note2_num = getNoteNumber(note2);
                dprintf(LATEX_FD, "{%c}} \\en\n", 'c' + note2_num);
            }
        } else {
            LogError("Received list contains an invalid argument");
            exit(1);
        }

        note_count++;

        token = strtok(NULL, delimiter);
    }

    finishPartiture();
}

void introPartiture() {
    dprintf(LATEX_FD, "\\documentclass{article}\n");
    dprintf(LATEX_FD, "\\usepackage{musixtex}\n");
    dprintf(LATEX_FD, "\\begin{document}\n");
    dprintf(LATEX_FD, "\\begin{music}\n");
    dprintf(LATEX_FD, "\\instrumentnumber{1}\n");
    dprintf(LATEX_FD, "\\setstaffs1{1}\n");
    dprintf(LATEX_FD, "\\nobarnumbers\n");
    dprintf(LATEX_FD, "\\generalmeter{\\meterfrac44}\n");
    dprintf(LATEX_FD, "\\startextract\n");
    dprintf(LATEX_FD, "\\bar\n");
}

void createNewExtract() {
    dprintf(LATEX_FD, "\\zendextract\n");
    dprintf(LATEX_FD, "\\instrumentnumber{1}\n");
    dprintf(LATEX_FD, "\\setstaffs1{1}\n");
    dprintf(LATEX_FD, "\\nobarnumbers\n");
    dprintf(LATEX_FD, "\\generalmeter{\\meterfrac44}\n");
    dprintf(LATEX_FD, "\\startextract\n");
    dprintf(LATEX_FD, "\\bar\n");
}

void finishPartiture() {
    dprintf(LATEX_FD, "\\Endpiece\n");
    dprintf(LATEX_FD, "\\zendextract\n");
    dprintf(LATEX_FD, "\\end{music}\n");
    dprintf(LATEX_FD, "\\end{document}\n");
}

char* notesFromChord(char * chordStr, int sum) {
    int chord = getChordEnum(chordStr);

    switch (chord)
    {
    case 3:
        chord += 2;
        break;
    case 4:
        chord += 3;
        break;
    case 5:
        chord += 4;
        break;
    case 6:
        chord += 7;
    }

    return getNoteStr((chord + sum) % 12);
}
