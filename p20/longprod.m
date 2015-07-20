function cold = longprod(a,b)
    cold = [];
    for i = numel(b):-1:1
        c = []; fromold = 0;
        for j = numel(a):-1:1
            c =[mod(a(j)*b(i)+fromold,10), c];
            fromold = fix((a(j)*b(i)+fromold)/10);
        end
        if (fromold>0)
            c = [fromold, c];
        end
        if ~(isempty(cold))
            %sum c and cold
            c = [c, zeros(1,numel(b)-i)];
            cold = sumlong(c,cold);
        else 
            cold = c;
        end
    end
end