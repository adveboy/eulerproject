maxS = 10000;
sqrs = (2:fix(sqrt(maxS))+1).^2;
cnt = 1;
oddcycle = 0;
for S = 2:maxS
    %S = 23;
    SS = sqrt(S);
    if (sqrs(cnt) == S)
        cnt = cnt + 1;
        continue;
    end
    mo = 0; do = 1; ao = fix(SS);
    hist = [ao do mo];
    found = false;
    while (~found)
        mn = do*ao - mo;
        dn = (S-mn*mn)/do;
        an = fix((SS+mn)/dn);
        [found, ix] = ismember([an dn mn], hist,'rows');
        hist = [hist; [an dn mn]];
        mo = mn; do = dn; ao = an;
    end
    dist = size(hist,1) - ix;
    if (mod(dist,2) == 1)
        oddcycle = oddcycle + 1;
    end
end
oddcycle