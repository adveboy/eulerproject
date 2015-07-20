clear;
mx = 50;
primearr = [];
for cnt = 1:sqrt(mx)
    if isprime(cnt)
        primearr = [primearr, cnt];
    end
end
n2 = primearr(primearr < mx^(1/2)).^2;
n3 = primearr(primearr < mx^(1/3)).^3;
n4 = primearr(primearr < mx^(1/4)).^4;

sums = zeros(length(n4), length(n3));
for i = 1:length(n4)
    for j = 1:length(n3)
        sums(i,j) = n4(i) + n3(j);
    end
end
sm34 = sums(sums(:) <= mx);

for i = 1:length(sm34)
    for j = 1:length(n2)
        sums234(i,j) = sm34(i) + n2(j);
    end
end
sum(sums234(:) <= mx)
