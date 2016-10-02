
main(int argc,char *argv[]) {

	if(argc>1)	{
		yyin=fopen(argv[1],"r");
		if (argc>2)
			cg_set(argv[2]);
	}
	else {
		yyin=fopen("input.txt","r");
		cg_start();
		}
	//yyout=fopen("tempdump","w");
	int passes =0;
	init_dict();

	reset_unres();
	do {
	reset_byte();
	fseek(yyin,0,0);
	yyparse();passes++;} while (chk_unres());
	printf("\nNo of Passes:%d",passes);
	printf("\nSize in Bytes:%d",get_ctr());

}

yyerror (char *s) {
printf("\nWhoops! something went wrong!\t%d:%s\n",yylineno,s);

}
