a = [2];
for cnt = 3:100
    cntcop = cnt;
    b = [];
    while (cntcop>0)
        b = [mod(cntcop,10),b];
        cntcop = fix(cntcop/10);
    end
    a = longprod(a,b);
end
sum(a)