function c = sumlong(a,b)
     if length(a) < length(b)
            a = [repmat(0, 1, length(b)-length(a)), a];
        else
            b = [repmat(0, 1, length(a)-length(b)), b];
        end
        sm = 0; fromold = 0; c = [];
        for cnt = length(a):-1:1
            sm = a(cnt) + b(cnt) + fromold;
            fromold = fix(sm/10);
            c = [mod(sm,10), c];
        end
        if fromold
            c = [1,c];
        end
end