								#ifndef DEF_SEQUENCE
								#define DEF_SEQUENCE
								
								#include "distance.h"
								
								struct sequence
								{
									int taille ; //taille sequence
									char *s ; //chaîne de caractères
								};
								typedef struct sequence SEQUENCE;
								
								int get_taille_seq(char *argv);
								
								char * lire_fichier( char *argv);								
								
								SEQUENCE  initialiser_sequence(char *argv1 );
								
								void initialiser_tab_seq (SEQUENCE D[] , char ** argv);
								
								float distance_sequence_sans_insertions( SEQUENCE  A, SEQUENCE B);
								
								float compare_carac(char s , char c);
								
								void afficher_tab(SEQUENCE D[]);
								
								void liberer_seq(SEQUENCE * A);
								
								void ajouter_seq_fichier(char * s , char * v  , int indiceg , int indiced , char * argv , float val);
								
								float min ( float a , float b);
								
								void remplir_tab(float **tab ,int ligne , int colonne);
								
								float distance_dyn (char *a , char *b , int i , int j, float **T);
								
								float compare_carac(char s , char c);
								
								
								#endif
