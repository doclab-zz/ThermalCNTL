%
% Simulation of temp control. This simulation shows the inrease and
% decrease in current when the algorithm attemps to maintain the set temp 
%

%%
global measuredTemp coilCurrent timeTick setTemp maxCount mitgationCase
maxCount =150;
for count = 0:1:maxCount
timeTick = timeTick +1;
%coilCurrent = 4;
%function  my_callback_fcn (obj, event, string_arg)
f=find(targetCurrentValues == coilCurrent);
%if(f)
 setCoilCurrent = targetCurrentValues (f) ;
 %fprintf('f before the CNTL =%f  ', f);
%end
 if (measuredTemp >= setTemp + mitActionDecTemp)
   %Reduce current in the coil
    if(f > 1)
    f = f-1;
    end
    setCoilCurrent = targetCurrentValues (f);
    coilCurrent = setCoilCurrent;
    measuredTemp = measuredTemp - rand();  
    mitgationCase = 1;
 end
 
 if (measuredTemp <= setTemp + mitActionDecTemp)
     if (f <=18)
     f =f+1;
     end
     setCoilCurrent = targetCurrentValues (f);
     coilCurrent = setCoilCurrent;
     measuredTemp = measuredTemp + rand(); 
     mitgationCase = 2;
 end
 
fprintf('measuredTemp =%f ', measuredTemp);
fprintf('coilCurrent =%f  ', coilCurrent);
fprintf('f =%f ', f);
fprintf('setCoilCurrent =%f ', setCoilCurrent);
fprintf('setTemp =%f ', setTemp);
fprintf('timeTick =%f \n', timeTick)
x_data = [];  % coilCurrent;
y_data = []; % measuredTemp;

hold on;

p= plot(timeTick, coilCurrent, timeTick, setTemp,timeTick, measuredTemp );
set(p,'LineWidth',2,{'LineStyle'},{'--';':';'-.'})
set(p,{'Marker'},{'*';'+';'x' })
if(mitgationCase == 1) % measured Temp >= set Temp 
 set(p,{'Color'},{'r';'g';'b'})
else                   % measured Temp <= set Temp 
 set(p,{'Color'},{'k';'c';'m'})
end


axis([0 maxCount 0 9] , [0 maxCount 0 20], [0 maxCount 0 80])
grid on
xlabel('Time Ticks')
ylabel('RED->coilcurrent  GREEN->setTemp  BLUE->simulatedMeasuredTemp ')
legend(p,'coilCurrent','setTemp','measuredTemp')
title('Simulated TempCNTL Algorithm')
% p1= plot(timeTick, measuredTemp);
% set(p,'Color','red','LineWidth',21);
% set(p1,'Color','blue','LineWidth',100);
end
%%
