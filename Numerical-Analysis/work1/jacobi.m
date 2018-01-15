function x = jacobi(n)
format long

lambda = 1; % Tem que ser menor que 1
lambdaAux = (1-lambda);
for  i=1:n;
    xi(i) = 0;
end
dif_maxima = 1;
count_jacobi = 0;
k = 0;
while dif_maxima > 1e-4
% Parte Principal
    for  i=1;          x(i)=lambdaAux*xi(i) + lambda*(450-1*xi(i+1))/3;  count_jacobi += 6; end
    for  i=2:n/2       x(i)=lambdaAux*xi(i) + lambda*(100-20*xi(i-1)-1*xi(i+1)-1*xi(i+n/2))/50;  count_jacobi += 10; end
    for  i=n/2+1:n-1   x(i)=lambdaAux*xi(i) + lambda*(200-1*xi(i+1)-11*xi(i-n/2)-3*xi(i-1))/60; count_jacobi += 10; end
    for  i=n;          x(i)=lambdaAux*xi(i) + lambda*(300-3*xi(i-1))/10; count_jacobi += 6; end
%
    dif_maxima = sum(abs(x-xi)); % Olho pro max pq se o max é pequeno não precisa ver os outros
    xi = x;
end
x;
dif_maxima;
count_jacobi