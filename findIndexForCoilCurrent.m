function returnIndexValue = findIndexForCoilCurrent(coilCurrent)
%for s=1:1:19
% if(targetCurrentDecValues (s) == coilCurrent)
%  disp(s);
%  returnIndexValue = s;
% end
%end
%
 returnIndexValue = find(targetCurrentDecValues == coilCurrent)
