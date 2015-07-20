a = zeros(4*10^6,1);
for i = 1:10^6
    curr = i; b = []; 
    loop_found = a(curr);
    while (~loop_found)
        b = [b, curr];
        curr = sum(factorial(num_to_long(curr)));
        if (curr == 45360)
            ss = 1;
        end
        [mem, ix] = ismember(curr, b);
        if mem
            for cnt = numel(b):-1:ix
                a(b(cnt)) = numel(b)-ix+1;
            end
            for cnt = ix-1:-1:1
                a(b(cnt)) = numel(b)-ix+1+ix-cnt;
            end
            loop_found = true;
        elseif (a(curr) > 0)
            for cnt = numel(b):-1:1
                a(b(cnt)) = a(curr)+numel(b)-cnt+1;
            end
            loop_found = true;
        end
    end
end
sum(a(1:10^6) == 60)