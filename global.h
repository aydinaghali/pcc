#ifndef extern_
	#define extern_ extern
#endif

extern_ int CharPosition;
extern_ int Line;
extern_ FILE* Infile;
extern_ char Putback;

enum {
	T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INT_LITERAL
};

struct token {
	int token;
	int intvalue;
};
