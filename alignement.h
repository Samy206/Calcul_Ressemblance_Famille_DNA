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

					typedef struct indices
					{
						int indiceG;
						int indiceD;
					}INDICES;
					
					void align (CHAINES *S , int i , int j , float **T);
					
					void liberer_chaine(CHAINES S);
					
					char* prepend(char* s, const char t);

					void ecrire_seq_alignee(char ** Tab_seq,char *fileName,int nb);

					void creer_familles(char **argv,FAMILLE *f,SEQUENCE *D);
					
					CHAINES initialiser_chaines(char *a , char*b);

					int freq_max_duplicate(int Freq[], int max);
					
					float ** init_matrice_dyn(int n);

					float **copyTab(float ** source);

					void init_and_call_align (char *chaine1,
 												char *chaine2,
 												int taille1,
 												int taille2, 
 												float **matrice,
 												int Tab_marqueur [],
 												char **Tab_seq,
												int indiceDistg,
 												int indiceDistd
											 );

					ALIGNEMENT creer_alignement ( int nb );
					
					void align_two(char **Tab_seq , FAMILLE f,int Tab_marqueur[]);
					
					void aligne_famille(char **Tab_seq , FAMILLE f, int Tab_marqueur[]);

					char freq_majoritaire(int T[], int nb_seq);

					char * creer_seq_consensus (char **Tab_seq , int nb_seq);

					int max_tab(int Freq[]);

					void ecrire_seq_consensus_fichier(char *consensus , char *argv);

					#endif
