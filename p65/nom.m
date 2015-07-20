function y = nom(n, a)
    if (n == length(a))
        y = 1;
    elseif (n == 1)
        y = a(1)*den(2,a) + nom(2,a);
    else
        y = den(n+1,a);
    end
    %disp(['nom(', num2str(n), ') = ', num2str(y)]);
end