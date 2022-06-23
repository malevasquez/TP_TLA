#include "bison-actions.h"

scopeADT scope;

int parser(int n, char* dest, char* src);

/**
 * Implementación de "bison-grammar.h".
 */

void yyerror(const char * string) {
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i) {
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");

	
}


/* ------------------------------------------------------ */ 
/*						  MARKERS                         */
/* ------------------------------------------------------ */ 

int ProgramGrammarAction(char* value) {
	LogDebug("ProgramGrammarAction(%s)", value);
	start_program();
	state.succeed = true;
	state.result = 0;
	scope = newScope();
	return 0;
}

int EndProgramGrammarAction(char* value) {
	LogDebug("EndProgramGrammarAction(%s)", value);
	end_program();
	return 0;
}

int AdditionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("AdditionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Add(leftValue, rightValue);
}

int SubtractionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("SubtractionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Subtract(leftValue, rightValue);
}

int MultiplicationExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("MultiplicationExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Multiply(leftValue, rightValue);
}

int DivisionExpressionGrammarAction(const int leftValue, const int rightValue) {
	LogDebug("DivisionExpressionGrammarAction(%d, %d)", leftValue, rightValue);
	return Divide(leftValue, rightValue);
}

int FactorExpressionGrammarAction(const int value) {
	LogDebug("FactorExpressionGrammarAction(%d)", value);
	return value;
}

int ExpressionFactorGrammarAction(const int value) {
	LogDebug("ExpressionFactorGrammarAction(%d)", value);
	return value;
}

int ConstantFactorGrammarAction(const int value) {
	LogDebug("ConstantFactorGrammarAction(%d)", value);
	return value;
}

/* ------------------------------------------------------ */ 
/*						OPERACIONES                       */
/* ------------------------------------------------------ */ 

int PlusGrammarAction(char * value) {
	LogDebug("PlusGrammarAction(%s)", value);
	plusValue();
	return 0;
}

int MinusGrammarAction(char * value) {
	LogDebug("MinusGrammarAction(%s)", value);
	minusValue();
	return 0;
}

int MultiplyGrammarAction(char * value) {
	LogDebug("MultiplyGrammarAction(%s)", value);
	multiplyValue();
	return 0;
}

