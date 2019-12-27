									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "alignement.h"
									#include "famille.h"
									
									int main(int argc , char ** argv )
									{
										//srand(getpid());
										//int alea1 , alea2 ;
										FAMILLE f[6];
										SEQUENCE D[21];
										
										creer_familles(argv,f,D);
										/*CHAINES S ;
										S.a = malloc((D[16].taille));
										S.b = malloc((D[12].taille));
										strcpy(S.a,D[16].s);
										strcpy(S.b,D[12].s);

										S.anew = malloc(40);
										S.bnew = malloc(40);
								

										float **T = malloc(19*sizeof(float*));
										for(int i = 0 ; i < 19 ; i++ )
										{
											T[i] = malloc(19*sizeof(float));
											for(int j = 0 ; j < 19 ; j++)
											{
											
												T[i][j] = -1;
											}
									
										}
									
									
										float d;
									

										d = distance_dyn(S.a, S.b, D[16].taille-1 , D[12].taille-1,T);
										
											
											for(int i = 0 ; i < 18 ; i++)
										{
											for(int j = 0 ; j < 18 ; j++)
											{
												printf("%2.1f\t" ,T[i][j]);
											}	
											printf("\n");
										}

										align (&S,D[16].taille-1 ,D[12].taille-1, T);
										printf("anew : %s \nbnew : %s\n, distance : %f \n",S.anew,S.bnew,d);*/
										
						
											
											
										exit(0);
									}


