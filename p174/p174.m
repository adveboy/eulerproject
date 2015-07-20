Nmax = 10^6;
tcount = zeros(Nmax,1);
for n = 3:floor((Nmax+4)/4)
    for m = n-2:-2:ceil(sqrt(max(n^2-Nmax,1)))
        pos = n^2-m^2;
        tcount(pos) = tcount(pos) + 1;
        %[pos n m]
    end
end
sum(tcount == 15)
[mx,ix] = max(tcount);
totalsum = 0;
for cnt = 1:10
    totalsum = totalsum + sum(tcount == cnt);
end
totalsum