int DivideGrammarAction(char * value) {
	LogDebug("DivideGrammarAction(%s)", value);
	divideValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*			      CONDITIONALES & CYCLOS				  */
/* ------------------------------------------------------ */ 

int IfGrammarAction(char * value) {
	LogDebug("IfGrammarAction(%s)", value);
	ifValue();
	return 0;
}

int ThenGrammarAction(char * value) {
	LogDebug("ThenGrammarAction(%s)", value);
	thenValue();
	return 0;
}

int ElseGrammarAction(char * value) {
	LogDebug("ElseGrammarAction(%s)", value);
	elseValue();
	return 0;
}

int EndIfGrammarAction(char * value) {
	LogDebug("EndIfGrammarAction(%s)", value);
	endIfValue();
	return 0;
}

int DoGrammarAction(char * value) {
	LogDebug("DoGrammarAction(%s)", value);
	doStatementValue();
	return 0;
}

int WhileGrammarAction(char * value) {
	LogDebug("WhileGrammarAction(%s)", value);
	whileValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*						COMPARACION                       */
/* ------------------------------------------------------ */

int GreaterGrammarAction(char * value) {
	LogDebug("GreaterGrammarAction(%s)", value);
	greaterValue();
	return 0;
}

int LowerGrammarAction(char * value) {
	LogDebug("LowerGrammarAction(%s)", value);
	lowerValue();
	return 0;
}

int EqualGrammarAction(char * value) {
	LogDebug("EqualGrammarAction(%s)", value);
	equalValue();
	return 0;
}

int NotEqualGrammarAction(char * value) {
	LogDebug("NotEqualGrammarAction(%s)", value);
	notEqualValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*					 	 OP LOGICOS                       */
/* ------------------------------------------------------ */

int AndGrammarAction(char * value) {
	LogDebug("AndEqualGrammarAction(%s)", value);
	andValue();
	return 0;
}

int OrGrammarAction(char * value) {
	LogDebug("OrGrammarAction(%s)", value);
	orValue();
	return 0;
}

int NotGrammarAction(char * value) {
	LogDebug("NotGrammarAction(%s)", value);
	notValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*				   	  VALORES DE VERDAD                   */
/* ------------------------------------------------------ */

int TrueGrammarAction(char * value) {
	LogDebug("TrueGrammarAction(%s)", value);
	trueValue();
	return 0;
}

int FalseGrammarAction(char * value) {
	LogDebug("FalseGrammarAction(%s)", value);
	falseValue();
	return 0;
}

/* ------------------------------------------------------ */ 
/*						 FUNCIONES                        */
/* ------------------------------------------------------ */ 

int PrintIntegerGrammarAction(int value) {
	LogDebug("PrintIntegerGrammarAction(%d)", value);
	printNum(value);
	return 0;
}

int PrintStringGrammarAction(char * value) {
	LogDebug("PrintStringGrammarAction(%s)", value);
	printStr(value);
	return 0;
}

int PrintChordGrammarAction(char * value) {
	LogDebug("PrintChordGrammarAction(%s)", value);
	printChord(value);
	return 0;
}

int PrintNoteGrammarAction(char * value) {
	LogDebug("PrintNoteGrammarAction(%s)", value);
	printNote(value);
	return 0;
}

int PrintVariableGrammarAction(char* value) {
	elem *element = (elem*) getElemByName(scope, value);
	
	if(element == NULL || element->value == NULL) {
		LogError("Variable %s en PrintVariableGrammarAction invalida.", value);
		exit(1);
	}

	// Check type
	if(element->type == _STRING) {
		printStr(ATTACHMENT_STR(element));
	} else if(element->type == _INTEGER) {
		printNum(ATTACHMENT_INT(element));
	} else if(element->type == _NOTE) {
		char* note = getNoteStr(ATTACHMENT_INT(element));
		printNote(note);
	} else if(element->type == _CHORD) {
		char* chord = getChordStr(ATTACHMENT_INT(element));
		printChord(chord);
	}

	LogDebug("PrintVariableGrammarAction(%s)", value);
	return 0;
}

int PrintToChordsGrammarAction(char * value) {
	LogDebug("PrintToChordsGrammarAction(%s)", value);
	int len = strlen(value);
	value[len - 1] = '\0';
	printToChords(value);
	return 0;
}

int PrintToChordsVariableGrammarAction(char* value) {
	char* notesArray = value;
	int value_len = strlen(value);
	char true_value[100];
	strncpy(true_value, value, value_len - 1);
	true_value[value_len - 1] = '\0';
	char delimiter[] = " ";

	char* token = strtok(true_value, delimiter);

	char notes[100] = "\0";
	elem* elem1;
	char* value1;

	while (token != NULL)
	{
		elem1 = (elem*) getElemByName(scope, token);
		value1 = getNoteStr(ATTACHMENT_INT(elem1));

		if(elem1 == NULL || elem1->type != _NOTE || elem1->value == NULL) {
			LogError("Variable %s en PrintToChordsVariableGrammarAction invalida.", token);
			exit(1);
		}

		strcat(notes, value1);
		strcat(notes, " ");

		token = strtok(NULL, delimiter);
	}
	value_len = strlen(notes);
	notes[value_len - 1] = '\0';

	printToChords(notes);
	LogDebug("PrintToChordsVariableGrammarAction(%s)", notesArray);
	return 0;
}


int ToChordGrammarAction(char* func, char* notes) {
	char delimiter[] = " ";

	func = strtok(func, delimiter);

	char *note1, *note2, *note3;

	note1 = strtok(notes, delimiter);
	note2 = strtok(NULL, delimiter);
	note3 = strtok(NULL, delimiter);
	toChord(note1, note2, note3);
	LogDebug("ToChordGrammarAction(%s, %s, %s, %s)", func, note1, note2, note3);
	return 0;
}

int ToChordVariabledGrammarAction(char* func, char* notes) {
	char delimiter[] = " ";

	func = strtok(func, delimiter);

	char *note1, *note2, *note3;

	note1 = strtok(notes, delimiter);
	note2 = strtok(NULL, delimiter);
	note3 = strtok(NULL, delimiter);

	elem *elem1 = (elem*) getElemByName(scope, note1);
	elem *elem2 = (elem*) getElemByName(scope, note2);
	elem *elem3 = (elem*) getElemByName(scope, note3);

	if(elem1 == NULL || elem1->type != _NOTE || elem1->value == NULL) {
		LogError("Variable %s en ToChordVariabledGrammarAction invalida.", note1);
		exit(1);
	}

	if(elem2 == NULL || elem2->type != _NOTE || elem2->value == NULL) {
		LogError("Variable %s en ToChordVariabledGrammarAction invalida.", note2);
		exit(1);
	}

	if(elem3 == NULL || elem3->type != _NOTE || elem3->value == NULL) {
		LogError("Variable %s en ToChordVariabledGrammarAction invalida.", note3);
		exit(1);
	}

	char* value1 = getNoteStr(ATTACHMENT_INT(elem1));
	char* value2 = getNoteStr(ATTACHMENT_INT(elem2));
	char* value3 = getNoteStr(ATTACHMENT_INT(elem3));

	toChord(value1, value2, value3);

	LogDebug("ToChordVariabledGrammarAction(%s, %s, %s, %s)", func, note1, note2, note3);
	return 0;
}

int ToNotesGrammarAction(char * func, char * chord) {
	char delimiter[] = " ";
	func = strtok(func, delimiter);

	LogDebug("ToNotesGrammarAction(%s, %s)", func, chord);
	toNotes(chord);
	return 0;
}

int ToNotesVariableGrammarAction(char* chord_var) {
	elem* chord_elem = (elem*) getElemByName(scope, chord_var);

	if(chord_elem == NULL || chord_elem->type != _CHORD || chord_elem->value == NULL) {
		LogError("Variable %s en ToNotesVariableGrammarAction invalida.", chord_var);
		exit(1);
	}

	char* chord_name = getChordStr(ATTACHMENT_INT(chord_elem));
	toNotes(chord_name);

	return 0;
}

int ConcatNotesGrammarAction(char * func, char * notes) {
	char delimiter[] = " ";

	func = strtok(func, delimiter);

	char *note1, *note2, *note3;

	note1 = strtok(notes, delimiter);
	note2 = strtok(NULL, delimiter);
	note3 = strtok(NULL, delimiter);
	concatNotes(note1, note2, note3);
	LogDebug("ConcatNotesGrammarAction(%s, %s, %s, %s)", func, note1, note2, note3);
	
	return 0;
}

int ConcatVariableNotesGrammarAction(char* variables) {
	char delimiter[] = " ";

	char* variable1 = strtok(variables, delimiter);
	char* variable2 = strtok(NULL, delimiter);
	char* variable3 = strtok(NULL, delimiter);

	elem* elem1 = (elem*) getElemByName(scope, variable1);

	if(elem1 == NULL || elem1->type != _NOTE || elem1->value == NULL) {
		LogError("Variable %s en ConcatVariableNotesGrammarAction invalida.", variable1);
		exit(1);
	}

	elem* elem2 = (elem*) getElemByName(scope, variable2);

	if(elem2 == NULL || elem2->type != _NOTE || elem2->value == NULL) {
		LogError("Variable %s en ConcatVariableNotesGrammarAction invalida.", variable2);
		exit(1);
	}

	elem* elem3 = (elem*) getElemByName(scope, variable3);

	if(elem3 == NULL || elem3->type != _NOTE || elem3->value == NULL) {
		LogError("Variable %s en ConcatVariableNotesGrammarAction invalida.", variable3);
		exit(1);
	}

	char* note1 = getNoteStr(ATTACHMENT_INT(elem1));
	char* note2 = getNoteStr(ATTACHMENT_INT(elem2));
	char* note3 = getNoteStr(ATTACHMENT_INT(elem3));

	concatNotes(note1, note2, note3);
	LogDebug("ConcatVariableNotesGrammarAction(%s, %s, %s)", note1, note2, note3);

	return 0;
}

int ValidateIsNoteGrammarAction(char *value) {
	LogDebug("ValidateIsNoteGrammarAction(%s)", value);
	isNote(value);
	return 0;
}

int ValidateVariableIsNoteGrammarAction(char *value) {
	LogDebug("ValidateVariableIsNoteGrammarAction(%s)", value);
	elem *variable = getElemByName(scope, value);
	// if(variable == NULL || variable->type != _STRING || variable->value == NULL) {
	// 	LogError("Variable no valida");
	// 	exit(1);
	// }

	isChordSimple(variable->value);
	return 0;
}

int ValidateIsChordGrammarAction(char *value) {
	LogDebug("ValidateIsChordGrammarAction(%s)", value);
	isChord(value);
	return 0;
}

int ValidateIsChordFromSingleVariableGrammarAction(char *value) {
	LogDebug("ValidateIsChordFromSingleVariableGrammarAction(%s)", value);
	elem *var = (elem*) getElemByName(scope, value);

	if(var == NULL || var->type != _CHORD || var->value == NULL) {
		LogError("Variable %s en ValidateIsChordFromSingleVariableGrammarAction invalida.", var);
		exit(1);
	}

	isChordSimple(ATTACHMENT_STR(var));
	return 0;
}

int ValidateVariableIsChordGrammarFromNotesAction(char *value) {
	LogDebug("ValidateVariableIsChordGrammarFromNotesAction(%s)", value);
	char *note1, *note2, *note3;

	note1 = strtok(value, " ");
	note2 = strtok(NULL, " ");
	note3 = strtok(NULL, " ");

	elem *var1 = (elem*) getElemByName(scope, note1);
	elem *var2 = (elem*) getElemByName(scope, note2);
	elem *var3 = (elem*) getElemByName(scope, note3);
	
	if(var1 == NULL || var1->type != _NOTE || var1->value == NULL) {
		LogError("Variable %s en ValidateVariableIsChordGrammarFromNotesAction invalida.", note1);
		exit(1);
	}

	if(var2 == NULL || var2->type != _NOTE || var2->value == NULL) {
		LogError("Variable %s en ValidateVariableIsChordGrammarFromNotesAction invalida.", note2);
		exit(1);
	}

	if(var3 == NULL || var3->type != _NOTE || var3->value == NULL) {
		LogError("Variable %s en ValidateVariableIsChordGrammarFromNotesAction invalida.", note3);
		exit(1);
	}

	isChordGivenNotes(getNoteStr(ATTACHMENT_INT(var1)), getNoteStr(ATTACHMENT_INT(var2)), getNoteStr(ATTACHMENT_INT(var3)));
	return 0;
}

int ValidateIsChordFromSingleNoteGrammarAction(char *value) {
	LogDebug("ValidateIsChordFromSingleNoteGrammarAction(%s)", value);
	isChordSimple(value);
	return 0;
}


int ValidateIsChordFromNotesGrammarAction(char *value) {
	LogDebug("ValidateIsChordFromNotesGrammarAction(%s)", value);
	char *note1, *note2, *note3;

	note1 = strtok(value, " ");
	note2 = strtok(NULL, " ");
	note3 = strtok(NULL, " ");

	isChordGivenNotes(note1, note2, note3);
	return 0;
}

int CreatePartitureGrammarAction(char * input) {
	input[strlen(input) - 1] = '\0';
	LogDebug("CreatePartitureGrammarAction(%s)", input);
	
	create_partiture(input);

	return 0;
}

/* ------------------------------------------------------ */ 
/*						 SIMBOLOS                         */
/* ------------------------------------------------------ */ 

int OpenParGrammarAction(char * value) {
	LogDebug("OpenParGrammarAction(%s)", value);
	openParValue();
	return 0;
}

int CloseParGrammarAction(char * value) {
	LogDebug("CloseParGrammarAction(%s)", value);
	closeParValue();
	return 0;
}

int DelimiterGrammarAction(char * value) {
	LogDebug("DelimiterGrammarAction(%s)", value);
	delimiterValue();
	return 0;
}

void AssignValueGrammarAction() {
	LogDebug("AssignValueGrammarAction()");
	dprintf(FD, " = ");
}

/* ------------------------------------------------------ */ 
/*						ASSIGNMENT                        */
/* ------------------------------------------------------ */ 
int AssignmentNumByIdGrammarAction(int id, enum type type1, int value){
	int ret = addAssignById(scope, id, type1, &value);
	if(ret == -1){
		LogError("Error in AssignmentNumByIdGrammarAction %d", id);
		exit(1);
	}

	elem* var = (elem*) getElemById(scope, id);
	if(var == NULL || var->type != type1 || ATTACHMENT_INT(var) != value) {
		LogError("Error in AssignmentNumByIdGrammarAction %d", id);
		exit(1);
	}
	return ret;
}

int AssignmentStringByIdGrammarAction(int id, enum type type1, char* value){
	int ret = addAssignById(scope, id, type1, value);
	if(ret == -1){
		LogError("assignment(2) %d", id);
		exit(1);
	}

	elem* var = (elem*) getElemById(scope, id);
	// dprintf(FD, "%s = %s", var->name, ATTACHMENT_STR(var));
	return ret;
}

int AssignmentNumByNameGrammarAction(char *name, enum type type1, int value) {
	char dest[20];
	parser(0, dest, name);
	int ret = addAssignByName(scope, dest, type1, &value);
	if(ret == -1){
		LogError("assignment(3) %s", dest);
		exit(1);
	}
	LogDebug("AssignmentNumByNameGrammarAction(%s, %d, %d)", dest, type1, value);
	return ret;
}

int AssignmentStringByNameGrammarAction(char *name, enum type type1, char* value) {
	char dest[20];
	parser(0, dest, name);
	int ret = addAssignByName(scope, dest, type1, NULL);
	if(ret == -1){
		LogError("assignment(4) %s", dest);
		exit(1);
	}

	dprintf(FD, "%s = %s", dest, value);
	return ret;
}


/* ------------------------------------------------------ */ 
/*						DEFINITION                        */
/* ------------------------------------------------------ */ 

int DefinitionGrammarAction(enum type type, char *variableName){
	int len = strlen(variableName);
	if(variableName[len - 1] == ';')
		variableName[len - 1] = '\0';
	if(type == _STRING){
		dprintf(FD, "char* %s;\n", variableName);
	}else if(type == _INTEGER) {
		dprintf(FD, "int %s", variableName);
	}else{
		dprintf(FD, "int %s", variableName);
	}
	int ret = addDefinition(scope, type, variableName);
	if(ret == -1){
		LogError("Definition %s", variableName);
		exit(1);
	}
	return ret;
}

int DefinitionForAssignGrammarAction(enum type type, char *variableName) {
	variableName = strtok(variableName, " ");
	
	LogDebug("DefinitionForAssignGrammarAction(%d, %s)", type, variableName);
	int ret = DefinitionGrammarAction(type, variableName);
	if(type != _STRING)
		dprintf(FD, ";\n");
	dprintf(FD, "\n%s", variableName);
	return ret;
}


int VariableExpressionGrammarAction(char* name) {
	char variable_name[20];
	parser(1, variable_name, name);
	elem *variable = getElemByName(scope, name);
	if(variable == NULL || variable->type != _INTEGER || variable->value == NULL) {
		LogError("Variable %s no valida", name);
		exit(1);
	}

	dprintf(FD, "%s", variable->name);

	return 0;
}

/* ------------------------------------------------------ */ 
/*						DATA TYPES                        */
/* ------------------------------------------------------ */ 

int IntegerConstantGrammarAction(const int value) {
	LogDebug("IntegerConstantGrammarAction(%d)", value);
	getIntegerValue(value);
	return value;
}

char* StringValueGrammarAction(char* str) {
	LogDebug("StringValueGrammarAction(%s)", str);
	getStringValue(str);
	return str;
}

int NoteValueGrammarAction(char* note) {
	LogDebug("NoteValueGrammarAction(%s)", note);
	int n = getNoteEnum(note);
	if(n == -1) {
		LogError("Nota invalida.");
		exit(1);
	}
	dprintf(FD, "%d", n);
	return n;
}

int ChordValueGrammarAction(char* chord) {
	LogDebug("ChordValueGrammarAction(%s)", chord);
	// print_chord(chord);
	int n = getChordEnum(chord);
	if(n == -1) {
		LogError("Acorde invalido.");
		exit(1);
	}
	dprintf(FD, "%d", n);
	return n;
}

char* VariableValueGrammarAction(char* variable) {
	LogDebug("VariableValueGrammarAction(%s)", variable);
	dprintf(FD, "%s", variable);
	return variable;
}

int parser(int n, char* dest, char* src){
	int i = 0, j=0;
	while(src[i] != '\n' && n != -1){
		if(src[i] == ' '){
			n--;
		}
		if(n == 0){
			dest[j] = src[i];
			j++;
		}
		i++;
	}
	dest[j++] = '\0';
	return j;
}
