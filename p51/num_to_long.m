function res = num_to_long(num)
    res = [];
    while (any(num > 0))
        res = [mod(num,10), res];
        num = fix(num/10);
    end
end