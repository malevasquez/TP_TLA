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
	print_chord(value);
	return 0;
}

int PrintNoteGrammarAction(char * value) {
	LogDebug("PrintNoteGrammarAction(%s)", value);
	print_note(value);
	return 0;
}

int PrintToChordsGrammarAction(char * value) {
	LogDebug("PrintToChordsGrammarAction(%s)", value);
	printToChords(value);
	return 0;
}


// TODO: Check if strtok use is valid
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
	// char delimiter[] = " ";

	// func = strtok(func, delimiter);

	// char* noteVar1[20];
	// parser(1, noteVar1, notes);

	// if(noteVar1 == NULL || noteVar1->type ==)
	// char* noteVar2[20];
	// parser(2, noteVar2, notes);
	// char* noteVar3[20];
	// parser(3, noteVar3, notes);
	return 0;
}

int ToNotesGrammarAction(char * func, char * chord) {
	char delimiter[] = " ";
	func = strtok(func, delimiter);

	LogDebug("ToNotesGrammarAction(%s, %s)", func, chord);
	toNotes(chord);
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
	elem *var = getElemByName(scope, value);

	//TODO: Validaciones

	isChordSimple(var->value);
	return 0;
}

int ValidateVariableIsChordGrammarFromNotesAction(char *value) {
	LogDebug("ValidateVariableIsChordGrammarFromNotesAction(%s)", value);
	char *note1, *note2, *note3;

	note1 = strtok(value, " ");
	note2 = strtok(NULL, " ");
	note3 = strtok(NULL, " ");

	elem *var1 = getElemByName(scope, note1);
	elem *var2 = getElemByName(scope, note2);
	elem *var3 = getElemByName(scope, note3);
	
	// TODO: Validaciones

	isChordGivenNotes(var1->value, var2->value, var3->value);
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
/* ------------------------------------------------------ */ 
/*						ASSIGNMENT                        */
/* ------------------------------------------------------ */ 
int AssignmentNumByIdGrammarAction(int id, enum type type1, int value){
	int ret = addAssignById(scope, id, type1, NULL);
	if(ret == -1){
		LogError("assignment(1) %d", id);
		exit(1);
	}

	elem* var = getElemById(scope, id);
	dprintf(FD, "%s = %d", var->name, value);
	return ret;
}

int AssignmentStringByIdGrammarAction(int id, enum type type1, char* value){
	int ret = addAssignById(scope, id, type1, NULL);
	if(ret == -1){
		LogError("assignment(2) %d", id);
		exit(1);
	}

	elem* var = getElemById(scope, id);
	dprintf(FD, "%s = %s", var->name, value);
	return ret;
}

int AssignmentNumByNameGrammarAction(char *name, enum type type1, int value) {
	char dest[20];
	parser(0, dest, name);
	printf("assignment(3) dest value [%s]\n", dest);
	printf("assignment(3) type1 value: [%d]\n", type1);
	printf("assignment(3) value value: [%d]\n", value);
	int ret = addAssignByName(scope, dest, type1, NULL);
	if(ret == -1){
		LogError("assignment(3) %s", dest);
		exit(1);
	}

	dprintf(FD, "%s = %d", dest, value);
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
	if(type == _STRING){
		dprintf(FD, "char* %s", variableName);
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

int VariableExpressionGrammarAction(char* name) {
	char variable_name[20];
	parser(1, variable_name, name);
	elem *variable = getElemByName(scope, name);
	if(variable == NULL || variable->type != _INTEGER || variable->value == NULL) {
		LogError("Variable no valida");
		exit(1);
	}

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
	// print_note(note);
	return 0;
}

int ChordValueGrammarAction(char* chord) {
	LogDebug("ChordValueGrammarAction(%s)", chord);
	print_chord(chord);
	return 0;
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
