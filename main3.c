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
										CHAINES S ;
										/*S.a = malloc(strlen(D[13].s));
										S.b = malloc(strlen(D[2].s));
										strcpy(S.a,D[13].s);
										strcpy(S.b,D[2].s);
										printf("S.a : %s , S.b : %s \n",S.a,S.b);
										S.anew = malloc(strlen(S.a)+3);
										S.bnew = malloc(strlen(S.b)+3);
										//strcpy(S.anew,S.a);
										//strcpy(S.bnew,S.b);
										S.anew[0] = '\0' ;
										S.bnew[0] = '\0' ;
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
									

										d = distance_dyn(S.a, S.b,D[13].taille-1,D[2].taille-1,T);
										
					

										align (&S,D[13].taille-1 ,D[2].taille-1, T);
										printf("anew : %s \nbnew : %s\n, distance : %f \n",S.anew,S.bnew,d);*/
										char **Sek = creer_deux_seq(Sek,f[1]);
										
						
											
											
										exit(0);
									}


