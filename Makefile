CFLAGS=-Wall -g

all: thermom histogram entab htoi invert

clean:
	rm -rf *.dSYM
	rm -r thermom
	rm -r histogram 
	rm -r entab 
	rm -r htoi
	rm -r invert
