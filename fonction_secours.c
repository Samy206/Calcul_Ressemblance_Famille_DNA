									float distance_rec(CHAINES S , int i , int j , float **T)
									{
										float d1,d2,d3,m;
										int nouvelletailleA , nouvelletailleB ;
										nouvelletailleA = strlen(S.a)+1;
										nouvelletailleB = strlen(S.b)+1;
										if(i == 0 && j > 0)
										{	
											return ( 1.5 * j );
										}
												
										else if ( j == 0 && i > 0)
										{
											return (1.5 *i );
										}
											
										else if ( i == 0 && j == 0)
										{
											return (compare_carac(S.a[i],S.b[j])) ;	
										}
											
										else if ( T[i][j] != -(1) )
										{
											return T[i][j] ;
										}
										
										else
										{
											d1 = distance_rec(S,i-1,j-1,T) + compare_carac(S.a[i],S.b[j]) ;	
											d2 = distance_rec(S,i-1,j,T) + compare_carac(S.a[i],'-') ;
											d3 = distance_rec(S,i,j-1T) + compare_carac('-',S.b[j]) ;
											
											
											if( d1 <= d2 && d1 <= d3 )
											{
												m = d1 ;
											}
											
											else if ( d2 <= d3 && d2 < d1 )
											{
												S.bnew[(nouvelletailleB)+1] = '\0' ;
												for(int k = (nouvelletailleB) ; k > j+1; k--)
												{
													S.bnew[k] = S.bnew[k-1] ;
												}													
												S.bnew[j+1] = '-' ;
												nouvelletailleB++ ;
												for(int l = 0 ; l < j+1 ; l++)
												{
													S.bnew[l] = S.b[l] ;
												}
												m = d2 ;
											}
											
											else
											{												
												S.anew[(nouvelletailleA)+1] = '\0' ;
												for(int k = (nouvelletailleA) ; k > i+1 ; k--)
												{
													S.anew[k] = S.anew[k-1] ;
												}	
												S.anew[i+1] = '-' ;
												nouvelletailleA++ ;
												for(int l = 0 ; l < i+1 ; l++)
												{
													S.anew[l] = S.a[l] ;
												}											
												m = d3 ;
											}
											
											
											
										return T[i][j] ;		
									}

