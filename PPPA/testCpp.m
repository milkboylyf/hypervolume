clear;clc;
pop = 100;      
dim = 13;       %维度


bounds = ones(1,dim);
M = 0;
for i = 1:dim-1
    C(:,i) = sqrt(1 - M ) .* rand(pop,1);
    M = M + C(:,i).^2;
end
C(:,dim) = sqrt(1 - M );
C = repmat(bounds,pop,1) - C;         %把点翻转


tic;
result(1,1)= mexPPPA(C,bounds);
% result(1,1)= mexHV(C,bounds);
result(2,1) = toc;


fprintf('已完成计算，计算hv结果：%u，消耗时间：%u \n', result(1), result(2));

