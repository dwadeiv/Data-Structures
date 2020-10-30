clear all;
clc;
xQuadmin = 0; xQuadmax = 400; yQuadmin = 0; yQuadmax = 300;
xLLmin = 0; xLLmax = 400; yLLmin = 0; yLLmax = 150;
xSummin = 0; xSummax = 400; ySummin = 0; ySummax = 1000;

% DatasetA
DATA_A_file = csvread('DatasetA.csv'); % Read the data
LL_A_file = fopen('LL_DataA.csv');
BST_A_file = fopen('BST_DataA.csv');
HTC_A_file = fopen('HTC_DataA.csv');
HTL_A_file = fopen('HTL_DataA.csv');
HTQ_A_file = fopen('HTQ_DataA.csv');
% DatasetB
DATA_B_file = csvread('DatasetB.csv'); % Read the data
LL_B_file = fopen('LL_DataB.csv');
BST_B_file = fopen('BST_DataB.csv');
HTC_B_file = fopen('HTC_DataB.csv');
HTL_B_file = fopen('HTL_DataB.csv');
HTQ_B_file = fopen('HTQ_DataB.csv');

% Read in files for DatasetA
read_LL_A_Data = textscan(LL_A_file, '%f %f', 'Delimiter', ',');
read_BST_A_Data = textscan(BST_A_file, '%f %f', 'Delimiter', ',');
read_HTC_A_Data = textscan(HTC_A_file, '%f %f %f', 'Delimiter', ',');
read_HTL_A_Data = textscan(HTL_A_file, '%f %f %f', 'Delimiter', ',');
read_HTQ_A_Data = textscan(HTQ_A_file, '%f %f %f', 'Delimiter', ',');
% Read in files for DatasetB
read_LL_B_Data = textscan(LL_B_file, '%f %f', 'Delimiter', ',');
read_BST_B_Data = textscan(BST_B_file, '%f %f', 'Delimiter', ',');
read_HTC_B_Data = textscan(HTC_B_file, '%f %f %f', 'Delimiter', ',');
read_HTL_B_Data = textscan(HTL_B_file, '%f %f %f', 'Delimiter', ',');
read_HTQ_B_Data = textscan(HTQ_B_file, '%f %f %f', 'Delimiter', ',');

% Various X data
Index = 0:39999;
Iterations = 0:399;

% Y data for LL
LLinsertA = read_LL_A_Data{1,1}(:,1);
LLsearchA = read_LL_A_Data{1,2}(:,1);
LLinsertB = read_LL_B_Data{1,1}(:,1);
LLsearchB = read_LL_B_Data{1,2}(:,1);
% Y data for BST
BSTinsertA = read_BST_A_Data{1,1}(:,1);
BSTsearchA = read_BST_A_Data{1,2}(:,1);
BSTinsertB = read_BST_B_Data{1,1}(:,1);
BSTsearchB = read_BST_B_Data{1,2}(:,1);
% Y data for HTC
HTCinsertA = read_HTC_A_Data{1,1}(:,1);
HTCsearchA = read_HTC_A_Data{1,2}(:,1);
HTCcollisionsA = read_HTC_A_Data{1,3}(:,1);
HTCinsertB = read_HTC_B_Data{1,1}(:,1);
HTCsearchB = read_HTC_B_Data{1,2}(:,1);
HTCcollisionsB = read_HTC_B_Data{1,3}(:,1);
% Y data for HTL
HTLinsertA = read_HTL_A_Data{1,1}(:,1);
HTLsearchA = read_HTL_A_Data{1,2}(:,1);
HTLcollisionsA = read_HTL_A_Data{1,3}(:,1);
HTLinsertB = read_HTL_B_Data{1,1}(:,1);
HTLsearchB = read_HTL_B_Data{1,2}(:,1);
HTLcollisionsB = read_HTL_B_Data{1,3}(:,1);
% Y data for HTQ
HTQinsertA = read_HTQ_A_Data{1,1}(:,1);
HTQsearchA = read_HTQ_A_Data{1,2}(:,1);
HTQcollisionsA = read_HTQ_A_Data{1,3}(:,1);
HTQinsertB = read_HTQ_B_Data{1,1}(:,1);
HTQsearchB = read_HTQ_B_Data{1,2}(:,1);
HTQcollisionsB = read_HTQ_B_Data{1,3}(:,1);

