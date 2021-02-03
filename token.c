#include <stdio.h>
#include <string.h>

#include "global.h"

char next_char(){
	char ret;
	if(Putback == 0){
		ret = getc(Infile);
		if(ret == '\n'){
			++Line;
			CharPosition = -1;
		}
		++CharPosition;
	}else{
		ret = Putback;
		Putback = 0;
	}

	return ret;
}

void putback(char c){
	Putback = c;
}

char skip_whitespace(){
	char c = next_char();
	while(' ' == c || '\t' == c ||\
		'\n' == c || '\r' == c || '\f' == c){
		c = next_char();
	}

	return c;
}

int char_index(char *s, int c){
 	char *p;
 	
 	p = strchr(s, c);
	return (p ? p - s : -1);
}

static int scan_int(int c) {
	int k, val = 0;
	
	while ((k = char_index("0123456789", c)) >= 0) {
		val = val * 10 + k;
		c = next_char();
	}
	
	putback(c);
	return val;
}

struct token next_token(){
	struct token t;
	char c = skip_whitespace();
	
	switch(c){
		case EOF:
			t.token = T_EOF;
			break;
		case '+':
			t.token = T_PLUS;
			break;
		case '-':
			t.token = T_MINUS;
			break;
		case '*':
			t.token = T_STAR;
			break;
		case '/':
			t.token = T_SLASH;
			break;
		default:
			if(char_index("0123456789", c) >= 0){
				t.token = T_INT_LITERAL;
				t.intvalue = scan_int(c);
			}
	}

	return t;
}
