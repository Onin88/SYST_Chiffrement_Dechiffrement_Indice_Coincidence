pere:
	gcc pere.c fonction_bases.c -o pere
	gcc fils.c fonction_bases.c -o fils

clean:
	rm pere
	rm fils
	rm -f res_*.txt