%-=-Week 4 tutorial CISC271-=-%

%{
This Tutorial Pretains to the Assignment 2 and how to train linear
regression and cross validation
%}

data = load("hw05.txt");                % A question that is asked very often 
                                        % in Linear Analysis is do we have to                                         
m = size(data, 2);                      % transpose a vector
A = [data(1,:)', ones(m,1)];
c = data(2,:)';

%-=-full regression and error-=-%
w = A\c; % this solves system of linear equation A*w = c

%-=-Leave one out: Observation #1-=-%
Av = A(1,:);
cv = c(1,:);
At = A(2:end,:); % gives all rows in A (and c below)
ct = c(2:end,:);

%-=-Train on the data-=-%
wt = At\ct                              % training on every entry accept the first 
                                        % (as At and ct start from row 2 in A and c)
%-=-Test the Results-=-%
ev = cv - Av*wt;
sqrt(sum(ev.^2)/length(ev))

%-=-Leave one out observation #2-=-%
Av = A(2,:);
cv = c(2,:);
At = A([1 3:end],:); % gives rows 1, 3-end
ct = c([1 3:end],:);

%-=-Train on data-=-%
wt = At\ct;

%-=-Test the results-=-%
cv = Av*wt;

%-=-Iterative method for doing the above calculations on a whole list-=-%
%-=-Repeat on #1 indexing-=-%
ix =  1;
Av = A(ix,:);
cv = c(ix,:);

%-=-Everything that preceeds ix-=-%
1:(ix-1)
%-=-Everything that follows ix-=-%
(ix - 1):m
%-=-Everything that isnt in ix-=-%
[ix:(ix-1) (ix + 1):m]

%-=-loop through frist 4 observations-=-%
elist = zeros(4,1);
for ix=1:4
    At = A([1:(ix-1) (ix + 1):m], :);
    ct = c([1:(ix-1) (ix + 1):m], :);
    Av = A(ix, :);
    cv = c(ix, :);

    %-=-Train on the data-=-%
    wt = At\ct;

    %-=-Put the test error in the list-=-%
    elist(ix) = cv - Av*wt;
end
disp(elist);

%-=-Study errors-=-%
disp(elist.^2); % .^2 is the 'hattamard product'. squares each entry of elist
sum(elist.^2)
sum(elist.^2)/length(elist)
sqrt(sum(elist.^2)/length(elist)); %this is the Root Mean Squared Error

%-=-MatLab function for finding the RootMeanSquared Error-=-%
rms(elist);

%-=-Train on m-2, test on 2; use index list-=-%

ilist = 1:m; % for indexing our indepndent readings
ix = 1; 
n = 1; % number of items to leave out - 1
kx = [ix:(ix+1)]; % set of data to reserve for validation, essenitally moving along list of independent redings in sets of length n + 1
tx = setdiff(ilist, kx); % gives the Set Difference of ilist of kx (everything on in kx)
At = A(tx, :);
ct = c(tx, :);
Av = A(kx, :);
cv = c(kx, :);
wt = At\ct;
cv - Av*wt
rms(cv - Av*wt) % we can use any of these as an answer for the assignment

