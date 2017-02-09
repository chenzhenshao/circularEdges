%% Run this script
%% For Y axis 
%inertia and damping values for unloaded platform
% %% For X (just platform)
% Jx = 7.410077248673616e-004;
% Bx = 0.001519494650341;
% %% For Y (just platform)
% Jy =2.182095285417511e-004;
% By =0.001127491288018;

% %% For X (cylinder+kistler)
% Jx = 9.507954388690071e-004;
% Bx = 0.001536455429262;
% %% For Y (cylinder+kistler)
% By = 8.650956610113620e-004;
% Jy = 5.706428319276779e-004;

%% For X (cylinder+kistler+cable)
Jx = 9.170930148991473e-004;
Bx = 0.002015920056936;
%% For Y (cylinder+kistler)
By = 8.925446348616319e-004;
Jy = 5.701918282653577e-004;

%% Circle
y=[-183.729;-94.660;-81.150;-160.970;-304.867;-316.914];
x=[-160.223;-222.451;-284.407;-389.623;-327.640;-277.457];
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
thetad=0.25;
Ts=0.01;
zeta=0.8;
%% Generate trajectory
center=[xc;yc];
rad=Re-5;
[circXt, circYt]=genCircle(center,rad,Ts,thetad);
circX=circXt(1:floor(length(circXt)));
circY=circYt(1:floor(length(circYt)));
theta=atan2(circY-yc,circX-xc);
figure(2);
plot(theta);

%% Build
slbuild('positionControlLoopCircle')  