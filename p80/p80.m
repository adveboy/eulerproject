sm = 0;
sm_hist = cell(1,100);
j = 1;
for i = 1:100
    if (j*j ~= i)
        continue;
    end
    num = square_root(i,100);
    str = char(num);
    sm_hist{i} = num;
    sm = sm + count_sum(str);
    i
end
disp(['sm = ', sm]);