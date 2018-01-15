format long
printf("--------------------------Parte 1 do trabalho--------------------------\n");
a = [1 +(-3.9-1*i) +(5.7 + 3.9*i) +(-3.7 - 5.7*i) +(0.9 + 3.7*i) +(0 - 0.9*i)];
x = sertanejo_roots(a);
Rlimite = 1e-4
printf("Raízes encontradas utilizando algoritmo proposto \n");
x

printf("\n\n--------------------------Parte 2 do Trabalho--------------------------\n");
printf("Raízes pelo método do Octave\n");
roots(a)
printf("Raízes encontradas pelo WolframAlpha\n");
e = [0.9 0.99999 1*i (1.00001 + 8.96723*1e-6*i)  (1.00001 - 8.96723*1e-6*i)]

printf("\nPode-se concluir a partir desses resultados que o trabalho proposto é melhor\n");
printf("do que o método roots e do wolfram alpha, isso acontece porque eles possuem uma\n");
printf("relaxação maior em relação ao Rlim e a tolerância, consequentemente suas raízes \n");
printf("serão um pouco mais afastadas das raízes exatas");

printf("\n\n--------------------------Parte 3 do trabalho--------------------------");
printf("\nExercício 5: Determinar os valores das cinco primeiras raízes positivas\n");
printf("de x*tan(x)-1=0\n");
x = fNewton()

printf("\n\n--------------------------Parte 4 do trabalho--------------------------");
printf("\nExercício 2: Valores dos parâmetros a e b da equação de estados de Van der Walls\n");
x = fNewtonSist2()