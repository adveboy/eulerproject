%generate a 
%a = [1 2 2 2 2 2 2 2 2 2];
a = [2];
for cnt = 1:99
    if mod(cnt,3) == 2
        a = [a 2*(fix(cnt/3)+1)];
    else
        a = [a 1];
    end
end
%a
%calculate nom
%nom(1, a)

apro = a; %[1 2 2 2 2 2 2 2 2]; 
nom_hist = [apro(1)];
den_hist = [1];
for tail = 2:length(apro)
    a = apro(1:tail);
    nom = 1; den = a(end);
    for cnt = (length(a)-1):-1:2
        nom_old = nom;
        nom = den;
        den = den*a(cnt) + nom_old;

    end
    nom = a(1)*den + nom;
    nom_hist = [nom_hist, nom];
    den_hist = [den_hist den];
end
disp('nom_hist = ');
disp(nom_hist);
% fprintf('%.0f\n',nom)
% disp(['nom_hist = ', num2str(nom_hist,1)]);
% fprintf('%.0f ', nom_hist);
% disp(['den_hist = ', den_hist]);
sm = 0;
dv = [];
nomnom = nom;
tstr = num2str(nomnom);
tstr(tstr == '0') = []

cyph = [];
for cnt=1:length(tstr)
    cyph = [cyph, str2num(tstr(cnt))];
end
fprintf('number is %.0f\n', nom);
fprintf('cypher sum is %.0f\n', sum(cyph));


