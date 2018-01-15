function x = fNewton()
    % Primeira fase: Localização da(s) raiz(es) inicial(is) 
    %Resultado de uma análise gráfica: 5 valores iniciais positivos 
    tolerancia = 1e-15; 
    xI = [1.  3.  6.  9.  12]; 
    % Segunda fase: Aproximação do valor da raiz com erro controlado 
    for i = 1 : 5 
        x(i) = Newton(xI(i), tolerancia); 
    end
end

function x = Newton(x, tolerancia) 
    dif = 1; 
    k = 0; 
    limite = 50; 
    while (dif > tolerancia && k < limite) 
        k++; 
% Núcleo do método    
        delta_x = -f(x)/derivada_f(x); 
        x = x+delta_x; 
% Núcleo do método 
        dif = abs(delta_x); 
    end 
end

function y = f(x)  
    y = x.*tan(x).-1; 
end 

function y = derivada_f(x)  
    y = tan(x).+x.*sec(x).*sec(x); 
end 