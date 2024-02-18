C99 standard (§6.7.2.1)

A bit-field shall have a type that is a qualified or unqualified version of _Bool, signed int, unsigned int, or some other implementation-defined type.

在 struct {int a : 1; } obj = {.a = 1 }; 的地方，原本 int 這個資料型態需要 4 bytes 的空間，即 32 個位元，我們透過 bit field 指定只用其中一個 bit 來存放數值。

但因 a 是 signed integer，依據二補數系統，1 bit 的範圍內只能表示 -1 和 0，於是程式輸出為 not one。

而決定 1-bit binary 1 為 -1 的是編譯器所定義，可見上述引用 C 語言規格書提及 implementation-defined 這個詞，代表該行為由實作品 (通常是指編譯器) 所決定，並對該定義有義務在文件內說明與告知。

如果題目的 int 並沒有說是 signed 或 unsigned ，那麼 bit-field 宣告之後究竟該是 signed / unsigned 是由編譯器所決定的。



即 a = 111 (decimal -1), b = 11 (decimal -1), c = 1100 (decimal -4), d = 000 (decimal 0)，沒有 alignment 則是 a = 111, b = 1 1, c = 1 11 1, d = 111。

但實際每次執行，d 的數值都不一樣。

重新思考過 padding 的方式，發現上述拿來舉例的程式碼是有漏洞。zero-width bit-field 對齊的示意圖如下：

i = 1111 1111 1111 1111
                            padding & start from here
                                    ↓
1111 1111 1111 1111  
             b baaa           dddcccc

|←  int 32 bits  →|←  int 32 bits  →|
而這裡因為宣告一個 int 的 zero-width bit-field ，所以要對齊的長度為 32 bit，c 和 d 早已超出 0xFFFF 的範圍，指到程式中不知名的地方，才會導致 d 每次都會是不同的答案。

如果使用 gcc 的話，c 有可能會一直維持 -4 不變，之所會這樣因為編譯器的緣故，但使用其他編譯器可能得到不同的結果，只有 a 跟 b 才是確定的。

在 C11 中，提供 _Static_assert 這樣的敘述來達到上述 BUILD_BUG_ON_ZERO 的效果，就不需要繞這麼一大圈，不過 Linux 核心考量到編譯器對語言規格的支援程度，最低期待是 C99 規格。