%generate 1000 prime numbers
%generate 1000 squares
%build matrix of prime+2*square

N = 10000;
oddcomp = 9; i = 9;
while (oddcomp(end) < N)
    i = i + 1;
    if (mod(i,2) == 1 && ~isprime(i)) 
        oddcomp = [oddcomp; i];
    end
end

sqrs = zeros(fix(sqrt(N/2)),1);
for i = 1:length(sqrs)
   sqrs(i) = 2*i^2;
end

primes = 2; %zeros(1000,1);

pr_ix = 0; i = 0;
while (primes(end) < N)
    i = i + 1;
    if isprime(i)
        pr_ix = pr_ix + 1;
        primes = [primes; i];
    end
end


odds = (1+(1:N)*2)';
diff = repmat(oddcomp,1,length(primes)) - repmat(primes',length(oddcomp),1);
for i = 1:size(diff,1)
    if (~any(ismember(diff(i,:),sqrs)))
        disp([num2str(oddcomp(i)), ' is not representable']);
        break;
    end
end

%{
A = zeros(1000,1000);
for i = 1:1000
    for j = 1:1000
        A(i,j) = primes(i) + sqrs(j);
    end
end
sort(A(:))
%}