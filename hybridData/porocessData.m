%% Process data
clear all;
close all;

% choose file %
filenameRoot = 'data5_1_5_31pmspindleon5n';
% filename
% k = 2;      % when the torque is %50 reduced.
% filename = [filenameRoot,num2str(k)];
filename=filenameRoot;

% open file
load(filename);
dataName = eval(filename);
plot(dataName.Y(3).Data);

a = 1;
b = ones(1,20)/20;
y = filter(b,a,dataName.Y(3).Data);
figure()
plot(y);