
FILE *cg_set(char *s);

int main(int argc,char *argv[]) {
	if (argc != 3)	{
        fprintf(stderr, "Usage: blitz8086 input.txt a.bin\n");
        return 1;
    }
	yyin = fopen(argv[1],"r");
    if (yyin == NULL) {
        fprintf(stderr, "could not open input: %s\n", strerror(errno));
        return 2;
    }
    FILE *fp = cg_set(argv[2]);
    if (fp == NULL) {
        fprintf(stderr, "could not open output: %s\n", strerror(errno));
        return 3;
    }

	int passes = 0;
	init_dict();

	reset_unres();
	do {
    	reset_byte();
    	fseek(yyin,0,0);
        yyparse();
        passes++;
    } while (chk_unres());

    // print summary and exit
    printf("\nNo of Passes:%d", passes);
    printf("\nSize in Bytes:%d", get_ctr());
    return 0;
}

yyerror (char *s) {
    fprintf(stderr, "\nWhoops! something went wrong!\t%d:%s\n", yylineno, s);
}
