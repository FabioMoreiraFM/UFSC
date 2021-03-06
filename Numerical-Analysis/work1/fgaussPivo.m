function x = fgaussPivo(A, n)

countComPivo = 0;
    for k = 1 : n - 1
        for i =  k + 1 : n
            A = pivot_parcial(A,n,k); #imprime com linhas trocadas
            aux = A(i, k)/A(k, k);
            countComPivo++;
            for j = k + 1 : n + 1
                A(i,j) = A(i, j) - aux*A(k, j); %Li <- Li - aux * Lk
                countComPivo += 2;
            end 
            A(i,k) = 0; %coluna j=k tem resultado ZERO conhecido
        end
    end
    

%retrosubstituição
aux_abs = abs(A(n,n));
if (aux_abs < 1e-15)
    if (abs(A(n,n+1)) < 1e-15)
    #atribuir valor a x(n)
        x(n) = 0; "Sistema Possível Indeterminado"
    else
        x(n) = NaN; "Sistema Impossível"
    endif
else
    x(n) = (A(n,n+1)/A(n,n));
    countComPivo++;
endif

for i=(n-1):-1:1
    soma = 0;
    for j=(i+1):n
       soma = soma + (A(i,j) * x(j));
       countComPivo += 2;
    end
  x(i) = (A(i, n+1) - soma)/ A(i,i);
  countComPivo += 2;
end
countComPivo
end