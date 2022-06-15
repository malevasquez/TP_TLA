#ifndef NOTES_H
#define NOTES_H

#include "../variables/variable.h"
#include "../support/utils.h"
#include "../support/logger.h"

void notes_to_chord(char* note1, char* note2, char* note3);
void chord_to_notes(char* chord);

void print_chord(char *chord);
void print_note(char *note);
void print_string(char *str);
void print_integer(int num);

int is_chord(char *value);
void is_note(char *note);

void concatNotes(char * note1, char * note2, char * note3);
void print_to_chords(char *notes);
void create_partiture(char * input);

#endif