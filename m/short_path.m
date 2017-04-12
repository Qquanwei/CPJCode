% path: �������
% form: ��ʼ��
% to: ������
% ��������:
% G = zeros(5,5);
% G(1,3) = 4;
% G(1,2) = 2;
% G(1,4) = 3;
% G(2,3) = 1;
% G(2,4) = 2;
% G(3,6) = 7;
% G(4,5) = 4;
% G(6,5) = 1;
% G = G' + G;

function short = short_path(path,form,to)
    points = struct();
    for i = 1:size(path,1)
        % forword_short_path ������֪�����·��
        % already ����ýڵ��Ƿ��Ѿ��߹�(���⻷·)
        points(i) = struct('forword_short_path', inf,...
                           'already', false);
    end
    points(form).forword_short_path = 0;
    short = l_short_path(path,form,to, points);
end

function min_path = l_short_path(path,form,to,points)
    points(form).already = true;
    if form == to
        min_path = points(form).forword_short_path;
        return
    end
    len = length(points);
    if path(form, to) == 0
        for i = 1:len
            if path(form, i) ~=0
                points(i).forword_short_path = min(...
                        points(i).forword_short_path, ...
                        points(form).forword_short_path + path(form, i));
            end
        end
    else
        points(to).forword_short_path = min(...
            points(to).forword_short_path, ...
            points(form).forword_short_path + path(form, to));
    end
    minvalue = min( ...
        [points([points.already] == false).forword_short_path]);
    
    % �ҳ��������·��������
    
    min_short_paths = find((...
        [points.forword_short_path] == minvalue).*...
        ([points.already] == false) );
    min_path = min(arrayfun(@(form) l_short_path(path, form, to, points)...
        , min_short_paths));
end
