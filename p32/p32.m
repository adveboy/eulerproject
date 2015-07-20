P = perms(1:9);
sm = 0;
all_pandigital = [];
tic
for i = 1:5
    num1 = P(:,1:i);
    %form num1
    num1n = zeros(size(num1,1),1);
    for k = 1:size(num1,2)
        num1n = num1n*10 + num1(:,k);
    end
    for j = i+1:6
        num2 = P(:,i+1:j);
        num3 = P(:,j+1:end);
        num2n = zeros(size(num2,1),1);
        for k = 1:size(num2,2)
            num2n = num2n*10 + num2(:,k);
        end
        num3n = zeros(size(num3,1),1);
        for k = 1:size(num3,2)
            num3n = num3n*10 + num3(:,k);
        end
        ix = all(num1n.*num2n == num3n,2);
        if any(all(num1n.*num2n == num3n,2)) 
            num1n(ix)
        end
        all_pandigital = [all_pandigital; num1n(ix), num2n(ix), num3n(ix)];
        sm = sm + sum(num3n(all(num1n.*num2n == num3n,2)));
    end
end
toc
sum(unique(all_pandigital(:,3)))
