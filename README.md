# OFDM-
# 📡 OFDM Communication System Simulation / 基于 MATLAB 的 OFDM 通信系统仿真

## 🧭 Project Overview / 项目简介
This project implements a **baseband OFDM (Orthogonal Frequency Division Multiplexing)** simulation in **MATLAB**, aiming to understand the basic principles of OFDM modulation and demodulation, and to analyze system performance under noise.

本项目使用 **MATLAB** 实现了一个**基带 OFDM（正交频分复用）通信系统**的仿真，用于理解 OFDM 调制解调的基本原理，并分析不同调制方式下的系统性能。

System features / 系统功能包括：
- Modulation & Demodulation （调制与解调）
- IFFT/FFT Operations （IFFT/FFT 操作）
- Cyclic Prefix (CP) Insertion/Removal （循环前缀添加与去除）
- AWGN Channel Simulation （加性高斯白噪声信道）
- BER Performance Analysis （误码率性能分析）

---

## 🎯 Objectives / 项目目标
- Understand the transceiver architecture of OFDM systems  
  理解 OFDM 系统的收发架构  
- Learn to simulate wireless channel effects using MATLAB  
  学习在 MATLAB 中仿真无线信道  
- Analyze BER vs. SNR for different modulation schemes  
  比较不同调制方式的误码率性能  
- Visualize constellation diagrams and BER curves  
  可视化星座图与 BER 曲线  

---

## 🧩 System Structure / 系统结构
Transmitter / 发射端:
Bit Generation → Modulation → IFFT → Add Cyclic Prefix

Channel / 信道:
AWGN Noise Model

Receiver / 接收端:
Remove CP → FFT → Demodulation → BER Calculation
---

## ⚙️ Simulation Parameters / 仿真参数

| Parameter | Description | Value |
|------------|--------------|--------|
| Number of subcarriers / 子载波数 | FFT size | 64 |
| CP length / 循环前缀长度 | 16 |
| Modulation type / 调制方式 | BPSK / QPSK / 16QAM |
| Channel / 信道 | AWGN |
| SNR range / 信噪比范围 | 0–30 dB |
| Number of symbols / 符号数量 | 10,000 |

---

## 📊 Results / 仿真结果

### 1️⃣ BER Performance / 误码率性能

| Modulation | SNR = 10 dB | BER |
|-------------|-------------|-----|
| BPSK | 0.0008 | ✅ |
| QPSK | 0.0015 | ✅ |
| 16QAM | 0.0102 | ✅ |


### 2️⃣ Constellation Diagram / 星座图 (QPSK, SNR = 10 dB)



---

## 🧠 Key Insights / 结果分析
- Higher SNR → Lower BER, as expected in AWGN channels.  
  信噪比越高，误码率越低。  
- Higher-order modulations (16QAM) require higher SNR to maintain low BER.  
  高阶调制方式（如 16QAM）对信噪比要求更高。  
- The OFDM structure effectively handles multipath fading when extended to fading channels.  
  OFDM 结构在多径信道下具有良好的抗干扰性能。  

---

## 💡 Future Work / 后续工作
- Add **Rayleigh Fading Channel / 瑞利衰落信道仿真**  
- Implement **LS / MMSE Channel Estimation / 信道估计算法（LS/MMSE）**  
- Compare **Single Carrier vs. OFDM** performance  
- Explore **Python (NumPy) Implementation / Python 版本实现**

---

## 🛠️ How to Run 

1. Clone this repository / 克隆项目：
   ```bash
   git clone https://github.com/AMUHE/OFDM-.git
📚 References / 参考文献
	•	J. G. Proakis, Digital Communications, 5th Edition
	•	3GPP TS 36.211 — Physical Channels and Modulation
	•	MATLAB Communications Toolbox Examples
👤 Author /
Name / 姓名： JieYuxin
University / 学校： Nanhangjincheng College
Email / 邮箱： 1316730787@qq.com
Keywords / 关键词： OFDM, MATLAB, Communication Algorithm, Signal Processing

