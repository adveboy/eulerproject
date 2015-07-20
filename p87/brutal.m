clear;
fileID = fopen('mlfile.txt','w');
mx = 5e7;
primearr = [];
for cnt = 1:fix(sqrt(mx))
    if isprime(cnt)
        primearr = [primearr, cnt];
    end
end
n2 = primearr(primearr.^2 < mx).^2; 
n3 = primearr(primearr.^3 < mx).^3; 
n4 = primearr(primearr.^4 < mx).^4; 
%{
    n2 = primearr.^2;
    n3 = primearr.^3;
    n4 = primearr.^4;
%}
cnt = 1; 
lng = length(n2)*length(n3)*length(n4);
%sm = zeros(length(n2)*length(n3)*length(n4),1);
maxlength = length(n2)*length(n3)*length(n4);
primevec = zeros(maxlength,3); cnt_val = 1;
sm = zeros(maxlength,1);
for i = 1:length(n2)
    for j = 1:length(n3)
        for k = 1:length(n4)
            num = n2(i) + n3(j) + n4(k);
            if (num < mx)
                primevec(cnt_val,:) = [primearr(i),primearr(j),primearr(k)];
                cnt_val = cnt_val + 1;
            end
        end
    end
end
primevec(cnt_val:end,:) = [];
result = length(unique(primevec(:,1).^2 + primevec(:,2).^3 + primevec(:,3).^4))