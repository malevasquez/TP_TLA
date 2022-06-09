#ifndef VARIABLE_H
#define VARIABLE_H

#include <stdio.h>
#include <string.h>

enum notes {
  DO = 0,
  RE,
  MI,
  FA,
  SOL,
  LA,
  SI,
  DO_S,
  RE_S,
  MI_S,
  FA_S,
  SOL_S,
  LA_S,
  SI_S,
};

enum chords {
  A = 0,
  B,
  C,
  D,
  E,
  F,
  G,
};

//TODO no se si funciona
//quiero que cada uno guarde cuanto ocupa
enum type{
    NOTE = 0,
    CHORD,
    INTEGER,
    STRING,
};

static char* noteName[] = {"do",  "re",  "mi",  "sol",  "fa",  "si",
                    "do#", "re#", "mi#", "sol#", "fa#", "si#"};
static const int noteNameSize = 12;

static char* chordName[] = {"A", "B", "C", "D", "E", "F", "G"};
static const int chordNameSize = 7;

// todas las funciones devulven -1 si hubo un error
enum notes getNoteEnum(char *noteStr);
char *getNoteStr(enum notes note);
enum chords getChordEnum(char *chordStr);
char *getChordStr(enum chords chord);

int getTypeSize(enum type);

#endif