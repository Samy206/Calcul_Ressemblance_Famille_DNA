								#ifndef DEF_SEQUENCE
								#define DEF_SEQUENCE
								
								struct sequence
								{
									int taille ; //taille sequence
									char *s ; //chaîne de caractères
								};
								
								typedef struct sequence SEQUENCE;
								
								SEQUENCE * lire_fichier( char *argv);								
								
								SEQUENCE * initialiser_sequence(char *argv1 );
								
								float distance_sequence_sans_insertions( SEQUENCE * A, SEQUENCE * B);
								
								float distance_sequence_avec_insertions( SEQUENCE * A, SEQUENCE * B);
								
								#endif
