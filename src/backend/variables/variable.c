#include "variable.h"

enum notes getNoteEnum(char* noteStr){
    for (int i = 0; i < noteNameSize; i++){
        if(strcmp(noteStr, noteName[i]) == 0){
            return i;
        }
    }
    return -1;
}

char* getNoteStr(enum notes note){
    if(note < DO  || note > SI_S)
        return -1;
    return noteName[note];
}


enum chords getChordEnum(char* chordStr){
    for (int i = 0; i < chordNameSize; i++){
        if(strcmp(chordStr, chordName[i]) == 0){
            return i;
        }
    }
    return -1;
}

char* getChordStr(enum chords chord){
    if(chord < A  || chord > G)
        return -1;
    return chordName[chord];
}
