%generate primes
%by deleting all variants of columns get the rest
%{
maxp = 10^6;
primes = zeros(maxp,1);
cnt = 1;
for i = 1:maxp
    if isprime(i)
        primes(cnt) = i;
        cnt = cnt + 1;
    end
end
primes(cnt+1:end,:) = [];
lng = num_to_long(primes);
ixs = num_to_long(str2num(dec2bin((1:63)')));
%}

for cnt = 1:size(ixs,1)
    ix = logical(ixs(cnt,:));
    static_cols = lng(:,~ix);
    var_cols = lng(:,ix);
    [static_sort, ix] = sort(static_cols,1);
    var_sorted = var_cols(ix,:);
    %delete rows that don't have the same cyphers
    ix_del = zeros(size(var_cols,1),1);
    for cnt = 2:size(var_cols,2)
        ix_del = ix_del & (var_cols(:,1) ~= var_cols(:,cnt));
    end
    static_cleant(ix_del,:) = [];
    var_cols(ix_del,:) = [];
    ix_last = all(static_cleant(1:end-1,:) == static_cleant(2:end,:),2);
    
end
