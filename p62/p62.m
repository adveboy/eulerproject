m = containers.Map;
n = containers.Map;

num = 0;
while (true)
    cub = num^3;
    cubstr = sort(num2str(cub));
    if ~isKey(m, cubstr)
        m(cubstr) = 1;
        n(cubstr) = [cub];
    else
        m(cubstr) = m(cubstr) + 1;
        n(cubstr) = [n(cubstr), cub];
    end
    if (m(cubstr) == 5)
        break;
    end
    num = num + 1;
end
cubstr
fprintf('%.0f\n',n(cubstr))