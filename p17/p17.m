f1 = {'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', ...
'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen'};
f2 = {'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety'};
sm = 0;
for n = 1:1000
    wrd = '';
    if (n == 1000)
        wrd = 'onethousand';
    else
        huns = fix(n/100);
        rmnd = mod(n,100);
        if (huns >= 1)
            wrd = [wrd, f1{huns}, 'hundred'];
        end
        if (huns > 0 && rmnd > 0)
            wrd = [wrd, 'and'];
        end
        if (rmnd > 0)
            tens  = fix(rmnd/10);
            if rmnd <= 19
                wrd = [wrd, f1{rmnd}];
            else
                wrd = [wrd, f2{tens-1}];
                cyps = mod(rmnd,10);
                if cyps
                    wrd = [wrd, f1{cyps}];
                end
            end
        end
    end
    sm = sm + length(wrd);
end
sm
%{
if (huns == 1)
            wrd = [wrd, 'onehundred'];
        else
%}