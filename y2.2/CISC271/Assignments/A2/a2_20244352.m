function [rmsvars, lowndx, rmstrain, rmstest] = a2_00000000
% [RMSVARS LOWNDX RMSTRAIN RMSTEST]=A3 finds the RMS errors of
% linear regression of the data in the file "GOODS.CSV" by treating
% each column as a vector of dependent observations, using the other
% columns of the data as observations of independent varaibles. The
% individual RMS errors are returned in RMSVARS and the index of the
% smallest RMS error is returned in LOWNDX. For the variable that is
% best explained by the other variables, a 5-fold cross validation is
% computed. The RMS errors for the training of each fold are returned
% in RMSTEST and the RMS errors for the testing of each fold are
% returned in RMSTEST.
%
% INPUTS:
%         none
% OUTPUTS:
%         RMSVARS  - 1xN array of RMS errors of linear regression
%         LOWNDX   - integer scalar, index into RMSVALS
%         RMSTRAIN - 1x5 array of RMS errors for 5-fold training
%         RMSTEST  - 1x5 array of RMS errors for 5-fold testing

    filename = 'goods.csv';
    [rmsvars, lowndx] = a2q1(filename);
    [rmstrain, rmstest] = a2q2(filename, lowndx)

end

function [rmsvars, lowndx] = a2q1(filename)
% [RMSVARS LOWNDX]=A2Q1(FILENAME) finds the RMS errors of
% linear regression of the data in the file FILENAME by treating
% each column as a vector of dependent observations, using the other
% columns of the data as observations of independent varaibles. The
% individual RMS errors are returned in RMSVARS and the index of the
% smallest RMS error is returned in LOWNDX. 
%
% INPUTS:
%         FILENAME - character string, name of file to be processed;
%                    assume that the first row describes the data variables
% OUTPUTS:
%         RMSVARS  - 1xN array of RMS errors of linear regression
%         LOWNDX   - integer scalar, index into RMSVALS

    format bank
    %-=-Read the test data & find size-=-%
    data = readtable(filename);
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
    [minRMSE, minRMSEindex] = min(RMSE);


    %-=-Compute regression w/ lowest RMSE-=-%
    y = Z(:, minRMSEindex);             
    X = Z(:, setdiff(1:n, minRMSEindex));
    u = X\y;                                                % compute final regression
    

    %-=-Plot results of final regression-=-%
    plot(X*u);


    %-=-Return Final Values-=-%
    rmsvars = minRMSE;
    lowndx  = minRMSEindex;

end
function [rmstrain, rmstest] = a2q2(filename,lowndx)
% [RMSTRAIN RMSTEST]=A3Q2(LOWNDX) finds the RMS errors of 5-fold
% cross-validation for the variable LOWNDX of the data in the file
% FILENAME. The RMS errors for the training of each fold are returned
% in RMSTEST and the RMS errors for the testing of each fold are
% returned in RMSTEST.
%
% INPUTS:
%         FILENAME - character string, name of file to be processed;
%                    assume that the first row describes the data variables
%         LOWNDX   - integer scalar, index into the data
% OUTPUTS:
%         RMSTRAIN - 1x5 array of RMS errors for 5-fold training
%         RMSTEST  - 1x5 array of RMS errors for 5-fold testing

    %-=-Read and get sizeof data-=-%
    data = readtable(filename);
    B = data{:, 2:end};             
    [~, n] = size(B);


    %-=-Init A and c (bcos non-standardized)-=-%
    c = B(:, lowndx);
    A = B(:, setdiff(1:n, lowndx));
    [m, n] = size(A);


    %-=-Compute Regression using 5fold validation-=-%
    k = 5;
    rI = randperm(n, n);                                    % set of randomized indices
    tI = floor(m/k);                                        % set of test indices
    
    rmstrain = zeros(1, k);                                 % init return vars
    rmstest  = zeros(1, k);

    prev = 0;
    foldSize = floor(n/k);
    
    %-=-Partition A into k 'folds'-=-%
    for q=1:k                                               % iterate through rI to assign a subset of the elemets  
        if q == k % final case                              % of A to X 
            X = A(:, rI(:, prev+1 : n));
        else % general case
            X = A(:, rI(:, prev+1 : q*foldSize));
            prev = q*foldSize;
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
end
