#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 64       // 子载波数
#define CP 16      // 循环前缀长度
#define NUM_SYMBOLS 1000
#define M 16       // 16-QAM

// 简单复数结构体
typedef struct {
    double re;
    double im;
} Complex;

// 占位 IFFT 函数（实际可使用 FFTW 库）
void ifft(Complex* in, Complex* out, int n) {
    for(int k=0; k<n; k++) {
        out[k].re = 0;
        out[k].im = 0;
        for(int t=0; t<n; t++) {
            double angle = 2 * M_PI * t * k / n;
            out[k].re += in[t].re * cos(angle) + in[t].im * sin(angle);
            out[k].im += -in[t].re * sin(angle) + in[t].im * cos(angle);
        }
        out[k].re /= n;
        out[k].im /= n;
    }
}

int main() {
    srand(time(NULL));
    int data[NUM_SYMBOLS];
    Complex txSignal[N], rxSignal[N];

    // 生成随机比特
    for(int i=0; i<NUM_SYMBOLS; i++) {
        data[i] = rand() % M;
    }

    // QAM 调制（16-QAM 简单映射）
    for(int i=0; i<N; i++) {
        int val = data[i % NUM_SYMBOLS];
        txSignal[i].re = 2*(val % 4) - 3; // 映射到 -3,-1,1,3
        txSignal[i].im = 2*(val / 4) - 3;
    }

    // IFFT
    Complex txIFFT[N];
    ifft(txSignal, txIFFT, N);

    // 添加循环前缀
    Complex txCP[N + CP];
    for(int i=0; i<CP; i++)
        txCP[i] = txIFFT[N-CP+i];
    for(int i=0; i<N; i++)
        txCP[i+CP] = txIFFT[i];

    // 接收端移除循环前缀
    for(int i=0; i<N; i++)
        rxSignal[i] = txCP[i+CP];

    // FFT 可用占位函数实现，或者直接假设无误差
    int errors = 0;
    for(int i=0; i<N; i++) {
        int rxVal = ((int)((rxSignal[i].re+3)/2) % 4) + 4*((int)((rxSignal[i].im+3)/2));
        if(rxVal != data[i % NUM_SYMBOLS]) errors++;
    }

    double BER = (double)errors / N;
    printf("误码率 BER = %.4f\n", BER);

    return 0;
} 