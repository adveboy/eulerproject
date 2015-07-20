function b = square_root(n, digits)
    limit = 10^(digits + 1);
    a = sym(5*n);
    b = sym(5);
    while (b < limit)
        %{
        if (~(mod(b,1000)==0))
            a = sym(1);
        end
        %}
        if (a >= b)
            a = a - b; 
            b = b + 10 ;
            % disp('branch1');
        else 
            a = a*100;
            b = fix(b/10)*100 + 5;
            % disp('branch2');
        end
        % disp(['a = ', char(a), '; b =  ', char(b)]);
    end
    b = fix(b/100);
end