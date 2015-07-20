clear;
N = 100;
elems = 1:(N-1);
%coins = [1 2];
ways = zeros(1, N + 1);
ways(1) = 1;
for i = 1:length(elems)
    for j = elems(i):N
        ways(j + 1) = ways(j + 1) + ways(j + 1 - elems(i));
        %ways
    end
end
fprintf('number of ways is %.0f\n', ways(end));

% finally it's finished


