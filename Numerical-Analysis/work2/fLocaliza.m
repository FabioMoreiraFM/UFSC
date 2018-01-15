% Objetivo encontrar 1 valor inicial
function xi = fLocaliza(n,a)
    % Encontrar o raio max (cota max)
    r_max = 1 + max(abs(a(2:n+1))) / abs(a(1));
    
    % Encontrar o raio mínimo das raízes (cota min). Abaixo dele não existe raízes.
    r_min = 1/(1 + max(abs(a(1:n) ) )/ abs(a(n+1)) );
    
    x = (r_max + r_min)*0.5;
    xi = complex(x*cos(pi/4),x*sin(pi/4));
    
end