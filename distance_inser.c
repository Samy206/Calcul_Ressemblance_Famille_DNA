#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									
									
									
									int get_taille_seq(char *argv)
									{
										int t = 0 ;
										FILE *F ;
										F = fopen(argv,"r");
										if(F == NULL)
										{
											printf("Problème d'ouverture fichier %s\n",argv);
											exit(1);
										}
										while(fgetc(F) != EOF)
										{
											t++;
										}
										rewind(F);
										fclose(F);
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
										fscanf(F,"%s",s); 			 //enregistrement de la séquence
										fclose(F);
										return s;
									}
									
									SEQUENCE initialiser_sequence ( char * argv1)
									{
										SEQUENCE A ;
										A.taille = get_taille_seq(argv1) ;										
										A.s = lire_fichier(argv1);
										return A ;
									}
									
									
									
									void initialiser_tab_seq (SEQUENCE D[] , char ** argv)
									{
										
										for(int i = 1 ; i <21 ; i++)
										{
											D[i] = initialiser_sequence(argv[i]);
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
													 if(A.s[i] != B.s[i] )
													 {			
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
												 while(i < difference )
												 {
													 distance = distance + 1.5 ; // partie où il n'y a plus de carac dans B 
													 i++;
												 }
										}
										 
										 if(A.taille < B.taille)  //la première séquence est plus courte que la deuxième
										{
											int difference1 ;
											difference1 = B.taille - A.taille ;
											while( i < (A.taille) )
											{
											    if(B.s[i] != A.s[i] )
												{
																				//si les caractères sont les mêmes on ne fait rien 
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
													}
														 
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
															distance = distance + 2.0 ;
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
													    else if(A.s[i] == 'G')
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
												 while(i < difference1 )
												 {
													 distance = distance + 1.5 ; // partie où il n'y a plus de carac dans A 
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
										}
											 // pas de partie où il n'y a pas de caractères en face de '-'										
										return distance ;
									}
									
									float distance_sequence_avec_insertions( LISTE *l , SEQUENCE A , SEQUENCE B , int indiceg , int indiced , char *argv)
									{
										int cmp , cmpt , cmptt;
										cmptt = 2 ;
										float distance = distance_sequence_sans_insertions(A,B); 
										float distance_min = 0.0 ;
										int difference ;
										int taillemax ;
										SEQUENCE C ;
										
										if( A.taille == B.taille )
										{
											push_liste(l,distance,indiceg,indiced);
											return distance ;
										}
										
										if(A.taille > B.taille)
										{
											C.s = malloc(A.taille);
											taillemax = A.taille;
											copie_string(C.s,B.s,B.taille);
											difference = A.taille - B.taille ;
											C.taille = taillemax ;
											
											if(difference == 1 )
											{	
												C.s[taillemax-1] = '-' ;
												for(int i = (taillemax-1); i>=0 ; i--)
												{
													distance_min = distance_sequence_sans_insertions(A,C);
													if(distance_min < distance )
													{
														distance = distance_min ;
														ajouter_seq_fichier(A.s,C.s,indiceg,indiced,argv,distance);
														push_liste(l,distance,indiceg,indiced);
													}
													C.s[i] = C.s[i-1] ;
													C.s[i-1] = '-' ;
												}
											}
											
											else if(difference ==2)
											{
												C.s[taillemax-1] = '-' ;
												cmpt = taillemax - 1 ;
												C.s[taillemax-2] = '-' ;
												cmp = taillemax - 2 ;
												distance_min = distance_sequence_sans_insertions(A,C);
												if(distance_min < distance )
												{
													distance = distance_min ;
													ajouter_seq_fichier(A.s,C.s,indiceg,indiced,argv,distance);
													push_liste(l,distance,indiceg,indiced);
												}
												
												for(int i = (C.taille-1) ; i > 0 ; i--)
												{
													for( int j = (C.taille-cmptt) ; j>= 0 ; j--)
													{
														C.s[j] = C.s[j-1] ;
														C.s[j-1] = '-' ;
														cmp-- ;
														distance_min = distance_sequence_sans_insertions(A,C);
														if(distance_min < distance )
														{
															distance = distance_min ;
															ajouter_seq_fichier(A.s,C.s,indiceg,indiced,argv,distance);
															push_liste(l,distance,indiceg,indiced);
														}
													}
													C.s[i] = C.s[i-1] ;
													C.s[i-1] = '-' ;
													cmpt-- ;
													cmptt++;
													cmp = 0 ;
													while(cmp != (cmpt-1))
													{
														C.s[cmp] = C.s[cmp+1];
														C.s[cmp+1] = '-' ;
														cmp++;
													}
												}
											}
										}
																			
										if(A.taille < B.taille)
										{
											taillemax = B.taille ;
											C.s = malloc(taillemax);
											copie_string(C.s , A.s,A.taille);
											difference = B.taille - A.taille;
											C.taille = taillemax ;
											
											if(difference == 1 )
											{
												C.s[taillemax-1] = '-' ;
												for(int i = (taillemax-1); i>=0 ; i--)
												{
													distance_min = distance_sequence_sans_insertions(C,B);
													if(distance_min < distance )
													{
														distance = distance_min ;
														ajouter_seq_fichier(C.s,B.s,indiceg,indiced,argv,distance);
														push_liste(l,distance,indiceg,indiced);
													}
													C.s[i] = C.s[i-1] ;
													C.s[i-1] = '-' ;
												}
											}
											if(difference ==2)
											{
												C.s[taillemax-1] = '-' ;
												cmpt = taillemax -1 ;
												C.s[taillemax-2] = '-' ;
												cmp = taillemax -2 ;
												distance_min = distance_sequence_sans_insertions(C,B);
												if(distance_min < distance )
												{
													//printf("A < B : 2 \n");
													distance = distance_min ;
													ajouter_seq_fichier(C.s,B.s,indiceg,indiced,argv,distance);
													push_liste(l,distance,indiceg,indiced);

												}
												for(int i = (C.taille-1) ; i > 0 ; i--)
												{
													for( int j = (C.taille-cmptt) ; j>= 0 ; j--)
													{
														C.s[j] = C.s[j-1] ;
														C.s[j-1] = '-' ;
														cmp-- ;
					
														distance_min = distance_sequence_sans_insertions(C,B);
														if(distance_min < distance )
														{
															distance = distance_min ;
															ajouter_seq_fichier(C.s,B.s,indiceg,indiced,argv,distance);
															push_liste(l,distance,indiceg,indiced);
															printf("A < B : 2 \n");
															
														}
													}
													C.s[i] = C.s[i-1] ;
													C.s[i-1] = '-' ;
													cmpt-- ;
													cmptt++;
													cmp = 0 ;
													
													while(cmp != (cmpt-1))
													{
														C.s[cmp]= C.s[cmp+1];
														C.s[cmp+1] = '-' ;
														cmp++;
													}
													printf("A < B : 2 \n");
												}
											}
										}	
										
										//liberer_seq(&C);
										return distance ;
									}
