%% Process data
clear all;
% close all;

% choose file %

filenameRoot = 'spindleon_2_55pm';
mean=1.76;
% filename
% k = 2;      % when the torque is %50 reduced.
% filename = [filenameRoot,num2str(k)];
filename=filenameRoot;

% open file
load(filename);
dataName = eval(filename);
% dataName=n2_09pm;
Xdata=dataName.Y(1).Data;
Ydata=dataName.Y(2).Data;
[xc,yc,Re,a] = circfit(Xdata,Ydata);


for i=1:length(Xdata)
    theta(i)=atan2(Ydata(i)-yc, Xdata(i)-xc);
end

figure(1);
plot(theta,dataName.Y(3).Data-mean);
figure(2);
plot(dataName.Y(3).Data-mean);
a = 1;
b = ones(1,20)/20;
y = filter(b,a,dataName.Y(3).Data-mean);
figure(3)
plot(theta,y);