a = 9;
b = (1:5)';
a = repmat(9,length(b),1);
c = repmat(9,length(b),1).*b;
cstr = '';
for cnt = 1:length(c)
    cstr = [cstr, num2str(c(cnt))];
end
unique(sort(cstr));
[a b c];


first_num = 9;
%generate initial numbers
for cnt = 90:98
    first_num = [first_num; cnt];
end
for cnt = 900:987
    first_num = [first_num; cnt];
end
for cnt = 9000:9876
    first_num = [first_num; cnt];
end
%first_num
total_elems = [];
for cnt = 1:9
    total_elems = [total_elems, first_num*cnt];
end
%total_elems
pandigit = [];
for i = 1:size(total_elems,1)
    concatstr = '';
    for j = 1:size(total_elems,2)
        concatstr = [concatstr, num2str(total_elems(i,j))]; 
       
        if (length(concatstr) > 9 || ismember('0',concatstr))
            break;
        end
        %}
        if ((length(concatstr) == 9) && (length(unique(concatstr)) == 9))
            pandigit = [pandigit; total_elems(i,1), j, str2num(concatstr)];
        end
    end
end
pandigit
[mx,ix] = max(pandigit(:,3));
mx


%run through multiplying and concatenating
%compare the results