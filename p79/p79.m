M = dlmread('p079_keylog.txt');
n1 = mod(M,10);
M2 = (M - n1)/10;
n2 = mod(M2, 10);
M3 = (M2 - n2)/10;
n3 = mod(M3, 10);
[M n3 n2 n1];
cyp = [n3 n2 n1]; 
allcyp = (unique(cyp(:)))';
cypi = cyp + 1;
% 
A = zeros(10);
for cnt = 1:size(cypi,1)
    A(cypi(cnt,1),cypi(cnt,2)) = 1;
    A(cypi(cnt,1),cypi(cnt,3)) = 1;
    A(cypi(cnt,2),cypi(cnt,3)) = 1;
end
A(:,~ismember(0:9, allcyp)) = [];
A(~ismember(0:9, allcyp),:) = [];

B = A + A';

%{
allcyp = [7 5 3 11 8 2 9 10];
A = [0 0 0 1 1 0 0 0;
     0 0 0 1 0 0 0 0;
     0 0 0 0 1 0 0 1;
     0 0 0 0 0 1 1 1;
     0 0 0 0 0 0 1 0;
     0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 0]
%}
% check if we have any 

L = [];
change = true;
S = allcyp;
while (length(L) ~= length(allcyp) && change)
    %find no-ins
    allnoincome = allcyp(~any(A,1));
    noincome = allnoincome(ismember(allnoincome, S));
    change = ~isempty(noincome); 
    %add no-ins to L
    % L 
    noincome
    L = [L noincome];
    A(ismember(allcyp, noincome),:) = 0;
    %delete them from S, add to L
    S(ismember(S, noincome)) = [];
end


str = '';
for cnt = 1:length(L)
    str = [str, num2str(L(cnt))];
end
str

find((any(cyp == 3,2)) & (any(cyp == 7,2)))