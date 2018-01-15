format long

% Interpolação Polinomial
printf("\nQuestão 5/Cap 5 - Avalie f(x)=exp(sen(x)),  x∈[0, π/2], por:\n");
a = 0; %limite inferior
b = pi/2 ;%limite superior
n = 2 ;%grau do polinomio
erroPnMax = 1;
h = (b-a)/n;
x = a : h : b
y = exp(sin(x))
printf("\n5a - Pn(x = 0.378) com Interpolador Polinomial\n");
cOeF = fInterPol(x,y,n)
xp = 0.378;
yp = fPnBriot(n,cOeF,xp)
y_exato = exp(sin(xp));

erroPn = abs(yp - y_exato);
erroPnMax = max(erroPn)
% Fim Interpolação Polinomial

% Interpolador LaGrange
printf("\n5b - Pn(x = 0.378) com Interpolador LaGrange\n");
yp = fPnLaGrange(n,x,y,xp)
erroPn = abs(yp - y_exato);
erroPnMax = max(erroPn)
% Fim Interpolador LaGrange

% Interpolador Gregory-Newton
printf("\n5c - Pn(x = 0.378) com Interpolador Gregory-Newton\n");
difdiv1=fdifdiv(n,x,y); %vetor com diferenças no ponto i = 1 
yp=fgregoryn(n,x,y,difdiv1,xp)%y aproximado para o vetor xp(ip) 
erroPn = abs(yp - y_exato);
erroPnMax = max(erroPn)
% Fim Interpolador Gregory-Newton

% ----------- Exercício 1 Cap 6 ---------------
printf("\n\nQuestão 1 - Cap 6\n\n");
%6.1 a
printf("\nExercício 1a - Encontre o grau n mínimo para um erro na ordem de 1e-02, o erro máximo exato e os coeficientes de Pn(x) utilizando Interpolador Polinomial\n");
a = -1;
b = +1;
n = 1;
erroPnMax = 1;
tol = sqrt(10)*1e-02;

while erroPnMax > tol
    n++;
    h = (b-a)/n;
    x = a : h : b;
    y = sin(x);
    xp = a : h/20 : b; tp = (2.*xp .- (b.+a))./(b.-a);
    difdiv1=fdifdiv(n,x,y);
    yp=fgregoryn(n,x,y,difdiv1,xp);
    y_exato = sin(xp);
    
    erroPn = abs(yp - y_exato);
    erroPnMax = max(erroPn);
end
n
difdiv1
erroPnMax

% 6.1b
printf("\nExercício 1b - Encontre o grau n mínimo para um erro na ordem de 1e-02, o erro máximo exato e os coeficientes da série de Maclaurin\n");
n = 1; 
erroPnMax = 1;
while erroPnMax > tol
    n++;
    h = (b-a)/n;
    xp = a : h/20 : b; tp = (2.*xp .- (b.+a))./(b.-a);
    coefMac = fMac(n);
    yp = fPnBriot(n,coefMac,tp); 
    y_exato = sin(xp);
    erroPnMax = max(abs(yp .- y_exato));
end
n
coefMac
erroPnMax

% 6.1 c -
printf("\nExercício 1c - Expansão algébrica de f(x) em termos de Tchebyschev para n=3 e n=5\n");
printf("\nGrau inicial de Maclaurin n = 5");
printf("\n\nErro de truncamento máximo de M5(x) = |sen(x)|*(1-0)^(5+1) / (5+1)! = 1.388888e-03 (resto máximo da série)");
printf("\n\nErro de truncamento máximo de M5(x) = 1/7! = 1.98412698413e-04 (1º termo abandonado em séries com sinais alternados");
printf("\n\nEntão, tomamos Erro máximo M5 = 1.98412698413e-04, menor deles");
printf("\nSérie de Maclaurin, em ordem crescente de grau: ");
printf("\n\nM5(x)=0.0*x^0+1.0*x^1+0.0*x^2-0.166666666666667*x^3+0.0*x^4+0.008333333333333*x^5");
printf("\nTC5(T)=0. + 169/192*T(1) - (5*T(3))/128 + T(5)/1920 (truncando o último termo desta série de Tchebychev)");
printf("\n\nErro de truncamento maximo total =1/7!+1/1920=7.192460e-04 (maior que a ordem de erro de M5(x))"); 
printf("\nn = 3");
printf("\nTC3(T)=0. + 169/192*T(1) - (5*T(3))/128 \nTC3(x)=0.*1 + 169/192*x - (5*(4*x^3-3*x))/128 \nTC3(x)= (383*x)/384-(5*x^3)/32"); 
printf("\n\nCujo erro exato máximo de TC3(x) = 5.67503606437536e-04");

