fid = fopen('number.txt');
number = [];
tline = fgetl(fid);
while ischar(tline)
    disp(tline)
    tline = fgetl(fid);
    number = [number tline];
end
number = number(1:length(number)-1);
fclose(fid);
pr = [];
array_of_cyphers = zeros(length(number) - 12,13);
for cnt = 1:length(number) - 12
    prnew = 1;
    for i = 0:12
        array_of_cyphers(cnt,i+1) = str2num(number(cnt+i));
    end
end

max(prod(array_of_cyphers,2))
disp(['desired prod = ', num2str(srt(13))]);
disp(['cyphers = ', number(i(13):i(13)+3)]);