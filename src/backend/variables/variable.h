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
  SI
};

enum chords {
  C = 0,
  D,
  E,
  F,
  G,
  A,
  B
};

//TODO no se si funciona
//quiero que cada uno guarde cuanto ocupa
enum type{
    _NOTE = 0,
    _CHORD,
    _INTEGER,
    _STRING,
};

static char* noteName[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#","sol", "sol#", "la", "la#", "si"};
static const int noteNameSize = 12;

static char* chordName[] = {"C", "D", "E", "F", "G", "A", "B"};
static const int chordNameSize = 7;

static char* majorNotesName[] = {"do", "re", "mi", "fa", "sol", "la", "si"};
static const int majorNotesNameSize = 7;

static char* minorNotesName[] = {"do#", "re#", "fa#", "sol#", "la#"};
static const int minorNotesNameSize = 5;

// todas las funciones devulven -1 si hubo un error
enum notes getNoteEnum(char *noteStr);
char *getNoteStr(enum notes note);
enum chords getChordEnum(char *chordStr);
char *getChordStr(enum chords chord);
int isSharp(char *noteStr);
int getNoteNumber(char *noteStr);

#endif