#include "variable.h"

enum notes getNoteEnum(char *noteStr) {
  for (int i = 0; i < noteNameSize; i++) {
    if (strcmp(noteStr, noteName[i]) == 0) {
      return i;
    }
  }
  return -1;
}

char *getNoteStr(enum notes note) {
  if (note < DO || note > SI)
    return NULL;
  return noteName[note];
}

enum chords getChordEnum(char *chordStr) {
  for (int i = 0; i < chordNameSize; i++) {
    if (strcmp(chordStr, chordName[i]) == 0) {
      return i;
    }
  }
  return -1;
}

char *getChordStr(enum chords chord) {
  if (chord < C || chord > B)
    return NULL;
  return chordName[chord];
}

int isSharp(char *noteStr) {
  if(strchr(noteStr, '#') != NULL) {
    // True
    return 1;
  } 
  // False
  return 0;
}


int getNoteNumber(char *noteStr) {
  for (int i = 0; i < majorNotesNameSize; i++) {
    if (strcmp(noteStr, majorNotesName[i]) == 0) {
      return i;
    }
  }
  return -1;
}