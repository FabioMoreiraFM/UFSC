function x = fNewtonSist2()
    n=2;
    %primeira iteração 
    xi = [0.2 0.2];
    dif = 1.; 
    k = 0.; 
    dx = [1e-6 1e-6]; 
        while (dif > 1.e-14 && k <20) 
            k=k+1; 
            A(1,1) = (f1([xi(1)+dx(1) xi(2)      ])-f1(xi))/dx(1); 
            A(1,2) = (f1([xi(1)       xi(2)+dx(2)])-f1(xi))/dx(2); 
            A(1,3) = -f1(xi); 
            A(2,1) = (f2([xi(1)+dx(1) xi(2)      ])-f2(xi))/dx(1); 
            A(2,2) = (f2([xi(1)       xi(2)+dx(2)])-f2(xi))/dx(2); 
            A(2,3) = -f2(xi); 
            dx=fgauss(A,n);  %  função  que  calcula  a  solução  dos sistema  pelo  metodo  de Gauss 
            x = xi + dx ;
            %segunda iteracao 
            xi=x; 
            dif = min(abs(dx./x)); %Usa-se a mínima diferença para calcular as derivadas 
        end
end

function y=f1(x) 
    R=8.314; 
    T=[300 600]; 
    v=[0.5 0.2]; 
    P=[6235.10   49881.50]; 
    y=(P(1)-x(1)/v(1)^2)*(v(1)-x(2))-R*T(1); 
end%function

function y=f2(x) 
    R=8.314; 
    T=[300 600]; 
    v=[0.5 0.2]; 
    P=[6235.10   49881.50]; 
    y=(P(2)-x(1)/v(2)^2)*(v(2)-x(2))-R*T(2); 
end%function 

