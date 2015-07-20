function res = long_to_num(long)
    res = 0;
    for cnt = 1:length(long)
        res = res*10 + long(cnt);
    end
end