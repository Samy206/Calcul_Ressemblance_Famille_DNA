							#ifndef DEF_DISTANCE
							#define DEF_DISTANCE
							
							struct distances
							{
								float val ; //val de la distance
								int indiceg ; // numéro de la première sequence
								int indiced ; // numéro de la deuxième sequence 
								struct distances *suiv ; //pointeur vers le suivant 
							};
							typedef struct distances DISTANCE ;
							
							struct liste 
							{
								int nombre ; 
								DISTANCE * premier ;
							};
							typedef struct liste LISTE ;
							
							
							LISTE * initialiser_liste();			
							
							int get_indice(char *argv);
							
							void push_liste(LISTE *l , float distance , int a , int b);
							
							void afficher_liste(LISTE *l);
							
							#endif
							
							
								
								
