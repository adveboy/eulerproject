% generate days one-by-one
days = [31 28 31 30 31 30 31 31 30 31 30 31];
sum(days == 30)
first_day = [];
for cnt = 1901:2000
    for i = 1:12
        if (i == 2)
            if ((~mod(cnt,4) && mod(cnt,100)) || (~mod(cnt,100) && ~mod(cnt,400)))
                %leap year
                first_day = [first_day, [1 zeros(1, 28)]];
            else
                first_day = [first_day, [1 zeros(1, 27)]];
            end
        else 
            first_day = [first_day, [1 zeros(1, days(i)-1)]];
        end
        
    end
end
sundays = [repmat([0 0 0 0 0 0 1], 1, fix(numel(first_day)/7)), zeros(1, mod(numel(first_day),7))];
sum(first_day & sundays)
