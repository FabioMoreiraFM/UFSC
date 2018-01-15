% Algoritmo funciona mas é menos eficiente
function yp = fPnHorner(n,a,xp)
    for k = 1 : length(xp)
        aux = a(n+1);
        for i = n: -1: 1
            aux = a(i) + aux*xp(k);
        end
        yp(k) = aux;
    end
end