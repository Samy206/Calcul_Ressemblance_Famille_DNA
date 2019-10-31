run1 : partie1
	./partie1 seq01.txt seq02.txt seq03.txt seq04.txt seq05.txt seq06.txt seq07.txt seq08.txt seq09.txt seq10.txt seq11.txt seq12.txt seq13.txt seq14.txt seq15.txt seq16.txt seq17.txt seq18.txt seq19.txt seq20.txt distance_sequences
	
partie1 : main1.o sequence.o distance.o 
	gcc -Wall -Wextra main1.o sequence.o distance.o -o partie1 -g

main1.o : main1.c 
	gcc -Wall -c main1.c -g

sequence.o : sequence.c
	gcc -Wall -c sequence.c -g
	
distance.o : distance.c
	gcc -Wall -c distance.c -g

clean : 
	rm -f *.o
	rm partie1
	ls -l
	
