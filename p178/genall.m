function combs = genall(N,lng, startzero)
    combs = [];
    if startzero 
        start = 0;
    else
        start = 1;
    end
    
    for cnt = start:N-1
        %generate_nums(N,cnt,lng)
        combs = [combs; generate_nums(N,cnt,lng)];
    end
end