function quant = calc_vars(lng, height, nozero)
    if (height < 2)
        quant = 0;
    else
        vars = zeros(height,lng);
        if ~nozero
            vars(1,lng) = 1;
        end
        vars(2:end,lng) = 1;
        for j = lng-1:-1:1
            vars(1,j) = vars(2,j+1);
            vars(height,j) = vars(height-1,j+1);
            for i = 2:height-1
                vars(i,j) = vars(i-1,j+1) + vars(i+1,j+1);
            end
        end
        quant = sum(vars(:,1));
    end
end