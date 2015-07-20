%{
    order = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
    combinations = {'High Card','One Pair','Two Pairs','Three of a Kind','Straight','Flush','Full House','Four of a Kind','Straight Flush','Royal Flush'};
%}

fid = fopen('p054_poker.txt');
cards = [];
tline = fgetl(fid);
while ischar(tline)
    strsp = strread(tline, '%s', 'delimiter', ' ');
    cards = [cards; strsp'];
    tline = fgetl(fid);
end
% [p1, p2] = parse()
p1 = cards(:,1:5);
p2 = cards(:,6:10);
res = [];
handvalue = cell(size(cards,1), 1);
for cnt = 1:size(cards,1)
    p1(cnt,:)
    [rs,mx] = estimate_hand(p1(cnt,:));
    handvalue{cnt} = rs;
    res = [res; compare(p1(cnt,:), p2(cnt,:))];
end
sum(res == 1)
%p = { '10C', 'JC', 'QC', 'KC', 'AC'}; %Royal Flush
%p = { '9C', '10C', 'JC', 'QC', 'KC'}; %Straight Flush
%p = { '10C', '10S', '10H', '10D', 'QC'}; %Four of a Kind
%p = { '10C', '10S', '10H', '2D', '2C'}; %Full House
%p = { '2C', '9C', '3C', 'JC', 'QC'}; %Flush
%p = { '9C', '10S', 'JS', 'QH', 'KC'}; %Straight
%p = { '9C', '9S', '10S', '9H', 'QC'}; %Three of a Kind
%p = { '9C', '9S', '10S', '10H', 'QC'}; %Two Pairs
%p = { '9C', '9S', '2S', '10H', 'QC'}; %One Pair
%p = { '9C', '10S', '2S', '5H', 'QC'}; %High Card

%p1 = {'5H', '5C', '6S', '7S', 'KD'}; p2 = {'2C', '3S', '8S', '8D', 'TD'};
%p1 = {'5D', '8C', '9S', 'JS', 'AC'}; p2 = {'2C', '5C', '7D', '8S', 'QH'};
%p1 = {'2D', '9C', 'AS', 'AH', 'AC'}; p2 = {'3D', '6D', '7D', 'TD', 'QD'};
%p1 = {'4D', '6S', '9H', 'QH', 'QC'}; p2 = {'3D', '6D', '7H', 'QD', 'QS'};
%p1 = {'2H', '2D', '4C', '4D', '4S'}; p2 = {'3C', '3D', '3S', '9S', '9D'};


%[res, mx] = estimate_hand(p)

