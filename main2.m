%% For X (platform+kistler+cable)
mx = 9.308173736838939e-004;
cx = 0.001654915051622;

%% For Y (platform+kistler+cable)
cy = 0.001043902893075;
my = 5.626343735815107e-004;

%% Circle
x=[-202.599; -223.790; -223.816; -283.937; -361.340; -312.786; -432.392; -329.119; -205.090; -203.733]-1.140;
y=[-181.700; -248.623; -248.672; -292.472; -289.565; -297.657; -206.463; -65.055; -205.132; -173.720]-0.193;
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
omegad=0.5;
alphad=0.25;
Ts=0.001;
%% Generate trajectory
center=[xc;yc];
rad=Re;
[circX, circY, circXd,circYd, circXdd, circYdd]=genCircle(center,rad,Ts,omegad,alphad);
factor=1;
circX=circX(1:floor(length(circX)/factor));
circY=circY(1:floor(length(circY)/factor));
circXd=circXd(1:floor(length(circX)/factor));
circYd=circYd(1:floor(length(circY)/factor));
circXdd=circXdd(1:floor(length(circX)/factor));
circYdd=circYdd(1:floor(length(circY)/factor));
theta=atan2(circY-yc,circX-xc);
figure(2);
plot(theta);

r0=Re;
Kp=[5 0; 0 5]*10^-2;
Kd=[5 0;0 5]*10^-4;
M=[mx 0; 0 my];
Minv=inv(M);
Ks=[1 0;0 0.1]*10^-2;
Wcut = 150; bLP  = exp(-Wcut*2*pi*Ts);
slbuild('positionControlSlidingCircle');