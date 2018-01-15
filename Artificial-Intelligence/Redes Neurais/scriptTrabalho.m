clear all
clc
path(path,'C:\Users\Fabio\7 Fase\IA\Trabalhos\Redes Neurais');
load exdata.mat

for i=1:size(X,2)
    SaidaTrein(y(1,i),i)=1;
end

[X_N,PS]=mapminmax(X);

net=newff(X,SaidaTrein,50,{'tansig','purelin'},'traingdx');
net.trainParam.epochs=5000;
net.divideParam.trainRatio=0.9;
net.divideParam.testRatio=0.1;
net.divideParam.valRatio=0.1;
net.trainParam.max_fail = 50;
net=train(net,X,SaidaTrein);

Y=sim(net,X);

for i=1:size(X,2)
	c = max([Y(1,i),Y(2,i),Y(3,i),Y(4,i),Y(5,i),Y(6,i),Y(7,i),Y(8,i),Y(9,i),Y(10,i)]);
    for j=1:10
        if Y(j,i)== c
            YClass(j,i)=1;
        end
    end
end

plotconfusion(SaidaTrein,YClass);
