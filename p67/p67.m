M = dlmread('p067_triangle.txt')
%M = dlmread('sample.txt')
opt = zeros(size(M))
opt(1,1) = M(1,1);
opt(2,1) = M(1,1)+M(2,1);
opt(2,2) = M(1,1)+M(2,2);
for i = 3:size(M,1)
    opt(i,1) = opt(i-1,1) + M(i,1);
    for j = 2:i
        opt(i,j) = max(opt(i-1,j-1),opt(i-1,j)) + M(i,j);
    end
end
max(opt(end,:))