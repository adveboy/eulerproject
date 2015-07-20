function f = count_sum(str)
    arr = [];
    str = char(str);
    for cnt = 1:length(str)
        arr = [arr, int8(str(cnt)-'0')];
    end
    f = sum(arr);
end