									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "combi.h"
									
									
									
									int get_taille_seq(char *argv)
									{
										int t = 0 ;
										FILE *F ;
										F = fopen(argv,"r");										//On ouvre le ficher nommé argv
										if(F == NULL)
										{
											printf("Problème d'ouverture fichier %s\n",argv);   
											exit(1);
										}
										while(fgetc(F) != EOF)                         
										{
											t++;                              //On compte le nombre de caractères
										}
										rewind(F);							//On remet le curseur au début 
										fclose(F);							//On ferme le fichier
										return t ;
									}
									
									char * lire_fichier(char *argv)
									{
										FILE *F ;
										F = fopen(argv,"r");						
										if(F == NULL)
										{
											printf("Problème d'ouverture fichier %s\n",argv);
											exit(1);
										}
										int t = get_taille_seq(argv);
										char *s ;
										s = malloc(t);
										fscanf(F,"%s",s); 			 //enregistrement de la séquence dans s
										fclose(F);
										return s;
									}
									
									SEQUENCE initialiser_sequence ( char * argv1)
									{
										SEQUENCE A ;
										A.taille = get_taille_seq(argv1) ;		//On définit la taille de la séquence								
										A.s = lire_fichier(argv1);				//On copie la chaîne de caractères dans la séquence
										return A ;
									}
									
																		
									void initialiser_tab_seq (SEQUENCE D[] , char ** argv)
									{
										
										for(int i = 1 ; i <21 ; i++)
										{
											D[i] = initialiser_sequence(argv[i]);    //On stocke les 20 séquences dans un tableau
										}
									}
									
								
									float distance_sequence_sans_insertions( SEQUENCE A, SEQUENCE B)
									{
										float distance = 0.0 ;
										int i = 0 ;
										
										if(A.taille > B.taille)  //la première séquence est plus longue que la deuxième
										{
											int difference ;
											difference = A.taille - B.taille ;
											
											 while( i < (B.taille) )
											 {
													//Comparaison caractères par caractères dans la séquence la plus courte
													
													 if(A.s[i] != B.s[i] )
													 {			
														 //si les caractères sont les mêmes on ne fait rien 
														 
														 if(A.s[i] == 'A')
														 {
															 if(B.s[i] == 'C')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'G')
																distance = distance + 1.0 ;
															 else if(B.s[i] == 'T')
																distance = distance + 2.0 ;
															 else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														 }
															 
														 else if(A.s[i] == 'C')
														 {
															 if(B.s[i] == 'A')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'G')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'T')
																distance = distance + 1.0 ;
															 else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														 }
															 
														else  if(A.s[i] == 'G')
														 {
															 if(B.s[i] == 'C')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'A')
																distance = distance + 1.0 ;
															 else if(B.s[i] == 'T')
																distance = distance + 2.0 ;
															 else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														}
															 
														else if(A.s[i] == 'T')
														{
														   if(B.s[i] == 'C')
																distance = distance + 1.0 ;
														   else if(B.s[i] == 'G')
																distance = distance + 2.0 ;
														   else if(B.s[i] == 'A')
																distance = distance + 2.0 ;
														   else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														}
														
														else if(A.s[i] == '-')
														{
														   if(B.s[i] == 'C')
																distance = distance + 1.5 ;
														   else if(B.s[i] == 'G')
																distance = distance + 1.5 ;
														   else if(B.s[i] == 'A')
																distance = distance + 1.5 ;
														   else if(B.s[i] == 'T')
															   distance = distance + 1.5 ;
														}
														i++ ;
													}
													else 
														i++;
												}
												 i =0 ; 
												 
												 // partie où il n'y a plus de carac dans B.s :  
												 
												 while(i < difference )
												 {
													 distance = distance + 1.5 ; 
													 i++;
												 }
										}
										 
										 if(A.taille < B.taille)  //la première séquence est plus courte que la deuxième
										{
											int difference1 ;
											difference1 = B.taille - A.taille ;
											while( i < (A.taille) )
											{
												
												//si les caractères sont les mêmes on ne fait rien
												
												
											    if(B.s[i] != A.s[i] )
												{
																								 
													if(B.s[i] == 'A')
												    {
														if(A.s[i] == 'C')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'G')
															distance = distance + 1.0 ;
														else if(A.s[i] == 'T')
															distance = distance + 2.0 ;
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													}											// on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
														 
													else if(B.s[i] == 'C')
													{
														if(A.s[i] == 'A')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'G')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'T')
															distance = distance + 1.0 ;
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													 }
														 
													 else if(B.s[i] == 'G')
													 {
														if(A.s[i] == 'C')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'A')
															distance = distance + 1.0 ;
														else if(A.s[i] == 'T')
															distance = distance + 2.0 ;		// on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													}
														 
													else if(B.s[i] == 'T')
													{
														if(A.s[i] == 'C')
															distance = distance + 1.0 ;
														else if(A.s[i] == 'G')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'A')
															distance = distance + 2.0 ;
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;		
													 }
														 
													 else if(B.s[i] == '-')
													{
														 if(A.s[i] == 'C')
															distance = distance + 1.5 ;
													    else if(A.s[i] == 'G')					// on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
															distance = distance + 1.5 ;
														 else if(A.s[i] == 'A')
															distance = distance + 1.5 ;
														 else if(A.s[i] == 'T')
														   distance = distance + 1.5 ;
													}
													i++;
												}
												else 
													i++;
											} 
												 i = 0 ;
												 
												  // partie où il n'y a plus de carac dans A.s :
												 
												 while(i < difference1 )
												 {
													 distance = distance + 1.5 ;
													 i++;
												 }
											 
										 }
										
										if(A.taille == B.taille)  //la première séquence a la même taille que la deuxième
										{
											 while( i < (B.taille))
											{
												if(A.s[i] != B.s[i] )
												{	
													if(A.s[i] == 'A')
													{
														 if(B.s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'G')
															distance = distance + 1.0 ;
														 else if(B.s[i] == 'T')                // on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
															distance = distance + 2.0 ;
														 else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }
														 
													 else if(A.s[i] == 'C')
													 {
														 if(B.s[i] == 'A')
															distance = distance + 2.0 ;															
														 else if(B.s[i] == 'G')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'T')
															distance = distance + 1.0 ;
														 else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }
														 
												
													 else if(A.s[i] == 'G')
													 {
														 if(B.s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'A')
															distance = distance + 1.0 ;
														 else if(B.s[i] == 'T')
															distance = distance + 2.0 ;
														else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }
														 
													else if(A.s[i] == 'T')
													 {
														 if(B.s[i] == 'C')
															distance = distance + 1.0 ;
														 else if(B.s[i] == 'G')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'A')
															distance = distance + 2.0 ;
														 else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }
			
													 else if(A.s[i] == '-')
													 {
														if(B.s[i] == 'C')
															distance = distance + 1.5 ;
														 else if(B.s[i] == 'G')
															distance = distance + 1.5 ;
														 else if(B.s[i] == 'A')
															distance = distance + 1.5 ;
														 else if(B.s[i] == 'T')
															distance = distance + 1.5 ;
													}		 
													i++ ;
												}
												
												else
													i++;
											}
											// pas de partie où il n'y a pas de caractères en face de '-'	
										}
										
										
																			
										return distance ;
									}
									
									
									
									float distance_combinaisons(LISTE *l ,SEQUENCE A , SEQUENCE B , float distance  , int indiceg , int indiced ,char *argv)
									{
										int diff ;
										diff = A.taille - B.taille ;       //difference de taille entre deux séquences
										float distance_min ;
										
										if(diff == 1)
										{
											COMB com = put_dash(B.s);    //on ajoute un seul tiret
											SEQUENCE C , D  ;           //C est la séquence qui va récupérer les modifications de la séquence B (B.s)
											for(int i = 0 ; i<com.taille ; i++)
											{
												C.taille = strlen(com.tab[i]) ;   //comb.tab est l'ensemble des combinaisons possibles
												C.s = com.tab[i] ;
													
												distance_min = distance_sequence_sans_insertions(A,C);
												if(distance_min <= distance )
												{
													D.s = C.s;                    
													D.taille = C.taille ;          //On enregsitre les modif. de la séquence C dans la séquence D
													distance = distance_min ;
												}
											}
											
											ajouter_seq_fichier(A.s,D.s,indiceg,indiced,argv,distance);    
																							//On enregsitre la séquence D et on écrit dans le ficher liste_seq_modif la seq A et D avec leur distance minimale	
											push_liste(l,distance,indiceg,indiced);			//On les met aussi dans une liste
										}
										
										else if ( diff == 2)
										{
											COMB com = put_double_dash(B.s);		//On met deux blancs 
											SEQUENCE C , D  ;
											for(int i = 0 ; i<com.taille ; i++)        
											{
												C.taille = strlen(com.tab[i]) ;    
												C.s = com.tab[i] ;						// ici la séquence C prend toutes les combinaisons possibles avec deux blancs
												distance_min = distance_sequence_sans_insertions(A,C);  //On calcule la taille sans insertions ( vu qu'elles sont déjà en place)
												if(distance_min <= distance )
												{
													D.s = C.s;
													D.taille = C.taille ;
													distance = distance_min ;
												}
											}
											
											ajouter_seq_fichier(A.s,D.s,indiceg,indiced,argv,distance);
											push_liste(l,distance,indiceg,indiced); 							//on ajoute les distances dans un fichier ( liste_seq_modif) et on les met dans une liste 
										}
										return distance ;
									}
																					
									/*float distance_sequence_avec_insertions(LISTE *l ,SEQUENCE A , SEQUENCE B , int indiceg , int indiced , char *argv)
									{
										float distance = distance_sequence_sans_insertions(A,B); 

										
										if(A.taille == B.taille )
										{
											push_liste(l,distance,indiceg,indiced);        //Si les deux séquences ont la même taille on appelle la fonction qui calcule la distance sans ajout de tiret
											return distance;
										}
										
										else if(A.taille > B.taille )
										{
											return distance_combinaisons(l,A,B, distance , indiceg , indiced,argv);	  // la fonction précédente fait tout et on appelle avec la séquence la plus grande ( ici A)
										}
										else if (B.taille > A.taille)
										{
											return distance_combinaisons(l,B,A, distance , indiced , indiceg,argv);	// la fonction précédente fait tout et on appelle avec la séquence la plus grande ( ici B)
										}
										return ;
										
									}*/
									
									void afficher_tab(SEQUENCE D[])
									{
										for ( int i = 1 ; i < 21 ; i++)
										{
											printf("D[%2d] : %s , taille : %d\n",i,D[i].s,D[i].taille);  //on parcourt le tableau de séquences et on affiche la chaîne de carac. et la taille de chacune d'elles
										}
										printf("\n");
										printf("\n");
									}
																		
									void liberer_seq(SEQUENCE * A)
									{
										free(A->s);
										free(A);
									}
																		
									void ajouter_seq_fichier(char * s , char * v  , int indiceg , int indiced , char * argv , float val)
									{
										FILE *F = fopen(argv,"a");
										if(F == NULL)
										{																// on écrit dans le nom de fichier passé en argument
											printf("problème d'ouverture de fichier ecriture\n");
											exit(3);
										}
										
										fprintf(F,"La distance entre la sequence %d (%s) et %d (%s) est : %f \n ",indiceg,s,indiced,v,val);
										
										fclose(F);	
									}
									
									void clean_fichier(char *argv)
									{
										FILE *F = fopen(argv,"w");
										if(F == NULL)
										{
											printf("problème d'ouverture de fichier ecriture\n");  //Efface tout le contenu d'un fichier grâce au mode d'ouverture "w"
											exit(3);
										}
										
										fprintf(F,"\n");
									}
							
									void copie_string( char *a , char *b, int fin)
									{
										for(int i = 0 ; i < fin ; i++)
										{
											a[i] = b[i] ;              //similaire à strcpy() mais avec un arrêt à l'indice fin
										}
									}
									
									float compare_carac ( char a , char b)
									{
										if ( a == b)
										{
											return 0.0 ;
										}
										else
										{
											if( a == 'A')
											{
												if(b == 'T')
													return 2.0 ;
												else if( b == 'C')
													return 2.0 ;
												else if ( b == 'G')
													return 1.0 ;
												else 
													return 1.5 ;
											}
											
											
											else if( a == 'T')
											{
												if(b == 'A')
													return 2.0 ;
												else if( b == 'C')
													return 1.0 ;
												else if ( b == 'G')
													return 2.0 ;
												else 
													return 1.5 ;
											}
											
											
											else if( a == 'G')
											{
												if(b == 'A')
													return 1.0 ;
												else if( b == 'C')
													return 2.0 ;
												else if ( b == 'T')
													return 2.0 ;
												else 
													return 1.5 ;
											}
											
											else if( a == 'C')
											{
												if(b == 'A')
													return 2.0 ;
												else if( b == 'G')
													return 2.0 ;
												else if ( b == 'T')
													return 1.0 ;
												else 
													return 1.5 ;
											}
											
											else
												return 1.5 ;
										}
									}
												
									float min ( float a , float b, float c)
									{
										if ( a < b )
										{
											if ( a < c )
												return a ;
											else 
												return c ;
										}
										else
										{
											if(b < c) 
												return b ;
											else 
												return c ;
										}
										return b ;
									}		
									
									
									void remplir_tab(float **tab ,int ligne , int colonne)
									{
										for(int i = 0 ; i < ligne ; i++)
										{
											for(int j = 0 ; j < colonne ; j++)
											{
												tab[i][j] = -(1.0) ;
											}
										}
									}
									
									float distance_dyn ( char *a , char *b , int i , int j ,float distance , float **T)
									{
										float d1,d2,d3,m;
											if(i == 0)
												return ( distance + 1.5* j );
												
											else if ( j == 0 )
												return ( distance + i * 1.5 );
												
											else if ( T[i][j] != (-1.0) )
												return T[i][j] ;
												
												d1 = distance_dyn(a,b,i-1,j-1,distance,T)+compare_carac(a[i],b[i]) ;
												d2 = distance_dyn(a,b,i,j-1,distance,T)+compare_carac(a[i],'-') ;
												d3 = distance_dyn(a,b,i-1,j,distance,T)+compare_carac('-',b[j]) ;
												//printf(" a[%d] : %c , b[%d] : %c , distance d1 : %f , distance d2 : %f , distance d3 : %f , distance : %f  \n",i,a[i],j,b[j],d1,d2,d3,distance);
												
												m = min(d1,d2,d3);
												T[i][j] = m ;
												
												return T[i][j] ;
											
									}		
										
								
									char * effacer_dernier ( char * a , int length)
									{
										char *s = malloc(length -1 );
										for(int i = 0 ; i < length -2 ; i++)
										{
											s[i] = a[i] ;
										}
										return s ;
									}
								
	
