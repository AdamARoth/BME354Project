%% Stat Analysis of Arudino Oven Temperature Code
% Tyler Hobbs, Adam Roth, Alexa Choy, Kavitha Prasanna
% May 1, 2013

figure(1); clf;

A=[ % INSERT DATA HERE (3 COLUMNS)
    ];


%% Calculate the R squared
SSresid = sum((A(:,3) - A(:,2)).^2);
SStotal = sum((A(:,3) - mean(A(:,3))).^2);
r_2 = 1 - SSresid./SStotal

plot(A(:,1),A(:,2),'k-',A(:,1),A(:,3),'b-');
text(105,230,['R^2 = ',num2str(r_2)],'FontSize',16)
title('Temperature (C) vs. Time (s) for Reflow Run 6')
xlabel('Time (seconds)');
ylabel('Oven Temperature (Celsius)');
grid on;
legend('Set Temp. Data','Actual Temp. Data',0);
