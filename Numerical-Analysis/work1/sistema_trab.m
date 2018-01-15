format long
% ---------------------- Criação da matriz ----------------------
n = 50;
A(n,n+1) = 0; % Não necessário no Octave
for  i=1;             A(i,i)=3;A(i,i+1)=1;A(i,n+1)=450; end
for  i=2:n/2          A(i,i-1)=20;A(i,i)=50;A(i,i+1)=1;A(i,i+n/2)=1;A(i,n+1)=100; end
for  i=n/2+1:n-1      A(i,i-n/2)=11;A(i,i-1)=3;A(i,i)=60;A(i,i+1)=1;A(i,n+1)=200; end
for  i=n;             A(i,i-1)=3;A(i,i)=10;A(i,n+1)=300; end

% ------------------------------------------------------------------

% ---------------------- Cálculo Método Direto Gauss ----------------------

printf("Letra a - Contador de Ponto Flutuante, resíduo e erro de truncamento \ndo Gauss sem Pivotação\n")
% Resultado do Sistema (SEM PIVOTACAO)
x = fgauss(n,A);

%Residuo Max do Sistema (SEM PIVOTACAO)
res_maxSP = fresiduo(n,A,x)

printf("Gauss não possui erro de truncamento\n")

printf("\nLetra b - Contador de Ponto Flutuante e resíduo do Gauss com Pivotação\n")
%Resultado do Sistema (COM PIVOTACAO)
y = fgaussPivo(A,n);

%Residuo Max do Sistema (COM PIVOTACAO)
res_maxCP = fresiduo(n,A,y)

printf("\nLetra c - Comparação dos resíduos")
if (res_maxCP < res_maxSP)
    printf("\nO residuo do Gauss com pivotação é menor, logo é mais exato \n")
else
    printf("\nO resíduo do Gauss sem pivotação é menor, logo é mais exato \n")
endif
printf("\n") 
% -------------------------------------------------------------------------

% -------------------- Método de Jacobi -----------------------------------
printf("Letra d - Contador de Ponto Flutuante e fator de relaxação do método de Jacobi\n") 
j = jacobi(n);
lambda = 1
printf("\n") 
% -------------------------------------------------------------------------

% -------------------- Método de Gauss-Seidel------------------------------
printf("Letra e - Contador de Ponto Flutuante, erro de truncamento e fator de relaxação\ndo Gauss-Seidel\n") 
gs = fGaussSeidel(n,A);
lambda = 1
% -------------------------------------------------------------------------

% ---- Resultador ---

printf("\nResultado das incógnitas pelo método de Gauss Com Pivotação\n")
y
printf("\nResultado das incógnitas pelo método de Gauss-Seidel \n")
gs