% Hash Table averages
avg_HTC_insertA = mean(HTCinsertA);
avg_HTC_searchA = mean(HTCsearchA);
avg_HTC_insertB = mean(HTCinsertB);
avg_HTC_searchB = mean(HTCsearchB);
avg_HTL_insertA = mean(HTLinsertA);
avg_HTL_searchA = mean(HTLsearchA);
avg_HTL_insertB = mean(HTLinsertB);
avg_HTL_searchB = mean(HTLsearchB);
avg_HTQ_insertA = mean(HTQinsertA);
avg_HTQ_searchA = mean(HTQsearchA);
avg_HTQ_insertB = mean(HTQinsertB);
avg_HTQ_searchB = mean(HTQsearchB);

% DatasetA vs DatasetB
f1 = figure(1);
cla; hold on; grid on;
plot(Index, DATA_A_file, 'b-');
plot(Index, DATA_B_file, 'r-');

xlabel('Indices','Interpreter','latex')
ylabel('Values','Interpreter','latex')
title('DatasetA vs DatasetB','Interpreter','latex')
legend('Dataset A', 'Dataset B')

saveas(gcf,'DatasetA_vs_DatasetB.pdf');

% Linked List Effieceny Plots
f2 = figure(2);
subplot(2, 1, 1);
cla; hold on; grid on;
axis([xLLmin xLLmax yLLmin yLLmax])
plot(Iterations, LLinsertA, 'b-','LineWidth',0.75);
plot(Iterations, LLsearchA, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (microseconds)','Interpreter','latex')
title('Linked List Efficency of DatasetA','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

subplot(2, 1, 2);
hold on; grid on; 
axis([xLLmin xLLmax yLLmin yLLmax])
plot(Iterations, LLinsertB, 'b-','LineWidth',0.75);
plot(Iterations, LLsearchB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (microseconds)','Interpreter','latex')
title('Linked List Efficency of DatasetB','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

saveas(gcf,'LL_Efficiency.pdf');

% Binary Search Tree Effieceny Plots
f3 = figure(3);
subplot(2, 1, 1);
cla; hold on; grid on;
plot(Iterations, BSTinsertA, 'b-','LineWidth',0.75);
plot(Iterations, BSTsearchA, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Binary Search Tree Efficency of DatasetA','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

subplot(2, 1, 2);
hold on; grid on; 
plot(Iterations, BSTinsertB, 'b-','LineWidth',0.75);
plot(Iterations, BSTsearchB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Binary Search Tree Efficency of DatasetB','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

saveas(gcf,'BST_Efficiency.pdf');

% Hash Table Chaining Effieceny Plots
f4 = figure(4);
subplot(2, 1, 1);
cla; hold on; grid on;
plot(Iterations, HTCinsertA, 'b-','LineWidth',0.75);
plot(Iterations, HTCsearchA, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Hash Table Chaining Efficency of DatasetA','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

subplot(2, 1, 2);
hold on; grid on; 
plot(Iterations, HTCinsertB, 'b-','LineWidth',0.75);
plot(Iterations, HTCsearchB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Hash Table Chaining Efficency of DatasetB','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

saveas(gcf,'HTC_Efficiency.pdf');

% Hash Table Linear Probing Effieceny Plots
f5 = figure(5);
subplot(2, 1, 1);
cla; hold on; grid on;
plot(Iterations, HTLinsertA, 'b-','LineWidth',0.75);
plot(Iterations, HTLsearchA, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Hash Table Linear Probing Efficency of DatasetA','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

subplot(2, 1, 2);
hold on; grid on; 
plot(Iterations, HTLinsertB, 'b-','LineWidth',0.75);
plot(Iterations, HTLsearchB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Hash Table Linear Probing Efficency of DatasetB','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

saveas(gcf,'HTL_Efficiency.pdf');

% Hash Table Quadratic Probing Effieceny Plots
f6 = figure(6);
subplot(2, 1, 1);
cla; hold on; grid on;
axis([xQuadmin xQuadmax yQuadmin yQuadmax])
plot(Iterations, HTQinsertA, 'b-','LineWidth',0.75);
plot(Iterations, HTQsearchA, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Hash Table Quadratic Probing Efficency of DatasetA','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

subplot(2, 1, 2);
hold on; grid on; 
axis([xQuadmin xQuadmax yQuadmin yQuadmax])
plot(Iterations, HTQinsertB, 'b-','LineWidth',0.75);
plot(Iterations, HTQsearchB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('Hash Table Quadratic Probing Efficency of DatasetB','Interpreter','latex')
legend('Avg insertion times', 'Avg search times')

saveas(gcf,'HTQ_Efficiency.pdf');

% Hash Table Collisions Plots
f7 = figure(7);
subplot(3, 1, 1);
cla; hold on; grid on;
plot(Iterations, HTCcollisionsA, 'b-','LineWidth',0.75);
plot(Iterations, HTCcollisionsB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Number of Collisions','Interpreter','latex')
title('Hash Table Number of Chaining Collisions','Interpreter','latex')
legend('Dataset A', 'Dataset B')

subplot(3, 1, 2);
hold on; grid on; 
plot(Iterations, HTLcollisionsA, 'b-','LineWidth',0.75);
plot(Iterations, HTLcollisionsB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Number of Collisions','Interpreter','latex')
title('Hash Table Number of Linear Probing Collisions','Interpreter','latex')
legend('Dataset A', 'Dataset B')

subplot(3, 1, 3);
hold on; grid on; 
plot(Iterations, HTQcollisionsA, 'b-','LineWidth',0.75);
plot(Iterations, HTQcollisionsB, 'r-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Number of Collisions','Interpreter','latex')
title('Hash Table Number of Quadratic Probing Collisions','Interpreter','latex')
legend('Dataset A', 'Dataset B')

saveas(gcf,'HashTable_Collisions_graphs.pdf');

% DatasetA Summary Figure Plot
newLLinseartA = (1000 .* LLinsertA);
newLLsearchA = (1000 .* LLinsertB);

f8 = figure(8);
subplot(2, 1, 1);
cla; hold on; grid on;
axis([xSummin xSummax ySummin ySummax])
plot(Iterations, newLLinseartA, 'r-','LineWidth',0.75);
plot(Iterations, BSTinsertA, 'b-','LineWidth',0.75);
plot(Iterations, HTCinsertA, 'm-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('DatasetA Insert Data Structure Comparison','Interpreter','latex')
legend('Linked List', 'Binary Search Tree', 'Hash Table with Chaining')

subplot(2, 1, 2);
cla; hold on; grid on;
axis([xSummin xSummax ySummin ySummax])
plot(Iterations, newLLsearchA, 'r-','LineWidth',0.75);
plot(Iterations, BSTsearchA, 'b-','LineWidth',0.75);
plot(Iterations, HTCsearchA, 'm-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('DatasetA Search Data Structure Comparison','Interpreter','latex')
legend('Linked List', 'Binary Search Tree', 'Hash Table with Chaining')

saveas(gcf,'DatasetA_Data_Structure_Comparison.pdf');

% DatasetB Summary Figure Plot
newLLinseartB = (1000 .* LLinsertA);
newLLsearchB = (1000 .* LLinsertB);

f9 = figure(9);
subplot(2, 1, 1);
cla; hold on; grid on;
axis([xSummin xSummax ySummin ySummax])
plot(Iterations, newLLinseartB, 'r-','LineWidth',0.75);
plot(Iterations, BSTinsertB, 'b-','LineWidth',0.75);
plot(Iterations, HTCinsertB, 'm-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('DatasetB Insert Data Structure Comparison','Interpreter','latex')
legend('Linked List', 'Binary Search Tree', 'Hash Table with Chaining')

subplot(2, 1, 2);
cla; hold on; grid on;
axis([xSummin xSummax ySummin ySummax])
plot(Iterations, newLLsearchB, 'r-','LineWidth',0.75);
plot(Iterations, BSTsearchB, 'b-','LineWidth',0.75);
plot(Iterations, HTCsearchB, 'm-','LineWidth',0.75);

xlabel('Iterations','Interpreter','latex')
ylabel('Time (nanoseconds)','Interpreter','latex')
title('DatasetB Search Data Structure Comparison','Interpreter','latex')
legend('Linked List', 'Binary Search Tree', 'Hash Table with Chaining')

saveas(gcf,'DatasetB_Data_Structure_Comparison.pdf');


