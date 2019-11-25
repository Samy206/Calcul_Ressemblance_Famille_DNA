								#ifndef DEF_COMBI
								#define DEF_COMBI


								struct combinaisons
								{
									char **tab ;
									int taille ;
								 };
								 typedef struct combinaisons COMB ;
	
								COMB put_dash( char * seq );
								
								COMB append ( COMB result , COMB x);
								
								 COMB put_double_dash( char *seq );
								 
								 #endif
