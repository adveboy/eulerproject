clear;
eps = 0.0001;
N = 12000;
nom1 = 1; den1 = 3;
nom2 = 1; den2 = 2;
noms = []; dens = 1:N;
prev = 0; %initialize with small one
ic = 0; jc = 1; quant = 0;
for i = 2:N
    range = ceil(i*nom1/den1 + eps):fix(i*nom2/den2 - eps);
    for j = range
        if (gcd(j,i) == 1) 
            quant = quant + 1;
        end
    end
    if ~mod(i,1000)
        i
    end
end
quant