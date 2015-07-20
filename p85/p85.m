N = 2*10^6;
a = 4*N;
H = 1; mn = 100000;
while (true)
    P = H*H+H;
    D = P*P+4*a*P;
    W = (sqrt(D)-P)/(2*P);
    Wl = fix(W); Wr = ceil(W);
    if (Wr == 1)
        break;
    end
    N1 = num_of_rect(Wl,H); N2 = num_of_rect(Wr,H);
    df = [2e6 - N1, N2 - 2e6];
    W = [Wl,Wr];
    [cur_mn, ix] = min([2e6 - N1, N2 - 2e6]);
    
    if (cur_mn < mn)
        mn = cur_mn; Wm = W(ix); Hm = H;
    end
    disp(['2e6-N1 = ', num2str(2e6 - N1)]);
    disp(['N2-2e6 = ', num2str(N2 - 2e6)]);
    H = H + 1;
end
Hm*Wm