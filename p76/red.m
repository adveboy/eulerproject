function sum = red(N,m)
%red(100,99)
    sum = 0; 
    
    if (m == 1 || m == 0) 
        sum = 1;
    else
        for cnt = 1:m
            sum = sum + red(cnt, min(cnt, N - cnt));
        end
    end
    % disp(['N = ', num2str(N), ' m = ', num2str(m), ' sum = ', num2str(sum)]);
end
% current goal: solve that kind of tasks in 20 minutes