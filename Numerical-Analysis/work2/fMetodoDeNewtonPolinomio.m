function [x,M] = fMetodoDeNewtonPolinomio(n,a,xi)
  
  x = xi;
  dif = 1;
  passos = 0;
  
  while ( dif > 1e-12 && passos < 120)
    passos++;
    passos;
    R = f_restos(n,a,xi);
    M = fMultiplicidade(R);
    x = xi - R(M)/ (M*R(M+1));
    
    dif = abs(x - xi) + abs(R(1));
    xi = x;
  end
end