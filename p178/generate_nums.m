function res = generate_nums(N,p,lng)
    res = [];
    if (lng == 1)
        res = p;
    else 
        if (p == 0)
            addpart = generate_nums(N,1,lng-1);
            res = [repmat(0,size(addpart,1),1), addpart];
        elseif (p == N-1)
            addpart = generate_nums(N,N-2,lng-1);
            res = [repmat(N-1,size(addpart,1),1), generate_nums(N,N-2,lng-1)];
        else
            addpart1 = generate_nums(N,p-1,lng-1);
            addpart2 = generate_nums(N,p+1,lng-1);
            res = [repmat(p,size(addpart1,1) + size(addpart2,1),1), [addpart1; addpart2]];
        end
    end
end