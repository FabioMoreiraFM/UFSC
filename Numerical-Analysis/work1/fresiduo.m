function rmax=fresiduo(n,A,x)

	for i=1:n
		soma=0;
		for j=1:n
			soma=soma+A(i,j)*x(j);
		end
		r(i)=abs(soma-A(i,n+1));
	end
	rmax=max(r);

end