#!/bin/bash


A=$(sed -n 1p coordonnees.txt)
B=$(sed -n 2p coordonnees.txt)
C=$(sed -n 3p coordonnees.txt)
D=$(sed -n 4p coordonnees.txt)
E=$(sed -n 5p coordonnees.txt)
F=$(sed -n 6p coordonnees.txt)
G=$(sed -n 7p coordonnees.txt)
H=$(sed -n 8p coordonnees.txt)
I=$(sed -n 9p coordonnees.txt)

CHEMIN='/home/prof/troispartrois/'

IP='IP'
USER='pignol'

ssh $USER@$IP cat $CHEMIN/$A $CHEMIN/$D $CHEMIN/$G > 1.fodaly
ssh $USER@$IP cat $CHEMIN/$B $CHEMIN/$E $CHEMIN/$H > 2.fodaly
ssh $USER@$IP cat $CHEMIN/$C $CHEMIN/$F $CHEMIN/$I > 3.fodaly

cat 1.fodaly espace.fodaly 2.fodaly espace.fodaly 3.fodaly > lab.fodaly

cd ..
cd src

echo "DEBUT DE RESOLUTION : ALGORYTHME RANDOM"
gcc -std=c99 random.c -L. -llabyrinthes -lcairo -lX11
./a.out
