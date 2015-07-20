sm = 0;
for cnt = 2:(2000000-1)
    if (isprime(cnt))
        sm = sm + cnt;
    end
end
sm