function res = long_to_num(long)
    res = 0;
    for cnt = 1:size(long,2)
        res = res*10 + long(:,cnt);
    end
end