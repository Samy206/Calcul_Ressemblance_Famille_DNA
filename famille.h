							#ifndef DEF_FAMILLE
							#define DEF_FAMILLE
							
							
								
							struct famille
							{
								int n ;
								SEQUENCE * table;
							};
							typedef struct famille FAMILLE;
							
							char * famille_fileName(int i);
							 
							FAMILLE creer_famille_initiale(int nb);
							
							void remplir_famille(FAMILLE f , int T[] ,SEQUENCE D[]);
							
							void ecrire_fich_fam(FAMILLE f  , int T[] , char *argv);
							
							float recherche_distance_min(LISTE *l);
							
							LISTE * creer_liste_initiale(SEQUENCE D[] , char * listSeq, char* distSequence);
							
							int get_num_freq_max( float distance , LISTE *l);
							
							int get_num_autre(int *T , float distance , int numero , LISTE *l);
													
							#endif
