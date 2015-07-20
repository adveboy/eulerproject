a = zeros(4*10^6,1);
a(145) = 1;
a([169 363601 1454]) = 3;
a([871 45361 871]) = 3;
a([872 45362 872]) = 3;
for i = 1:10^6
    curr = i; b = []; 
    loop_found = a(curr);
    while (~loop_found)
        b = [b, curr];
        curr = sum(factorial(num_to_long(curr)));
        if(a(curr)>0)
            for cnt = numel(b):-1:1
                a(b(cnt)) = a(curr) + numel(b) - cnt + 1;
            end
            loop_found = true;
        end
    end
end
