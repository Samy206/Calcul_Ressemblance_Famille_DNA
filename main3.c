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
										//FAMILLE f[6];
										//SEQUENCE D[21];
										//creer_familles(argv,f,D);
										CHAINES S ;
										S.a = "AAA";
										S.b = "AGAA";
								

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
										//for(int i = 0 ; i < 1 ; i++)
										//{
										
										//ATTT-GTAGAAGTACATT---AA
										//T-TCTATGGAA-T-C-TCTTTA

											//alea1 = (rand()%19)+1 ;
											//alea2 = (rand()%19) +1;
									

									
											d = distance_dyn(S.a, S.b, 3 , 4, 2, 3,T);
										
											
											for(int i = 0 ; i < 3 ; i++)
											{
												for(int j = 0 ; j < 4 ; j++)
												{
													printf("%2.1f\t" ,T[i][j]);
												}	
												printf("\n");
											}

											align (&S ,3 , 4 , T);

											printf("anew : %s \nbnew : %s\n, distance : %f \n",S.anew,S.bnew,d);
										//}
										exit(0);
									}


