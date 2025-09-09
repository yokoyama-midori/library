#pragma once
// ref: https://maspypy.com/library-checker-many-a-b , Nyaanさん
#include "./type-utils.hpp"
namespace fastio {
constexpr int SZ = 1 << 17;
constexpr int offset = 64;
constexpr int mod = 10000;
char in_buf[SZ];
int in_left{}, in_right{};
char out_buf[SZ];
char out_tmp[offset];
int out_right{};
struct Pre {
    char num[4 * mod]{};
    constexpr Pre() {
        for(int i = 0; i < mod; ++i) {
            for(int n = i, j = 3; j >= 0; --j, n /= 10)
                num[4 * i + j] = '0' + n % 10;
        }
    }
    constexpr const char *operator[](int i) const { return &num[4 * i]; }
} constexpr pre;
void load() {
    memmove(in_buf, in_buf + in_left, in_right - in_left);
    in_right += -in_left + std::fread(in_buf + in_right - in_left, 1,
                                      SZ - (in_right - in_left), stdin);
    in_left = 0;
    if(in_right < SZ)
        in_buf[in_right++] = '\n';
}
void read(char &c) {
    do {
        if(in_left == in_right)
            load();
        c = in_buf[in_left++];
    } while(isspace(c));
}
void read(std::string &s) {
    s.clear();
    char c;
    do {
        if(in_left == in_right)
            load();
        c = in_buf[in_left++];
    } while(isspace(c));
    do {
        s += c;
        if(in_left == in_right)
            load();
        c = in_buf[in_left++];
    } while(!isspace(c));
}
template <extended_integral T> void read(T &x) {
    if(in_right - in_left < offset)
        load();
    char c;
    do
        c = in_buf[in_left++];
    while(c < '-'); // \n:10 space:32 -:45 '0':48
    bool minus{};
    if constexpr(extended_signed_integral<T>) {
        if(c == '-') {
            c = in_buf[in_left++];
            minus = true;
        }
    }
    x = 0;
    while(c >= '0') {
        x = 10 * x + (c & 15);
        c = in_buf[in_left++];
    }
    if constexpr(extended_signed_integral<T>) {
        if(minus)
            x = -x;
    }
}
void flush() { fwrite(out_buf, 1, std::exchange(out_right, 0), stdout); }
void write_range(const char *c, int n) {
    while(n > 0) {
        if(out_right == SZ)
            flush();
        int len = std::min(n, SZ - out_right);
        memcpy(out_buf + out_right, c, len);
        out_right += len;
        n -= len;
    }
}

void write(char c) {
    if(SZ == out_right)
        flush();
    out_buf[out_right++] = c;
}
void write(const char *c) { write_range(c, strlen(c)); }
void write(const std::string &s) { write_range(s.data(), s.size()); }
template <std::floating_point T> void write(T x) {
    int n = std::snprintf(out_tmp, sizeof(out_tmp), "%.16g", x);
    write_range(out_tmp, n);
}
void write(bool x) { write(x ? '1' : '0'); }
template <extended_integral T> void write(T x) {
    if(x == 0) {
        write('0');
    }
    if constexpr(extended_signed_integral<T>) {
        if(x < 0) {
            write('-');
            x = -x;
        }
    }
    if(SZ - out_right < offset)
        flush();
    int cur = offset;
    for(; x >= 1000; x /= mod) {
        cur -= 4;
        memcpy(out_tmp + cur, pre[x % mod], 4);
    }
    if(x >= 100) {
        cur -= 3;
        memcpy(out_tmp + cur, pre[x % mod] + 1, 3);
    } else if(x >= 10) {
        cur -= 2;
        memcpy(out_tmp + cur, pre[x % mod] + 2, 2);
    } else if(x >= 1) {
        cur -= 1;
        memcpy(out_tmp + cur, pre[x % mod] + 3, 1);
    }
    write_range(out_tmp + cur, offset - cur);
}
struct Dummy {
    // プログラム終了時に出力
    ~Dummy() { flush(); }
} dummy;
} // namespace fastio
using fastio::write;