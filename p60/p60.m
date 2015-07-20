% find primes less than 10000

maxp = 30;
primes = [];
for i = 1:maxp
    if isprime(i)
        primes = [primes, i];
    end
end
% build the matrix  
A = zeros(numel(primes));
for i = 1:numel(primes)
    for j = 1:numel(primes)
        A(i,j) = isprime(str2num([num2str(primes(i)),num2str(primes(j))]));
    end
    i
end


elems_to_find = 3;
B = A + A' + 2*diag(ones(size(A,1),1));
gangs = [];
for i = 1:size(B,1)
    ix = find(B(i,:) == 2);
    M = B(ix,ix);
    gangset = ix(find(all(M == 2,1) & (all(M == 2,2))'));
    if (numel(gangset) > 1)
        aa = 1;
    end
    if (numel(gangset) >= elems_to_find)
        tmp = permute(gangset);
        gangs = [gangs; unique(tmp(:,1:elems_to_find),'rows')];
    end
end

p = perms(1:5);
unique(p(:,1:2),'rows')
ixx = find(ismember(primes, [3 7 109 673]))
B(ixx,ixx)
