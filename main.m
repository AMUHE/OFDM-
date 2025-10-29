% main.m - 最基础的 OFDM 仿真示例

clc; clear; close all;

%% 参数设置
N = 64;             % 子载波数
cp_len = 16;        % 循环前缀长度
M = 16;             % QAM 调制阶数
numSymbols = 1000;  % 总比特数

%% 生成随机比特
data = randi([0 M-1], numSymbols, 1);

%% QAM 调制
modData = qammod(data, M, 'UnitAveragePower', true);

%% 将数据分成 OFDM 符号
numOFDM = ceil(length(modData)/N);
modData = [modData; zeros(numOFDM*N - length(modData),1)]; % 补零
ofdmData = reshape(modData, N, numOFDM);

%% IFFT - OFDM 发送
txSignal = ifft(ofdmData, N, 1);

%% 添加循环前缀
txCP = [txSignal(end-cp_len+1:end,:); txSignal];

%% 模拟传输（无信道，只演示流程）
rxCP = txCP;

%% 移除循环前缀
rxSignal = rxCP(cp_len+1:end, :);

%% FFT - 接收端
rxData = fft(rxSignal, N, 1);
rxData = rxData(:);

%% QAM 解调
rxBits = qamdemod(rxData, M, 'UnitAveragePower', true);

%% 计算误码率
numErrors = sum(rxBits(1:numSymbols) ~= data);
BER = numErrors/numSymbols;

fprintf('误码率 BER = %.4f\n', BER); 