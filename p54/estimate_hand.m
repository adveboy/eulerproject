function [res,mx] = estimate_hand(p)
    order = {'2','3','4','5','6','7','8','9','10','J','Q','K','A'};
    nums = cell(1,5);
    mast = cell(1,5);
    for cnt = 1:5
        nums{cnt} = p{cnt}(1:end-1);
        mast{cnt} = p{cnt}(end);
    end

    ism = ismember(order,nums);
    res = '';
    if (all(strcmp(mast{1},mast)) && all(ism(end-4:end)))
        %Royal Flush
        res = 'Royal Flush';
        mx = find(strcmp('A',order));s
    else 
        if all(strcmp(mast{1},mast))
            %Straight Flush
            for cnt = 1:(length(ism) - 5)
               if all(ism(cnt:cnt+4))
                   res = 'Straight Flush';
                   mx = cnt + 4;
               end
            end
            if (strcmp(res, ''))
                res = 'Flush';
                mx = max(find(ismember(order, nums)));
            end
        else
            if ((sum(strcmp(nums{1}, nums)) == 4)|| (sum(strcmp(nums{2}, nums)) == 4))
                %Four of a Kind
                res = 'Four of a Kind';
                if (length(unique(nums)) == 2)
                    uq = unique(nums);
                    if (sum(strcmp(nums, uq{1})) == 4)
                        uqel = uq{1};
                    else
                        uqel = uq{2};
                    end
                    mx = find(strcmp(uqel, order));
                    elem = nums(find(~strcmp(uqel,nums)));
                    mx = [mx, find(strcmp(elem,order))];
                end
            else
                for cnt = 1:(length(ism) - 4)
                   if all(ism(cnt:cnt + 4)) 
                       res = 'Straight';
                       mx = cnt + 3;
                   end
                end
                if (~strcmp(res, 'Straight'))
                    uq = unique(nums);
                    threekind = false;
                    twokind = false;
                    for cnt = 1:length(uq)
                       if (sum(strcmp(uq{cnt}, nums)) == 3)
                           threekind = true;
                           res = 'Three of a Kind';
                           mx = find(strcmp(uq{cnt}, order));
                       elseif (sum(strcmp(uq{cnt}, nums)) == 2)
                           twokind = true;
                           twopos = find(strcmp(uq{cnt}, order));
                       end

                    end
                    if threekind && twokind 
                        res = 'Full House';
                        mx = [mx, twopos];
                    elseif threekind
                        res = 'Three of a Kind';
                    else
                        if (~strcmp(res, 'Three of a Kind'))
                           doublecount = 0; mx = []; tail = [];
                           for cnt = 1:length(uq)
                               if (sum(strcmp(uq{cnt}, nums)) == 2)
                                    doublecount = doublecount + 1;
                                    cardpos = find(strcmp(uq{cnt},order));
                                    mx = [mx cardpos];
                               else 
                                   tail = [tail, find(strcmp(uq{cnt},order))];
                               end
                           end 
                           if (doublecount == 1)
                               res = 'One Pair';
                               mx = [sort(mx,'descend'), sort(tail,'descend')];
                           elseif (doublecount >= 2)
                               res = 'Two Pairs';
                               mx = [sort(mx,'descend'), sort(tail,'descend')];
                           else
                               res = 'High Card';
                               mx = sort(find(ismember(order, uq)), 'descend');
                           end
                        end
                    end
                end
             end
        end
    end
