#/bin/bash

gcc bule.c -o saida -lglut -lGLU -lGL -lm
./saida


gcc cubo.c -o saida2 -lglut -lGLU -lGL -lm
./saida2

gcc cubonormal.c -o saida3 -lglut -lGLU -lGL -lm
./saida3
