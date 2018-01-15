% O professor colocou o trabalho como individual
% então para escolher os exercícios eu considerei o grupo 5 (meu grupo).
format long
% --- Exercício 1 Cap 7 -------
printf("Exercício 1 - Cap. 7");
m=6; 
T=[ 0.2    0.4    0.6    0.8   0.9   1.0  ]; 
V=[ 0.04   0.14   0.30   0.45  0.61  0.69 ]; 
% Ajuste DIRETO para determinação de coeficientes não lineares de funções ajustadas 
% V(T)=ln(a + b*T^2) 
xi=[0.01   0.01] ;
s=fNewton2h(xi); 
a=s(1); 
b=s(2); 
%Desvio local D=abs((a+b*T(k)^(-2))^(-1)- V(k)) 
D=abs(log(a+b.*T.^2).-V); 
%Coeficiente de Determinação: 
ym=0; for k=1:m ym=ym+V(k); end  
ym=ym/m; 
SQT=0; for k=1:m SQT=SQT+(V(k)  -ym             )^2; end %soma dos quadrados totais 
SQE=0; for k=1:m SQE=SQE+(V(k)  -log(a+b*T(k)^2))^2; end %soma do quadrado dos residuos 
R1=1-SQE/SQT; %coeficiente de determinação simplificado 
np=100; 
Tp=T(1):(T(m)-T(1))/np:T(m); 
Vp=log(a.+b.*Tp.^2); 
%Interpolação polinomial de grau n=m-1=4 
n=m-1 ;
difdiv1=fdifdiv(n,T,V); %vetor com diferenças no ponto i = 1       ye = sin(xp); 
%valores exatos 
yip=fgregoryn(n,T,V,difdiv1,Tp); %y interpolado para cada xp(i)
printf("\n1.a)Determine as duas equações não lineares que permitem calcular diretamente os parâmetros a e b, através da minimização do desvio quadrático D(a,b) entre V(T), calculando em cada ponto T(k), e o valor efetivamente medido de V(k), para k = 1 até m\n");
printf("R:Como é complicado de representar as equações aqui elas se encontram nos arquivos h1.m e h2.m");
printf("\n\n1.b) Determine os parâmetros a e b resolvendo as 2 equações não lineares, obtidas em 1a), de modo a levar em conta todas as m medições experimentais\n");
a
b
printf("\n1.c) Calcule o módulo do desvio local em todos os T e o coeficiente de determinação\n");
D
R1
printf("\n1.d) Plote um gráfico com os m pontos experimentais, a função ajustada e uma função interpoladora, que passe sobre os m pontos. Diga qual foi a melhor aproximação para os m pontos");
printf("\nR: Embora a interpolação polinomial passe por todos os pontos, a função ajustada representa melhor a tendência dos pontos");
plot(T,V,'*','markersize',20,Tp,Vp,'-k','LineWidth',2,Tp,yip,'--b','LineWidth',2) 
legend('Dados experimentais','V(T)=ln(a + b*T^2)','V(T)=P4(T) interpolacao polinomial n=4','location','north'); 
grid on 

% --- Exercício 5 Cap 8 -------
printf("\n\nExercício 5 - Cap. 8\n\n");
printf("\n5.a) Quais  métodos  podem  ser  aplicados  para  calcular  numericamente  esta integral imprópria? Justifique;");
printf("\nR: Pode-se  aplicar  o  método  de  integração  de  Gauss-Legendre,  pois  é  um método onde não é avaliada a função integranda sobre os extremos do intervalo de integração.");

printf("\n\n5.b)Monte uma function Gm = fGm(a,b,m), para integrar numericamente uma função f(x) entre [a,b] pelo método de Gauss-Legendre, com até m=7 pontos com precisão double\n");
Gm = fGm(0,1,7)

printf("\n5.c) Determine e imprima Gm(m) e os erros exatos de Gm(m), com m = 2 até 7 pontos.\n");
I = -1;
for i = 2 : 7
    Gm = fGm(0,1,i)
    ErroExato = abs(Gm-I)
end