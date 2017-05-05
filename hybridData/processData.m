%% Process data
clear all;
% close all;

% choose file %

filenameRoot = 'data5_4_2_22pmspindleon10noffsetpi';

% filename
% k = 2;      % when the torque is %50 reduced.
% filename = [filenameRoot,num2str(k)];
filename=filenameRoot;

% open file
load(filename);
dataName = eval(filename);
Xdata=dataName.Y(1).Data;
Ydata=dataName.Y(2).Data;
[xc,yc,Re,a] = circfit(Xdata,Ydata);


for i=1:length(Xdata)
    theta(i)=atan2(Ydata(i)-yc, Xdata(i)-xc)+pi;
end

figure();
plot(theta,dataName.Y(3).Data-1.76);
figure();
plot(dataName.Y(3).Data-1.76);
a = 1;
b = ones(1,20)/20;
y = filter(b,a,dataName.Y(3).Data);
figure()
plot(theta(1:4000),y(1:4000)-1.76);