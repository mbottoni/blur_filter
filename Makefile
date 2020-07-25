#Makefile
main:
	gcc -omain src/main.c src/imageprocessing.c -I./ -lfreeimage
	./main
	xdg-open cachorro-out.jpg
	xdg-open data/cachorro.jpg

clear:
	rm main
	rm cachorro-out.jpg
