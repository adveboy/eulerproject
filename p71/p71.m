clear;
eps = 0.0001;
N = 1000000;
nom = 3; den = 7;
noms = []; dens = 1:N;
prev = 0; %initialize with small one
ic = 0; jc = 1;
for i = den:N
    start_nom = fix(3*i/7 - eps);
    for j = start_nom:-1:1
        if (gcd(j,i) == 1) 
            if (j/i > prev)
                ic = i; jc = j;
                prev = j/i;
            end
            break; 
        end
    end
    if ~mod(i,10000)
        i
    end
end
ic 
jc