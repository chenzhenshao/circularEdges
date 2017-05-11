%% For X (platform+kistler+cable)
mx = 9.241410334340282e-004;
cx = 0.001651705312519;

%% For Y (platform+kistler+cable)
cy = 0.001046707328795;
my = 5.572114462326005e-004;
% 
% %% Al platform only
% mx = 7.950913801404835e-004;
% cx = 0.001331957704959;
% my=2.721567156741477e-004;
% cy=0.001005491797519;

%% Circle
x=[-39.827; -157.874; -271.401; -187.914; -275.410];
y=[-212.137; -321.030; -235.368; -88.914; -216.377];
plot(x,y,'o'), title(' measured points');
[xc,yc,Re,a] = circfit(x,y);
th = linspace(0,2*pi,20)';
xe = Re*cos(th)+xc; ye = Re*sin(th)+yc;
plot(x,y,'o',[xe;xe(1)],[ye;ye(1)],'-.'),
title(' measured and fitted circles')
legend('measured','fitted')
text(xc,yc,sprintf('center (%g , %g );  R=%g',xc,yc,Re))
xlabel x, ylabel y 
axis equal

%% Other parameters
omegad=1.2;
alphad=0.6;
Ts=0.001;
%% Generate trajectory
center=[xc;yc];
rad=Re;
kNorm=1*10^-1;
rNormal=109.08;
[circX, circY, circXd,circYd, circXdd, circYdd]=genCircle(center,rad,Ts,omegad,alphad);
% circX=fliplr(circX);
% circY=fliplr(circY);
% circXd=fliplr(circXd);
% circYd=fliplr(circYd);
% circXdd=fliplr(circXdd);
% circYdd=fliplr(circYdd);
factor=1;
circX=circX(1:floor(length(circX)/factor));
circY=circY(1:floor(length(circY)/factor));
circXd=circXd(1:floor(length(circX)/factor));
circYd=circYd(1:floor(length(circY)/factor));
circXdd=circXdd(1:floor(length(circX)/factor));
circYdd=circYdd(1:floor(length(circY)/factor));
% circX=[circX, circX];
% circY=[circY, circY];
% circXd=[circXd, circXd];
% circYd=[circYd, circYd];
% circXdd=[circXdd, circXdd];
% circYdd=[circYdd, circYdd];
theta=atan2(circY,circX);
figure(2);
plot(theta);

for i=1:length(circX)
    radRef(i)=sqrt((circX(i))^2+(circY(i))^2);
end

r0=rad;
Kp=[8 0; 0 7]*10^-2;
Kd=[5 0;0 5]*10^-4;
M=[mx 0; 0 my];
Minv=inv(M);
Ks=[7 0;0 0.7]*10^-2;
Wcut = 150; bLP  = exp(-Wcut*2*pi*Ts);
slbuild('positionControlSlidingCircle');
% 
% 
% filenameRoot = 'refcheck';
% mean=1.76;
% % filename
% % k = 2;      % when the torque is %50 reduced.
% % filename = [filenameRoot,num2str(k)];
% filename=filenameRoot;
% 
% % open file
% load(filename);
% dataName = eval(filename);
% % dataName=n2_09pm;
% XExpData=dataName.Y(1).Data;
% YExpData=dataName.Y(2).Data;
% XExpRef=dataName.Y(6).Data;
% YExpRef=dataName.Y(7).Data;
% [xcExp,ycExp,ReExp,aExp] = circfit(XExpRef,YExpRef);
% 
% 
% for i=1:length(Xdata)
% %     theta(i)=atan2(Ydata(i)-yc, Xdata(i)-xc);
%     rad(i)=sqrt((XExpData(i)-xc)^2+(YExpData(i)-yc)^2);
%     rdes(i)=sqrt((XExpRef(i)-xcExp)^2+(YExpRef(i)-ycExp)^2);
% end
% 
% % plot(rad);
% figure();
% plot(rdes);
% hold on;
% plot(radRef,'r');