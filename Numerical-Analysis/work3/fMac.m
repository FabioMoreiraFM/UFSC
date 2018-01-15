function a = fMac(n)
    for i=1:n+1 
           ii=2*i; 
           c(ii-1)=0; 
           c(ii)=(-1)^(i-1)/factorial(2*i-1); 
    end
    a = c(1:n+1);
end