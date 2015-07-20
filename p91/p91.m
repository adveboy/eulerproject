N=50;
triv = 3*N^2 + fix(N/2)*2;
for x1 = 1:N
    for x2 = 1:N
        for y1 = 1:N
            for y2 = 1:N
                if (x1 == x2 && y1 == y2)
                    continue;
                end
                if (x1^2 + y1^2 + (x1-x2)^2 + (y1-y2)^2 == x2^2 + y2^2)
                    triv = triv + 1;
                    %disp(['x1 = ', num2str(x1), '; y1 = ', num2str(y1), '; x2 = ', num2str(x2), '; y2 = ', num2str(y2)]);
                end
            end
        end
    end
end