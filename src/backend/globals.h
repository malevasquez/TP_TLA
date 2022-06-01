#include <stdio.h>

enum note{
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

enum chord{
    A=0,
    B,
    C,
    D,
    E,
    F,
    G,
};

char* noteName[] = {"do", "re", "mi", "sol", "fa", "si", "do#", "re#", "mi#", "sol#", "fa#", "si#"};

char* chardName[]  = {"A", "B", "C", "D", "E", "F", "G"};

