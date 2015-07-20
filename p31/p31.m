coins = [1 2 5 10 20 50 100 200];
%coins = [1 2];
sum = 200;
ways = zeros(1,sum + 1);
ways(1) = 1;
for i = 1:length(coins)
    for j = coins(i):sum
        ways(j+1) = ways(j+1) + ways(j+1-coins(i));
        ways
    end
end
fprintf('number of ways is %.0f\n', ways(end));


