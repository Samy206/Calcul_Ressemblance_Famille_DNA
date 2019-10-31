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
						fclose(F);;
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
					
					SEQUENCE * initialiser_sequence ( char * argv1)
					{
						SEQUENCE *A = calloc(1,sizeof(SEQUENCE*));
						A->taille = get_taille_seq(argv1) ;
						A->s = lire_fichier(argv1);
						return A ;
					}

					
					float distance_sequence_sans_insertions( SEQUENCE * A, SEQUENCE * B)
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
						float distance = distance_sequence_sans_insertions(A,B); 
						float distance_min = 0.0 ;
						
						int difference ;
						if(A->taille > B->taille)
						{
							difference = A->taille - B->taille ;
						}
						if(A->taille < B->taille)
						{
							difference = B->taille - A->taille ;
						}
						
						if(A->taille == B->taille)
						{
							distance = distance ;
						}
						
						if(A->taille > B->taille)
						{
							if(difference == 1)
							{
								(B->taille)++;
								for(int j = B->taille ; j > 0 ; j--)
								{
									B->s[j] = B->s[j-1] ;
								}
								B->s[0] = '-' ;
								distance_min = distance_sequence_sans_insertions(A,B);
								if(distance_min < distance)
								{
									distance = distance_min ;
								}
								
								for(int k = 0 ; k < B->taille ; k++)
								{
									B->s[k] = B->s[k+1] ;
									B->s[k+1] = '-' ;
									distance_min = distance_sequence_sans_insertions(A,B);
									if(distance_min < distance)
									{
										distance = distance_min ;
									}
								}
							}
							
							if(difference == 2)
							{
								(B->taille)++;
								for(int j = B->taille ; j > 0 ; j--)
								{
									B->s[j] = B->s[j-1] ;
								}
								B->s[0] = '-' ;
								
								(B->taille)++;
								B->s[B->taille] = '-' ;
								
								for(int k = 0 ; k < (B->taille/2) ; k++)
								{
									distance_min = distance_sequence_sans_insertions(A,B);
									if(distance_min < distance)
									{
										distance = distance_min;
									}
									
									for(int l = (B->taille) ; l > ((B->taille/2)+1) ; l--)
									{
										B->s[l] = B->s[l-1];
										B->s[l-1] = '-' ;
										distance_min = distance_sequence_sans_insertions(A,B);
										if(distance_min < distance)
										{
											distance = distance_min;
										}
									}
									B->s[k] = B->s[k+1] ;
									B->s[k+1] = '-' ;
									
									for(int m = ((B->taille/2)+1) ; m < B->taille ; m++)
									{
										B->s[m] = B->s[m+1] ;
										B->s[m+1] = '-' ;
									}
								}
										
								}
								
								
						}						
						
						if(A->taille < B->taille)
						{
							if(difference == 1)
							{
								(A->taille)++;
								for(int j = A->taille ; j > 0 ; j--)
								{
									A->s[j] = A->s[j-1] ;
								}
								A->s[0] = '-' ;
								distance_min = distance_sequence_sans_insertions(A,B);
								if(distance_min < distance)
								{
									distance = distance_min ;
								}
								
								for(int k = 0 ; k < A->taille ; k++)
								{
									A->s[k] = A->s[k+1] ;
									A->s[k+1] = '-' ;
									distance_min = distance_sequence_sans_insertions(A,B);
									if(distance_min < distance)
									{
										distance = distance_min ;
									}
								}
							}
							
							if(difference == 2)
							{
								(A->taille)++;
								for(int j = A->taille ; j > 0 ; j--)
								{
									A->s[j] = A->s[j-1] ;
								}
								A->s[0] = '-' ;
								
								(A->taille)++;
								A->s[A->taille] = '-' ;
								
								for(int k = 0 ; k < (A->taille/2) ; k++)
								{
									distance_min = distance_sequence_sans_insertions(A,B);
									if(distance_min < distance)
									{
										distance = distance_min;
									}
									
									for(int l = (A->taille) ; l > ((A->taille/2)+1) ; l--)
									{
										A->s[l] = A->s[l-1];
										A->s[l-1] = '-' ;
										distance_min = distance_sequence_sans_insertions(A,B);
										if(distance_min < distance)
										{
											distance = distance_min;
										}
									}
									A->s[k] = A->s[k+1] ;
									A->s[k+1] = '-' ;
									
									for(int m = ((A->taille/2)+1) ; m < A->taille ; m++)
									{
										A->s[m] = A->s[m+1] ;
										A->s[m+1] = '-' ;
									}
								}
										
								}
								
								
						}	
						return distance ;
					}
					
					void liberer_seq(SEQUENCE *A)
					{
						free(A->s);
						free(A);
					}
							
						
