#include <stdio.h>

#define extern_
#include "global.h"
#undef extern_

#include "token.h"

int main(int argc, char** argv){
	Infile = fopen("inp.txt", "r");

	{
		struct token t;
		while( (t = next_token()).token != T_EOF ){
			switch(t.token){
				case T_PLUS:
					printf("PLUS\n");
					break;
				case T_MINUS:
					printf("MINUS\n");
					break;
				case T_STAR:
					printf("STAR\n");
					break;
				case T_SLASH:
					printf("SLASH\n");
					break;
				case T_INT_LITERAL:
					printf("INTEGER : %d\n", t.intvalue);
					break;
			}
		}
	}
	
	return 0;
}
