%shitty bruteforce (!!!)
mx = 5e7;
primearr = [];
for cnt = 1:sqrt(mx)
    if isprime(cnt)
        primearr = [primearr, cnt];
    end
end
cnt = 0;
for N = (2^4 + 2^3 + 2^2):mx
    n2 = primearr(primearr < N^(1/2)).^2;
    n3 = primearr(primearr < N^(1/3)).^3;
    n4 = primearr(primearr < N^(1/4)).^4;
    for i = 1:length(n4)
        R1 = N - n4(i);
        for j = 1:length(n3)
            R2 = R1 - n3(j); 
            if (R2 < 0) 
                break;
            end
            [n2m, ix] = ismember(R2,n2);
            if n2m 
                %disp([N n2(ix), n3(j), n4(i)]);
                cnt = cnt + 1;
                disp(['N = ', num2str(N), '; cnt = ', num2str(cnt)]);
            end
        end
    end
end
%shitty bruteforce (!!!)
