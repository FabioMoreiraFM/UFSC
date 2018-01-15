function A = pivot_parcial(A,n,k) #I/O da funcao

maior_valor = abs(A(k,k));
max_index = k;
for i = k+1 : n
    aux = abs(A(i,k));
    if(aux > maior_valor)
        maior_valor = aux;
        max_index = i;
    endif
endfor


Aaux = A(k,:);
A(k,:) = A(max_index,:);
A(max_index,:) = Aaux;
end