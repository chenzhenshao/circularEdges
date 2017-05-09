%% Fucntion to generate circle
function [circX, circY, circXd,circYd, circXdd, circYdd]=genCircle(center,rad,Ts,omegades, alphades)
%center=[x1,y1] rad=radius (all in mm)
% T=2*pi/thetad;
% t=(0:Ts:T);
% theta=t/T*2*pi;
% 
% circX=center(1)+rad*cos(theta);
% circY=center(2)+rad*sin(theta);
% 
% 
% for i=1:length(circX)-1
%     circXd(i,1)=(circX(i+1)-circX(i))/(t(i+1)-t(i));
%     circYd(i,1)=(circY(i+1)-circY(i))/(t(i+1)-t(i));
% end
% circXd(i+1,1)=circXd(i);
% circYd(i+1,1)=circYd(i);
% 
% for i=1:length(circXd)-1
%     circXdd(i,1)=(circXd(i+1)-circXd(i))/(t(i+1)-t(i));
%     circYdd(i,1)=(circYd(i+1)-circYd(i))/(t(i+1)-t(i));
% end
% circXdd(i+1)=circXd(i);
% circYdd(i+1)=circYd(i);
offset=pi;
t1=omegades/alphades;
theta1=1/2*alphades*t1^2;
t2=(2*pi-2*theta1)/omegades+t1;
theta2=theta1+omegades*(t2-t1);
t3=t2+t1;
T=(0:Ts:t3);
i=1;
while T(i)<=t1
    theta(i)=1/2*alphades*T(i)^2+pi;
    thetad(i)=alphades*T(i);
    thetadd(i)=alphades;
    
    circX(i)=center(1)+rad*cos(theta(i));
    circY(i)=center(2)+rad*sin(theta(i));
    circXd(i)=rad*thetad(i)*cos(theta(i)+pi/2);
    circYd(i)=rad*thetad(i)*sin(theta(i)+pi/2);
    circXdd(i)=rad*thetadd(i)*cos(theta(i)+pi/2);
    circYdd(i)=rad*thetadd(i)*sin(theta(i)+pi/2);
    i=i+1;
end
while T(i)<=t2
    theta(i)=theta1+omegades*(T(i)-t1)+pi;
    thetad(i)=omegades;
    thetadd(i)=0;
    
    circX(i)=center(1)+rad*cos(theta(i));
    circY(i)=center(2)+rad*sin(theta(i));
    circXd(i)=rad*thetad(i)*cos(theta(i)+pi/2);
    circYd(i)=rad*thetad(i)*sin(theta(i)+pi/2);
    circXdd(i)=rad*thetadd(i)*cos(theta(i)+pi/2);
    circYdd(i)=rad*thetadd(i)*sin(theta(i)+pi/2);
    i=i+1;
end
while i<=length(T) && T(i)<=t3
    theta(i)=theta2+omegades*(T(i)-t2)-1/2*alphades*(T(i)-t2)^2+pi;
    thetad(i)=omegades-alphades*(T(i)-t2);
    thetadd(i)=-alphades;
    
    circX(i)=center(1)+rad*cos(theta(i));
    circY(i)=center(2)+rad*sin(theta(i));
    circXd(i)=rad*thetad(i)*cos(theta(i)+pi/2);
    circYd(i)=rad*thetad(i)*sin(theta(i)+pi/2);
    circXdd(i)=rad*thetadd(i)*cos(theta(i)+pi/2);
    circYdd(i)=rad*thetadd(i)*sin(theta(i)+pi/2);
    i=i+1;
end
thetadd(end)=0;