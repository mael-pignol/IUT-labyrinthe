#!/bin/bash

A=$(sed -n 1p ptdr.txt)
B=$(sed -n 2p ptdr.txt)
C=$(sed -n 3p ptdr.txt)
D=$(sed -n 4p ptdr.txt)
E=$(sed -n 5p ptdr.txt)
F=$(sed -n 6p ptdr.txt)
G=$(sed -n 7p ptdr.txt)
H=$(sed -n 8p ptdr.txt)
I=$(sed -n 9p ptdr.txt)

CHEMIN='/home/prof/troispartrois/'

IP='IP'
USER='pignol'

ssh $USER@$IP cat $CHEMIN/$A $CHEMIN/$D $CHEMIN/$G > 1.fodaly
ssh $USER@$IP cat $CHEMIN/$B $CHEMIN/$E $CHEMIN/$H > 2.fodaly
ssh $USER@$IP cat $CHEMIN/$C $CHEMIN/$F $CHEMIN/$I > 3.fodaly

cat 1.fodaly espace.fodaly 2.fodaly espace.fodaly 3.fodaly > lab.fodaly

cd ..
cd src

echo "DEBUT DE RESOLUTION : ALGORYTHME PLEDGE"
gcc -std=c99 pledge.c -L. -llabyrinthes -lcairo -lX11
./a.out
