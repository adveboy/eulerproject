N = 50;
comb = 0;
for x1 = 0:N
    for x2 = 0:N
        if (x1 == 0 && x2 == 0)
            continue;
        end
        for y1 = 0:N
            for y2 = 0:N
                if (y1 == 0 && y2 == 0)
                    continue;
                end
                if (x1 == x2 && y1 == y2)
                    continue;
                end
                if (x1^2 + y1^2 + (x1-x2)^2 + (y1-y2)^2 == x2^2 + y2^2)
                    comb = comb + 1;
                    %disp(['x1 = ', num2str(x1), '; y1 = ', num2str(y1), '; x2 = ', num2str(x2), '; y2 = ', num2str(y2)]);
                end
            end
        end
    end
end
comb