printf("\n\nGrau inicial de Maclaurin n = 7");
printf("\nM7(x)=0.0*x 0+1.0*x^1+0.0*x^2-0.166666666666667*x^3+0.0*x^4+0.008333333333333*x^5+0.0*x^6-1.98412698412698e-04*x^7");
printf("\nM7(x)=0.0*x^0+1.0*x^1+0.0*x^2-1/6*x^3+0.0*x^4+1/120*x^5+0.0*x^6-1/5040*x^7");
printf("\n\nErro de truncamento maximo de M7(x)= |sen(x)|*(1-0)(7+1)/(7+1)!=1/8!=1/40320= 2.4801587301*10^-05");
printf("\n\nErro  de  truncamento  maximo  de  M7(x)=  1/9! = 2.75573192239859e-06 (1º  termo  abandonado  em séries com sinais alternadas) ");
printf("\n\nEntão, tomamos Erro maximo M7=2.75573192239859e-06, menor deles."); 
printf("\nTC7(x)= 1.0*T(1)-1/6*(T(3)+3*T(1))/4+1/120*(T(5)+5*T(3)+10*T(1))/16-1/5040*(T(7)+7*T(5)+21*T(3)+35*T(1))/64"); 
printf("\nTC7(T)= 0. + 169/192*T(1) -(601*T(3))/15360+(23*T(5))/46080-T(7)/322560"); 
printf("\n\nErro de truncamento maximo total=1/9!+1/322560=5.85593e-06 (maior que a ordem de erro de M7(x)) n=5"); 
printf("\nTC5(T)= 0. + 169/192*T(1) -(601*T(3))/15360+(23*T(5))/46080");
printf("\nTC5(T)= 0. + 169/192*x -(601*(4*x^3-3*x))/15360+(23*(16*x^5-20*x^3+5*x))/46080");
printf("\nTC5(T)= 0. + (11521*x)/11520 - (959*x^3)/5760 + (23*x^5)/2880 ");
printf("\n\nCujo erro exato máximo de TC5(x) = 1.08876303214656e-04");
printf("\n\nAs  aproximações  algébricas  de  Tchebychev-Maclaurin, de graus  reduzidos,  geraram  erros  maiores que a  série de Maclaurin originais. ");

% 6.1 d -
printf("\n\nExercício 1d - Determine o erro máximo exato e os coeficientes de Tchebyschev para n = 3 e n = 5\n");
printf("\nPara k = 3\n");
b1 = fTchebychev(3)
xp = a : h/20 : b; t = (2 .* xp - (b+a))/(b-a); y_exato = sin(xp);
YTC=b1(1).*1.+b1(2).*t.+b1(3).*(2.*t.^2.-1).+b1(4).*(4.*t.^3.-3.*t);
erroTC=abs(YTC.-y_exato);
erroTCMax=max(abs(erroTC))

printf("\nPara k = 5\n");
b1 = fTchebychev(5) 
YTC=b1(1).*1.+b1(2).*t.+b1(3).*(2.*t.^2.-1).+b1(4).*(4.*t.^3.-3.*t).+b1(5).*(8.*t.^4.-8.*t.^2.+1)+b1(6).*(16.*t.^5-20.*t.^3.+5.*t);
erroTC1=abs(YTC.-y_exato);
erroTCMax = max(abs(erroTC1))

% 6.1 e - 
printf("\nExercício 1e - Determine os coeficientes e o erro exato máximo da série racional de Padé\n");
npade = 3; 
mpade = 2;
xp = a : h/20 : b;
t = (2 .* xp - (b+a))/(b-a);
coefMac = fMac(npade+mpade);
[a b]=fPade(npade,mpade,coefMac)

yPade=fPnBriot(npade,a,t)./ fPnBriot(mpade,b,t); 
%yPade=fPnHorner(npade,a,t)./ fPnHorner(mpade,b,t); 
ErroPade=abs(yPade.-y_exato); 
ErroPademax=max(ErroPade)
%plot(xp,yPade,'-k',xp,y_exato,'..r',1.2,0)

% 6.1 f
printf("\nExercício 1f - Gráfico dos erros exatos entre Tchebyschev e Padé\n");
plot(xp,erroTC,'-k',xp,erroTC1,'..r',xp,ErroPade,'.-.b')
legend('Erro Tchebyschev n = 3','Erro Tchebyschev n = 5','Erro Pade M = 5','location','north') 
grid on 