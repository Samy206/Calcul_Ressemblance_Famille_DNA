									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
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
										if(t == 17 )
										{
											s = malloc(t+2);
										}
										if(t == 18 )
										{
											s = malloc(t+1);
										}
										else if(t == 19 )
										{
											s = malloc(t);
										}
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
										for(int i = 0 ; i <20 ; i++)
										{
											D[i] = initialiser_sequence(argv[i+1]);
										}
									}
									
									
									float distance_sequence_sans_insertions( SEQUENCE  * A, SEQUENCE * B)
									{
										float distance = 0.0 ;
										int i = 0;
										
										if(A->taille > B->taille)  //la première séquence est plus longue que la deuxième
										{
											 while( i < (B->taille))
											 {
												 if(A->s[i] != B->s[i] )
												 {			
													 if(A->s[i] == 'A')
													 {
														 if(B->s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'G')
															distance = distance + 1.0 ;
														 else if(B->s[i] == 'T')
															distance = distance + 2.0 ;
														 else if(B->s[i] == '-')
															distance = distance + 1.5 ;
													 }
														 
													 if(A->s[i] == 'C')
													 {
														 if(B->s[i] == 'A')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'G')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'T')
															distance = distance + 1.0 ;
														 else if(B->s[i] == '-')
															distance = distance + 1.5 ;
													 }
														 
													 if(A->s[i] == 'G')
													 {
														 if(B->s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'A')
															distance = distance + 1.0 ;
														 else if(B->s[i] == 'T')
															distance = distance + 2.0 ;
														 else if(B->s[i] == '-')
															distance = distance + 1.5 ;
													}
														 
													if(A->s[i] == 'T')
													{
													   if(B->s[i] == 'C')
															distance = distance + 1.0 ;
													   else if(B->s[i] == 'G')
															distance = distance + 1.0 ;
													   else if(B->s[i] == 'A')
															distance = distance + 2.0 ;
													   else if(A->s[i] == '-')
															distance = distance + 1.5 ;
													}
													
													if(A->s[i] == '-')
													{
													   if(B->s[i] == 'C')
															distance = distance + 1.5 ;
													   else if(B->s[i] == 'G')
															distance = distance + 1.5 ;
													   else if(B->s[i] == 'A')
															distance = distance + 1.5 ;
													   else if(B->s[i] == 'T')
														   distance = distance + 1.5 ;
													}
												 
												}
												i++;
											}
													 
											 while(i < (A->taille) )
											 {
												 distance = distance + 1.5 ; // partie où il n'y a plus de carac dans B 
												 i++;
											 }
										}
										 
										 if(A->taille < B->taille)  //la première séquence est plus courte que la deuxième
										{
											 while( i <= (A->taille))
											 {
												 if(B->s[i] != A->s[i] ){
																			//si les caractères sont les mêmes on ne fait rien 
													
												 if(B->s[i] == 'A')
												 {
														if(A->s[i] == 'C')
															distance = distance + 2.0 ;
														else if(A->s[i] == 'G')
															distance = distance + 1.0 ;
														else if(A->s[i] == 'T')
															distance = distance + 2.0 ;
														else if(A->s[i] == '-')
															distance = distance + 1.5 ;
												 }
												 
												 if(B->s[i] == 'C')
												 {
														if(A->s[i] == 'A')
															distance = distance + 2.0 ;
														else if(A->s[i] == 'G')
															distance = distance + 2.0 ;
														else if(A->s[i] == 'T')
															distance = distance + 1.0 ;
														else if(A->s[i] == '-')
															distance = distance + 1.5 ;
												 }
												 
												 if(B->s[i] == 'G')
												 {
														if(A->s[i] == 'C')
															distance = distance + 2.0 ;
														else if(A->s[i] == 'A')
															distance = distance + 1.0 ;
														else if(A->s[i] == 'T')
															distance = distance + 2.0 ;
														else if(A->s[i] == '-')
															distance = distance + 1.5 ;
												 }
												 
												 if(B->s[i] == 'T')
												 {
														if(A->s[i] == 'C')
															distance = distance + 1.0 ;
														else if(A->s[i] == 'G')
															distance = distance + 1.0 ;
														else if(A->s[i] == 'A')
															distance = distance + 2.0 ;
														else if(A->s[i] == '-')
															distance = distance + 1.5 ;
														
												 }
												 
												 if(B->s[i] == '-')
													{
													   if(A->s[i] == 'C')
															distance = distance + 1.5 ;
													   else if(A->s[i] == 'G')
															distance = distance + 1.5 ;
													   else if(A->s[i] == 'A')
															distance = distance + 1.5 ;
													   else if(A->s[i] == 'T')
														   distance = distance + 1.5 ;
													}
												 
											 }
												 i++;
											 }
											 
											 while(i < (B->taille) )
											 {
												 distance = distance + 1.5 ; // partie où il n'y a plus de carac dans A 
												 i++;
											 }
										 }
										
										if(A->taille == B->taille)  //la première séquence a la même taille que la deuxième
										{
											 while( i < (B->taille))
											 {
												 if(A->s[i] != B->s[i] )
												 {
														
													 if(A->s[i] == 'A')
													 {
														 if(B->s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'G')
															distance = distance + 1.0 ;
														 else if(B->s[i] == 'T')
															distance = distance + 2.0 ;
														 else if(B->s[i] == '-')
															distance = distance + 1.5 ;
													 }
													 
													 if(A->s[i] == 'C')
													 {
														 if(B->s[i] == 'A')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'G')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'T')
															distance = distance + 1.0 ;
														 else if(B->s[i] == '-')
															distance = distance + 1.5 ;
													 }
													 
													 if(A->s[i] == 'G')
													 {
														 if(B->s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B->s[i] == 'A')
															distance = distance + 1.0 ;
														 else if(B->s[i] == 'T')
															distance = distance + 2.0 ;
														 else if(B->s[i] == '-')
															distance = distance + 1.5 ;
													 }
													 
													 if(A->s[i] == 'T')
													 {
														 if(B->s[i] == 'C')
															distance = distance + 1.0 ;
														 else if(B->s[i] == 'G')
															distance = distance + 1.0 ;
														 else if(B->s[i] == 'A')
															distance = distance + 2.0 ;
														 else if(A->s[i] == '-')
															distance = distance + 1.5 ;
													 }
													 
													 if(A->s[i] == '-')
													{
													   if(B->s[i] == 'C')
															distance = distance + 1.5 ;
													   else if(B->s[i] == 'G')
															distance = distance + 1.5 ;
													   else if(B->s[i] == 'A')
															distance = distance + 1.5 ;
													   else if(B->s[i] == 'T')
														   distance = distance + 1.5 ;
													}
												 }
														 
													 i++;
											 }
											 // pas de partie où il n'y a pas de caractères en face de '-'
										 }
										
										return distance ;
									}
									
									
									float distance_sequence_avec_insertions(SEQUENCE * A , SEQUENCE * B )
									{
										int cmp , cmpt ;
										float distance = distance_sequence_sans_insertions(A,B); 
										float distance_min = 0.0 ;
										char *s ;
										int difference ;
										
										if((A->taille) > (B->taille))
										{
											difference = A->taille - B->taille ;
											if(difference == 1 )
											{
												s = malloc(sizeof(A->taille+1));
											}
											else
											{
												s = malloc(sizeof(A->taille+2));
											}
										}
										if((A->taille) < (B->taille))
										{
											difference = B->taille - A->taille ;
											if(difference == 1 )
											{
												s = malloc(sizeof(A->taille+1));
											}
											else
											{
												s = malloc(sizeof(A->taille+2));
											}
										}
										
										if(A->taille == B->taille)
										{
											distance = distance ;
										}
										
										printf("difference : %d \n",difference);
										if(A->taille > B->taille)
										{
											if(difference == 1)
											{
												(B->taille++);
												B->s[B->taille] = '-' ;
												distance_min = distance_sequence_sans_insertions(A,B);
												if(distance_min < distance )
												{
													distance = distance_min ;
													s = B->s ;
												}
												for(int j = B->taille ; j>0 ; j--)
												{
													B->s[j] = B->s[j-1] ;
													B->s[j-1] = '-' ;
													distance_min = distance_sequence_sans_insertions(A,B);
													if(distance_min < distance )
													{
														distance = distance_min ;
														s = B->s ;
													}
												}
												B->s = s ;
											}
											
											if(difference == 2)
											{
												(B->taille++);
												 B->s[B->taille] = '-' ;
											    (B->taille++);
											     cmp = B->taille ;
												 B->s[B->taille] = '-' ;
												 cmpt = B->taille;
												 s = B->s ;
												for(int i = B->taille ; i > 0 ; i--)
												{
													distance_min = distance_sequence_sans_insertions(A,B);
													if(distance_min < distance )
													{
														distance = distance_min ;
														s = B->s ;
													}
													
													for(int j = (B->taille-1) ; j>0 ; j--)
													{
														B->s[j] = B->s[j-1] ;
														B->s[j-1] = '-' ;
														cmp-- ;
														distance_min = distance_sequence_sans_insertions(A,B);
														if(distance_min < distance )
														{
															distance = distance_min ;
															s = B->s ;
														}
													}
													
													(cmpt--);
													B->s[B->taille] = B->s[cmpt];
													B->s[cmpt] = '-' ;
													while(cmp != (cmpt-1))
													{
														B->s[cmp] = B->s[cmp+1] ;
														B->s[cmp+1] = '-' ;
														cmp++;
													}
												}
													
												B->s = s ;
											}
										}						
											
										if(A->taille < B->taille)
										{
											if(difference == 1)
											{
												(A->taille++);
												A->s[A->taille] = '-' ;
												distance_min = distance_sequence_sans_insertions(A,B);
												if(distance_min < distance )
												{
													distance = distance_min ;
													s = A->s ;
												}
												
												for(int j = A->taille ; j>0 ; j--)
												{
													A->s[j] = A->s[j-1] ;
													A->s[j-1] = '-' ;
													distance_min = distance_sequence_sans_insertions(A,B);
													if(distance_min < distance )
													{
														distance = distance_min ;
														s = A->s ;
													}
												}
												printf("orange \n");
												A->s = s ;
											}
											
											if(difference == 2)
											{
												A->s[18] = '-' ;
												
												cmp =18;
												printf(" dernier carac %c \n",A->s[cmp]);
												A->s[19] = '-' ;
												cmpt =19;
												A = A->s ;
												for(int i = 18 ; i > 0 ; i--)
												{
													distance_min = distance_sequence_sans_insertions(A,B);
													if(distance_min < distance )
													{
														distance = distance_min ;
														printf("orange \n");
														s = A->s ;
													}
													for(int j = (A->taille-1) ; j>0 ; j--)
													{
														A->s[j] = A->s[j-1] ;
														A->s[j-1] = '-' ;
														cmp-- ;
														distance_min = distance_sequence_sans_insertions(A,B);
														if(distance_min < distance )
														{
															distance = distance_min ;
															s = A->s ;
														}
													}
													
													(cmpt--);
													A->s[cmpt+1] = A->s[cmpt];
													A->s[cmpt] = '-' ;
													while(cmp != (cmpt-1))
													{
														A->s[cmp] = A->s[cmp+1] ;
														A->s[cmp+1] = '-' ;
														cmp++;
													}
												}
													
												A->s = s ;
											}
										}
										return distance ;
									}
									
									void liberer_seq(SEQUENCE * A)
									{
										free(A->s);
										free(A);
									}
							
						
