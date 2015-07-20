%a = [131 673 234; 201 96 342; 630 803 746];
%read sample
%a = dlmread('p081_matrix.txt');
a = dlmread('p081_matrix.txt');
opt = zeros(size(a)); 
pth = zeros(size(a)); %pth=1 if left pth = 2 if up
for i = 1:size(a,2)
    for j = 1:size(a,1)
        if (i == 1 && j == 1)
            opt(i,j) = a(1,1);
        elseif (i == 1)
            opt(i,j) = opt(1,j-1) + a(i,j); pth(1,j) = 1;
        elseif (j == 1)
            opt(i,j) = opt(i-1,1) + a(i,j); pth(i,1) = 2;
        else
            if (opt(i,j-1) < opt(i-1,j))
                opt(i,j) = opt(i,j-1) + a(i,j); pth(i,j) = 1;
            else
                opt(i,j) = opt(i-1,j) + a(i,j); pth(i,j) = 2;
            end
        end
    end
end

i = size(a,1); j = size(a,1); 
sm = a(i,j);
pthseq = a(i,j);
while(~(i==1 && j==1))
   if (pth(i,j) ==  1);
       j = j-1;
   else
       i = i-1;
   end
   sm = sm + a(i,j);
   pthseq = [a(i,j) pthseq];
end

%sum([131 201 96 342 746 422 121 37 331])