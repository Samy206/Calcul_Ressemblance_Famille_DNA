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
							
							int liste_vide(LISTE *l);
							
							int est_vide(LISTE *l);
							
							void push_liste(LISTE *l , float val , int a , int b);
							
							void ecrire_fichier_liste_fin(LISTE *l , char * argv );
							
							void ajouter_fichier_fin(LISTE *l , char * argv );
							
							float pop_liste_place( LISTE *l , int place);
							
							void afficher_liste(LISTE *l);
							
							void liberer_liste(LISTE *l);
							
							int get_numero_distance(LISTE *l , int indiceg , int indiced);
							
							void supp_numero_seq(LISTE *l , int numero);
							
							#endif
							
							
								
								
