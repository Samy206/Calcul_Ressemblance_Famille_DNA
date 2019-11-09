								#ifndef DEF_SEQUENCE
								#define DEF_SEQUENCE
								
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
								
								float distance_sequence_sans_insertions( SEQUENCE * A, SEQUENCE * B);
								
								float distance_sequence_avec_insertions( SEQUENCE * A, SEQUENCE * B);
								
								void liberer_seq(SEQUENCE * A);
								
								#endif
