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
									
									char * lire_fichier(char *argv, int num)
									{
										FILE *F ;
										
										char seqNum[3] ;
										if (num >=10) {
											seqNum[0]= (num/10)+'0';
											seqNum[1]= (num%10)+'0';
											seqNum[2]= '\0';
										}
										else {
											seqNum[0]= '0';
											seqNum[1]= num+'0';
											seqNum[2]= '\0';
										}
										const int len = strlen(argv)+11;
										char *fileName = malloc(len);
										strcpy(fileName, argv);
										strcat(fileName, "/seq"),
										strcat(fileName,seqNum);
										strcat(fileName,".txt");
										F = fopen(fileName,"r");						
										if(F == NULL)
										{
											printf("Problème d'ouverture fichier %s\n",argv);
											exit(1);
										}
										int t = get_taille_seq(fileName);
										char *s ;
										s = malloc(t+1);
										fscanf(F,"%s",s); 			 //enregistrement de la séquence dans s
										fclose(F);
										s[t+1]='\0';
										return s;
									}
																		
									void initialiser_tab_seq (SEQUENCE D[] , char * argv)
									{
										
										for(int i = 1 ; i <21 ; i++)
										{
											SEQUENCE A ;
											A.s = lire_fichier(argv, i);
											A.taille = strlen(A.s);
											D[i] = A;    //On stocke les 20 séquences dans un tableau
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
									
									void afficher_tab(SEQUENCE D[])
									{
										for ( int i = 1 ; i < 21 ; i++)
										{
											printf("D[%2d] : %s , taille : %d\n",i,D[i].s,D[i].taille);  //on parcourt le tableau de séquences et on affiche la chaîne de carac. et la taille de chacune d'elles
										}
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
												
									float min ( float a , float b)
									{
										if ( a < b )
											return a ;
											
										else
											return b ;
											
					
									}		
									
									
									void remplir_tab(float **tab ,int ligne , int colonne)
									{
										for(int i = 0 ; i < ligne ; i++)
										{
											for(int j = 0 ; j < colonne ; j++)
											{

												tab[i][j] = -(1) ;
											}
										}
									}
									
									float distance_dyn (char *a , char *b , int i , int j , float **T)
									{
										float mini , temp;
										if (T[i][j] != -(1) ){
											return  T[i][j];
										}
										if(i == 0 && j > 0) 
										{
											mini = 1.5;
											for(int k = 0 ; k < j ; k++)
											{
												temp = compare_carac(a[0],b[k]);
												if(temp < mini)
												{
													mini = temp ;
												}
											}
											T[i][j] = 1.5 * (j-1) + mini ;
											return T[i][j];
										}

										if(j == 0 && i > 0) 
										{
											mini = 1.5;
											for(int k = 0 ; k < i ; k++)
											{
												temp = compare_carac(a[0],b[k]);
												if(temp < mini)
												{
													mini = temp ;
												}
											}
											T[i][j] = 1.5 * (i-1 ) + mini;
											return T[i][j];
										}
										if(j == 0 && i == 0) {
							
											T[i][j] = compare_carac(a[i],b[j]);
											return T[i][j];
										}
									
										float d1,d2,d3;
										d1 = distance_dyn(a,b,i-1,j-1,T) + compare_carac(a[i],b[j]) ;
										d2 = distance_dyn(a,b,i-1,j,T) + compare_carac(a[i],'-') ;
										d3 = distance_dyn(a,b,i,j-1,T) + compare_carac('-',b[j]) ;
												
										T[i][j] = min(min(d1,d2),d3);	
										return T[i][j] ;		
									}	
	
