function x = sertanejo_roots(a)
    n = size(a,2)-1; % size é para matriz, gambiarra
    
    % Normalização
    for i = 2: n+1
        a(i) = a(i)/a(1); 
    end
    a(1) = 1;
    
    % Faz parte da purificao
    a_original = a;
    n_original = n;
    
    k = 0;
    while (n > 0)
        % Para 1ª raiz
        k++;
        k;
        % localizar a raiz
        xi(k) = fLocaliza(n,a);
        % Aproximacao
        [x(k),M(k)] = fMetodoDeNewtonPolinomio(n,a,xi(k));
        
        % Técnica da Purificacao da raiz x(k) encontrada
        [x(k),M(k)] = fMetodoDeNewtonPolinomio(n_original,a_original,x(k));
        
        % Reducao de grau pela raiz x, M vezes
        [n,a] = fReducaoGrau(n,a,x(k),M(k));
        % printf("\n\n");
        
    end
    M
    
end