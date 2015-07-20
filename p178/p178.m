N = 10; lng = 11;

%res = calc_vars_long(lng,N) - 2*calc_vars_long(lng-1,N) + calc_vars_long(lng-2,N);
%fprintf('%d\n', res);
res = 0;
for lng = 40:-1:10
    res = res + calc_vars(lng,N,1) - calc_vars(lng,N-1,1) - calc_vars(lng,N-1,0) + calc_vars(lng,N-2,0);
end
fprintf('%d\n', res);
%let's printout the numbers

%{
combs = genall(N,lng,0);
combs1 = genall(N-1,lng,0);
combs2 = genall(N-1,lng,1) + 1;
combs3 = genall(N-2,lng,1) + 1;

finres = combs(~(ismember(combs,combs1,'rows') | ismember(combs,combs2,'rows')),:);
size(finres,1)
res
%}