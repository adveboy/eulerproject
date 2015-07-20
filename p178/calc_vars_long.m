function quant = calc_vars_long(height, lng)
    if (height < 2)
        quant = 0;
    else
        vars = cell(height,lng);
        for cnt = 1:size(vars,1)
            vars{cnt,lng} = 1;
        end
        for j = lng-1:-1:1
            vars{1,j} = vars{2,j+1};
            vars{height,j} = vars{height-1,j+1};
            for i = 2:height-1
                vars{i,j} = sumlong(vars{i-1,j+1}, vars{i+1,j+1});
            end
        end
        st = vars{1,1};
        for cnt = 2:size(vars,1)
           stold = st;
           st = sumlong(stold,vars{cnt,1});
        end
        quant = long_to_num(st);
    end
end