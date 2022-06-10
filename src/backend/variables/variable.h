#ifndef VARIABLE_H
#define VARIABLE_H

#include <stdio.h>
#include <string.h>

enum notes {
  DO = 0,
  DO_S,
  RE,
  RE_S,
  MI,
  FA,
  FA_S,
  SOL,
  SOL_S,
  LA,
  LA_S,
  SI,
};

enum chords {
  C,
  C_S,
  D,
  D_S,
  E,
  F,
  F_S
  G,
  G_S,
  A,
  A_S
  B,
};

//TODO no se si funciona
//quiero que cada uno guarde cuanto ocupa
enum type{
    NOTE = 0,
    CHORD,
    INTEGER,
    STRING,
};

static char* noteName[] = {"do", "do#", "re", "re#", "mi", "mi#", "fa", "fa#","sol", "sol#", "la", "la#","si", "si#",};
static const int noteNameSize = 12;

static char* chordName[] = {"C", "C#" "D", "D#","E","F", "F#", "G", "G#", "A", "A#", "B"};
static const int chordNameSize = 7;

// todas las funciones devulven -1 si hubo un error
enum notes getNoteEnum(char *noteStr);
char *getNoteStr(enum notes note);
enum chords getChordEnum(char *chordStr);
char *getChordStr(enum chords chord);

#endif