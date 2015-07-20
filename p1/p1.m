sm = 0;
nums = [];
for cnt=1:1000-1
    if (rem(cnt,3) == 0 || rem(cnt,5) == 0 || rem(cnt,15) == 0)
        nums = [nums cnt];
        sm = sm + cnt;
    end
end
sm
%nums