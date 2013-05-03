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
fopen(s); pause(15);

% Open the figure window and clear it
figure(1); clf;

% Initialize the while variables
d=0;
k=0;
A=0;
while s.BytesAvailable >= 0
    d = fscanf(s,'%f %f %f');   % Read the data into variable, d
    d = d'                      % Transpose d
    if  d(1) ~= 0
        k = k + 1;
        A(k,[1 2 3]) = d;
        
        hold on
        plot(d(1),d(3),'k-');    % Plot the data
        plot(d(1),d(2),'b-');    % Plot the set Temp data
        title('Temperature (C) vs. Time (s) for Reflow Run');
        xlabel('Time (seconds)');
        ylabel('Oven Temperature (Celsius)')
        grid on;
        legend('Actual Temp. Data','Set Temp. Data',0)
    end
end

%% Calculate the R squared
SSresid = sum((A(:,3) - A(:,2)).^2);
SStotal = sum((A(:,3) - mean(A(:,3))).^2);
r_2 = 1 - SSresid./SStotal

text(105,230,['R^2 = ',num2str(r_2)],'FontSize',16)

fclose(s);  % Close the Serial buffer
