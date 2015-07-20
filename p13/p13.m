% ? ???????!)
fid = fopen('numbers.txt');
tline = cell(1000,1);
tline{1} = strtrim(fgets(fid));
sum = 0;
cnt = 2;
nextl = fgets(fid);
while ischar(nextl)
    tline{cnt} = strtrim(nextl);
    cnt = cnt + 1;
    nextl = fgets(fid);
end
tline(cnt:end) = [];
% tline

strsize = length(tline{1}); 
cyp = [];
fromold = 0;
for i = strsize:-1:1
    sm = 0; 
    for cnt = 1:length(tline)
        sm = sm + str2num(tline{cnt}(i));
    end
    sm = sm + fromold;
    fromold = fix(sm/10);
    cyp = [ mod(sm,10), cyp];
end
ost = num2str(fromold);
firstcyps = cyp(1:10-length(ost));
answer = num2str(ost);
for cnt = 1:length(firstcyps)
    answer = [answer, num2str(firstcyps(cnt))];
end
answer

