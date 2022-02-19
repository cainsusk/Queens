%{
A = load("20cjbs.txt");

rng('shuffle');

C = A*randi(10,4,6);

[U, S, V] = svd(C)

% We can see that the nullspace is in V where the corresponding colmns in S
% are 0. 

disp('the nullspace of C is:')
disp(V(:, end-1:end)) % this is hardcoded as the matrix always has the same dimensions
%}





%{
data = readtable('goods.csv');
A = data{:, 2:end};
c = datenum(data{:, 1});
[m, n] = size(A);

k = 3;
rI = randperm(n, n);                                    % set of randomized indices
tI = floor(m/k);                                        % set of test indices

rmstrain = zeros(1, k);                                 % init return vars
rmstest  = zeros(1, k);

prev = 0;
foldSize = floor(n/k);

for q=1:k                                                 
        if q == k
            X = A(:, foldSize*q : end);
        else
            X = A(:, prev+1 : foldSize*q);
        end
        
        %-=-Train and Validate-=-%
        Xt = X(tI+1:m, :);                                  % training data
        ct = c(tI+1:m, :);
    
        Xv = X(1:tI, :);                                    % validation data
        cv = c(1:tI, :);
    
        w = Xt\ct;                                          % generate model w                         

        %-=-Return variables-=-%
        rmstrain(q) = rms(ct - (Xt*w));                     % accumulate errors into return vars
        rmstest(q)  = rms(cv - (Xv*w));
end

disp(rmstrain)
disp(rmstest)
%}

%{
A = load("20cjbs.txt");
[U, S, V] = svd(A);

B = U*V'
C = V*S*V'
%}

data = readtable('goods.csv');
    A = data{:, 2:end};                                      % init A with correct range of data
    [m, n] = size(A);                                        % size of A
    

    %-=-Stdize data using Zscore-=-%
    Z = zeros(m,n);                                         % matrix of Zscores for A
    for c = 1:n
        a = A(:, c);
        aBar = mean(a);
        zeroMean = a - ones(m, 1)*aBar;
        sigma = sqrt(norm(zeroMean)^2 / m-1);               % sqrt([||va-v1*aBar||^2]/[m-1]);
        zScore = zeroMean / sigma;
        Z(:, c) = zScore;
    end


    %-=-find y (bcos standard) with lowest RMSE-=-%
    RMSE = zeros(1,n);
    for k = 1:n
        y = Z(:, k);
        X = Z(:, setdiff(1:n, k));                          % gets all vectots accept the one at k in Z                    
        u = X\y;                                            % compute weight vector
 
        RMSE(1, k) = rms(y - X*u);
    end
    [minRMSE, minRMSEindex] = max(RMSE);


    %-=-Compute regression w/ lowest RMSE-=-%
    y = Z(:, minRMSEindex);             
    X = Z(:, setdiff(1:n, minRMSEindex));
    u = X\y;                                                % compute final regression
    

    %-=-Plot results of final regression-=-%
    plot(X*u);


    %-=-Return Final Values-=-%
    rmsvars = minRMSE
    lowndx  = minRMSEindex
