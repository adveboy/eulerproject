d = [31 28 31 30 31 30 31 31 30 31 30 31];
m = 0; y = 1900; 
dd = 1;  sun1 = 0;
while (y < 2001)
    if (m == 2 && ~mod(y,4))
        y
        dd = dd + 29;
    else
        dd = dd + d(m+1);
    end
    if (y ~= 1900)
        sun1 = sun1 + ~mod(dd,7);
    end
    y = y + ~mod(m + 1, 12); % change year
    m = mod(m + 1, 12); % change month
end

sun1