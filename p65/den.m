function y = den(n, a)
    if (n == length(a))
        y = a(end);
    else
        y = den(n+1,a)*a(n) + nom(n+1,a);
    end
    %disp(['den(', num2str(n), ') = ', num2str(y)]);
end