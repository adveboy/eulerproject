long_to_num(num_to_long(50));
maxsum = 0;
for i = 2:99
    ilong = num_to_long(i); curr_prod = ilong;
    for j = 2:99
        jlong = num_to_long(j);
        curr_prod = longprod(curr_prod, ilong);
        if (sum(curr_prod) > maxsum)
            maxsum = sum(curr_prod);
        end
    end
end
maxsum
