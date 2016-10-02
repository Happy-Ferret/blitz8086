
main(int argc,char *argv[]) {
	if (argc>1)	{
		yyin = fopen(argv[1],"r");
		if (argc > 2)
			cg_set(argv[2]);
	} else {
		yyin=fopen("input.txt","r");
        if (yyin == NULL) {
            fprintf(stderr, "could not open input.txt: %s\n", strerror(errno));
            return 1;
        }
		cg_start();
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
    printf("\nNo of Passes:%d",passes);
    printf("\nSize in Bytes:%d",get_ctr());

}

yyerror (char *s) {
    fprintf(stderr, "\nWhoops! something went wrong!\t%d:%s\n", yylineno, s);
}
