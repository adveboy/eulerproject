function res = compare(p1, p2)
    res = 0;
    combinations = {'High Card','One Pair','Two Pairs','Three of a Kind','Straight','Flush','Full House','Four of a Kind','Straight Flush','Royal Flush'};
    [res1, mx1] = estimate_hand(p1) 
    [res2, mx2] = estimate_hand(p2)
    if (find(strcmp(res1,combinations)) > find(strcmp(res2,combinations)))
        res = 1;
    elseif (find(strcmp(res1,combinations)) < find(strcmp(res2,combinations)))
        res = 2;
    else
        if (~strcmp(res1,'High Card') && ~strcmp(res1,'One Pair'))
            a = 1;
        end
        for cnt = 1:length(mx1)
            if (mx1(cnt) > mx2(cnt))
                res = 1; break;
            elseif (mx1(cnt) < mx2(cnt))
                res = 2; break;
            end
        end
    end
end