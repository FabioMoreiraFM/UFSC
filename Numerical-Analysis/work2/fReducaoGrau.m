function [n,a] = fReducaoGrau(n,a,x,M)
    for ndiv = 1: M % Reduz o grau M vezes, Aqui ocorre BriotRuffini
        % primeira divisao
        b(1) = a(1);
        for i = 2: n+1
            b(i) = a(i) + x*b(i-1);
        end
        R(ndiv) = b(n+1);
        a = b(1:n);
        n = n-1;
        %fim da primeira divisao
    end
end