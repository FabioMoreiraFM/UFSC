% Com fator de relaxação
function x = fGaussSeidel(n,A)
    format long;
    lambda = 1; % Tem que ser menor que 1
    lambdaAux = (1-lambda);
    
    for i = 1 : n xi(i) = 0; end
    x = xi;
    
    countGaussSeidel = 0;
    countPFGaussSeidel = 0;
    dif = 1;
    while (dif > 1e-4 && countGaussSeidel < 10)
        countGaussSeidel++;
        for  i=1;          x(i)=lambdaAux*xi(i) + lambda*(450-1*x(i+1))/3; countPFGaussSeidel += 6;end
        for  i=2:n/2       x(i)=lambdaAux*xi(i) + lambda*(100-20*x(i-1)-1*x(i+1)-1*x(i+n/2))/50; countPFGaussSeidel += 10; end
        for  i=n/2+1:n-1   x(i)=lambdaAux*xi(i) + lambda*(200-1*x(i+1)-11*x(i-n/2)-3*x(i-1))/60; countPFGaussSeidel += 10;end
        for  i=n;          x(i)=lambdaAux*xi(i) + lambda*(300-3*x(i-1))/10; countPFGaussSeidel += 6; end
        dif = sum(abs(x.-xi));
        xi = x;
    end
    y = x;
    countPFGaussSeidel
    
    % K = 20 iterações para calcular erro de truncamento
    iteration = countGaussSeidel*2;
    while (dif > (1e-4)**2 && countGaussSeidel < iteration)
        countGaussSeidel++;
        for  i=1;          x(i)=lambdaAux*xi(i) + lambda*(450-x(i+1))/3;  end
        for  i=2:n/2       x(i)=lambdaAux*xi(i) + lambda*(100-20*x(i-1)-x(i+1)-x(i+n/2))/50;  end
        for  i=n/2+1:n-1   x(i)=lambdaAux*xi(i) + lambda*(200-x(i+1)-11*x(i-n/2)-3*x(i-1))/60; end
        for  i=n;          x(i)=lambdaAux*xi(i) + lambda*(300-3*x(i-1))/10; end
        dif = sum(abs(x.-xi));
        xi = x;
    end
    erro_truncamento_max_Gauss_Seidel = max(abs(y.-x))
end