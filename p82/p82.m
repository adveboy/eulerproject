%a = [131 673 234; 201 96 342; 630 803 746];
%read sample
%a = dlmread('sample_matrix.txt');
a = dlmread('p082_matrix.txt');
mv = ['r','u','d'];
opt = zeros(size(a)); 
opt(:,1) = a(:,1);
opt(:,2:end) = Inf;
addline = repmat(Inf,1,size(opt,2));
opt = [addline; opt; addline]
pth = zeros(size(a)); 
for j = 2:size(a,2)
    change = true;
    while (change)
        change = false;
        for i = 1:size(a,1)
            vars = [opt(i,j), opt(i+1,j-1), opt(i+2,j)];
            [mn,ix] = min(vars);
            if (opt(i+1,j) > a(i,j) + mn)
                opt(i+1,j) = a(i,j) + mn; 
                pth(i,j) = ix;
                change = 1;
            end
        end
    end
end
min(opt(:,end))
%sum([131 201 96 342 746 422 121 37 331])