#ifndef NOTES_H
#define NOTES_H

#include "../variables/variable.h"
#include "../support/utils.h"
#include "../support/logger.h"

void start_program();
void end_program();
void notes_to_chord(char* note1, char* note2, char* note3);
void chord_to_notes(char* chord);
void print_chord(char *chord);
void print_note(char *note);

#endif