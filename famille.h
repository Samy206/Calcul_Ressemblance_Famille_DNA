							#ifndef DEF_FAMILLE
							#define DEF_FAMILLE
							
							struct famille
							{
								LISTE *l ; //liste d'éléments qui sont proches
							};
							typedef struct famille FAMILLE;
							
							float recherche_distance_min(LISTE *l);
							
							LISTE * creer_liste_initiale(SEQUENCE D[], char **argv);
							
							int get_num_freq_max(float distance ,char **argv);
							
							int get_num_autre(int *T , int numero , float distance , char **argv);		
							

											
							
							
							#endif
