function A = pivot_parcial(A,n,k) 
    #procura sempre a melhor linha para cada passo
    #passo 1
    #descobrir melhor linha k, maior pivô (modulo) da coluna; erro de arredondamento; maior diagonal principal
    
    maior_valor = abs(A(k,k));
    max_index = k;
    for i = k+1 : n
        aux = abs(A(i,k));#pesquisa na linha certa
        if(aux > maior_valor)
            maior_valor = aux;
            max_index = i;
        endif
    endfor
    
    Aaux = A(k,:);
    A(k,:) = A(max_index,:);
    A(max_index,:) = Aaux;
end