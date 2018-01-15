function x = fgauss(n,A)

%Escalonamento para transformar A em U (triangular superior)
countSemPivo = 0;
    for k = 1 : n - 1
        for i =  k + 1 : n 
            aux = A(i, k)/A(k, k);
            countSemPivo++;
            for j = k + 1 : n + 1
                A(i,j) = A(i, j) - aux*A(k, j); %Li <- Li - aux * Lk
                countSemPivo += 2;
            end
            A(i,k) = 0;  %coluna j=k tem resultado ZERO conhecido
        end
    end


%retrosubstituição
aux_abs = abs(A(n,n));
if (aux_abs < 1e-15)
    if (abs(A(n,n+1)) < 1e-15)
        x(n) = 0; "Sistema Possível Indeterminado"
    else
        x(n) = NaN; "Sistema Impossível"
    endif
else
    x(n) = (A(n,n+1)/A(n,n));
    countSemPivo++;
endif

for i=(n-1):-1:1
    soma = 0;
    for j=(i+1):n
       soma = soma + (A(i,j) * x(j));
       countSemPivo += 2;
    end
    x(i) = (A(i, n+1) - soma)/ A(i,i);
    countSemPivo += 2;
end
countSemPivo
end