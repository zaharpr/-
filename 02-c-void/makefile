# makefile for sorting.asm
task: main.c input.c inrnd.c output.c sorting.o surfaceArea.o
	gcc -g -o task main.c sorting.o surfaceArea.o -no-pie
sorting.o: sorting.asm
	nasm -f elf64 -g -F dwarf sorting.asm -l sorting.lst
surfaceArea.o: surfaceArea.asm
	nasm -f elf64 -g -F dwarf surfaceArea.asm -l surfaceArea.lst