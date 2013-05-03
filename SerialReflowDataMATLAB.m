%% Serial Read and Plot of Arduino Reflow Data 
% KAAT INDUSTRIES
% Kavitha Prasanna, Alexa Choy, Tyler Hobbs, Adam Roth
% May 1, 2013

% Initialize the workspace
clear; clc;

% Close any open Serials
fclose(instrfind);

% Set up the Arduino Serial
s = serial('/dev/tty.usbmodemfa141')

% Open the Serial buffer and pause to allow user time to start Reflow
fopen(s); pause(25);

% Open the figure window and clear it
figure(1); clf;

% Initialize the while variables
d=0;
k=0;

while s.BytesAvailable >= 0
    d = fscanf(s,'%f %f %f');   % Read the data into variable, d
    d = d'                      % Transpose d
    if  d(1) ~= 0
        hold on
        plot(d(1),d(3),'k-')    % Plot the data
    end
end
fclose(s);  % Close the Serial buffer
