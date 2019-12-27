					#ifndef DEF_ALIGNEMENT
					#define DEF_ALIGNEMENT
					#include "famille.h"
					
					typedef struct alignement
					{
						int nb ; //nombre de séquences à aligner 
						char *s ; // sequence consensus
					}ALIGNEMENT;
					
					typedef struct chaines
					{
						char *a ; //première séquence avec laquelle on va calculer une distance 
						char *b ; //deuxième séquence avec laquelle on va calculer une distance
						char *anew ; //nouvelle distance a avec les blancs 
						char *bnew ; //nouvelle distance b avec les blancs
					}CHAINES;
					
					void align (CHAINES *S , int i , int j , float **T);
					
					void liberer_chaine(CHAINES S);
					
					char* prepend(char* s, const char t);

					void creer_familles(char **argv,FAMILLE *f,SEQUENCE *D);
					
					CHAINES initialiser_chaines(char *a , char*b);
					
					int verif_tab(int T[] , int n );
					
					ALIGNEMENT creer_alignement ( int nb );


					#endif
