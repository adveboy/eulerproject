for i = 1:499
    for j = 1:499
        if (i*i + j*j == (1000-i-j)*(1000-i-j))
            a = i; b = j; c = (1000 - i - j);
            break
        end
    end
end
a*b*c
