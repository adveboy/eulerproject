N = 1260;
for cnt = 1:10
    
end
prod(factor(N) + 1)
numel(factor(1260))
9*4*2-1

maxprimes = ceil(log(2*N-1)/log(3));
primes = []; cnt = 2;
while (numel(primes) < maxprimes)
    if isprime(cnt)
        primes = [primes, cnt];
    end
    cnt = cnt + 1;
end

prime_level = ones(size(primes));
fprintf('%d\n', prod(prime_level*2+1));
prod(primes.^prime_level)

change = true;
cnt = numel(prime_level);
new_level = prime_level;
while(change)
    new_level(cnt) = 0;
    change = false;
    for i = 1:cnt
        tmp_level = new_level;
        tmp_level(i) = tmp_level(i) + 1;
        if (prod(tmp_level*2+1) > 2*N-1)
            change = true;
            new_level = tmp_level;
            break; %stop executing the loop
        end
    end
    cnt = cnt - 1;
end

prime_impact = ones(size(primes));
while (prod(prime_level) < 2*N - 1)
    [mn,ix] = min(prime_impact.*primes);
    prime_impact(ix) = prime_impact(ix)*primes(ix);
    prime_level(ix) = prime_level(ix) + 1;
end
fprintf('%d\n', prod(prime_impact));



