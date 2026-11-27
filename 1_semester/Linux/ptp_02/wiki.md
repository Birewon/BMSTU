# Задание 2 по ПТП.

В качестве примера программы я буду использовать свой код из 6-го задания лабараторной работы.

```C
#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int type_of_tr(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double ab = pow(xb - xa, 2) + pow(yb - ya, 2);
    double ac = pow(xc - xa, 2) + pow(yc - ya, 2);
    double bc = pow(xc - xb, 2) + pow(yc - yb, 2);

    if (ab < (0 + EPS) || ac < (0 + EPS) || bc < (0 + EPS))
    {
        return -1;
    }
    else if (sqrt(ab) + sqrt(ac) <= sqrt(bc) + EPS || sqrt(ab) + sqrt(bc) <= sqrt(ac) + EPS || sqrt(ac) + sqrt(bc) <= sqrt(ab) + EPS)
    {
        return -1;
    }

    if ((ab + ac < bc) || (ab + bc < ac) || (ac + bc < ab))
    {
        return 2;
    }
    else if (fabs(ab + ac - bc) < EPS || fabs(ab + bc - ac) < EPS || fabs(ac + bc - ab) < EPS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    if (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
    {
        return 1;
    }
    

    int res = type_of_tr(xa, ya, xb, yb, xc, yc);
    if (res != -1)
    {
        printf("%d\n", res);
    }
    else
    {
        return 1;
    }

    return 0;
}
```

## 1. Компилятор gcc

### 1.1 Версия компилятора

Для начала узнаем версию компилятора _gcc:_

```bash
$ gcc --version

gcc (GCC) 16.2.1 20260819 (Red Hat 16.2.1-2)
Copyright (C) 2026 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### 1.2 Команда для получения исполняемого файла

Скомпилируем указанную выше программу с помощью _gcc_ с ключами:

`-std=c99 -Wall -Werror -save-temps -v -lm`

Эти ключи указывают параметры компиляции программы.

```
$ gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -lm -save-temps -v main.c

Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/16/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-redhat-linux
Configured with: ../configure --enable-bootstrap --enable-languages=c,c++,fortran,objc,obj-c++,ada,go,d,m2,cobol,algol68,lto --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=https://bugzilla.redhat.com/ --enable-shared --enable-threads=posix --enable-checking=release --enable-multilib --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-gcc-major-version-only --enable-libstdcxx-backtrace --with-libstdcxx-zoneinfo=/usr/share/zoneinfo --with-linker-hash-style=gnu --enable-plugin --enable-initfini-array --with-isl=/builddir/build/BUILD/gcc-16.2.1-build/gcc-16.2.1-20260819/obj-x86_64-redhat-linux/isl-install --enable-offload-targets=nvptx-none,amdgcn-amdhsa --enable-offload-defaulted --without-cuda-driver --enable-gnu-indirect-function --enable-cet --with-tune=generic --with-tls=gnu2 --with-arch_32=i686 --build=x86_64-redhat-linux --with-build-config=bootstrap-lto --enable-link-serialization=1 --disable-libssp
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 16.2.1 20260819 (Red Hat 16.2.1-2) (GCC) 
COLLECT_GCC_OPTIONS='-std=c99' '-Wall' '-Werror' '-save-temps' '-v' '-foffload-options=-l_GCC_m' '-mtune=generic' '-march=x86-64' '-mtls-dialect=gnu2' '-dumpdir' 'a-'
 /usr/libexec/gcc/x86_64-redhat-linux/16/cc1 -E -quiet -v main.c -mtune=generic -march=x86-64 -mtls-dialect=gnu2 -std=c99 -Wall -Werror -foffload-options=-l_GCC_m -fpch-preprocess -o a-main.i
ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/16/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/16/../../../../x86_64-redhat-linux/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/x86_64-redhat-linux/16/include
 /usr/local/include
 /usr/include
End of search list.
COLLECT_GCC_OPTIONS='-std=c99' '-Wall' '-Werror' '-save-temps' '-v' '-foffload-options=-l_GCC_m' '-mtune=generic' '-march=x86-64' '-mtls-dialect=gnu2' '-dumpdir' 'a-'
 /usr/libexec/gcc/x86_64-redhat-linux/16/cc1 -fpreprocessed a-main.i -quiet -dumpdir a- -dumpbase main.c -dumpbase-ext .c -mtune=generic -march=x86-64 -mtls-dialect=gnu2 -Wall -Werror -std=c99 -version -foffload-options=-l_GCC_m -o a-main.s
GNU C99 (GCC) version 16.2.1 20260819 (Red Hat 16.2.1-2) (x86_64-redhat-linux)
	compiled by GNU C version 16.2.1 20260819 (Red Hat 16.2.1-2), GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.4.1, isl version isl-0.24-GMP

GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
Compiler executable checksum: 9bab69ee039b57e5d63c6dcf5d331ec2
COLLECT_GCC_OPTIONS='-std=c99' '-Wall' '-Werror' '-save-temps' '-v' '-foffload-options=-l_GCC_m' '-mtune=generic' '-march=x86-64' '-mtls-dialect=gnu2' '-dumpdir' 'a-'
 as -v --64 -o a-main.o a-main.s
GNU assembler version 2.46.1 (x86_64-redhat-linux) using BFD version version 2.46.1-1.fc44
COMPILER_PATH=/usr/libexec/gcc/x86_64-redhat-linux/16/:/usr/libexec/gcc/x86_64-redhat-linux/16/:/usr/libexec/gcc/x86_64-redhat-linux/:/usr/lib/gcc/x86_64-redhat-linux/16/:/usr/lib/gcc/x86_64-redhat-linux/
LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/16/:/usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/:/lib/../lib64/:/usr/lib/../lib64/:/usr/lib/gcc/x86_64-redhat-linux/16/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-std=c99' '-Wall' '-Werror' '-save-temps' '-v' '-foffload-options=-l_GCC_m' '-mtune=generic' '-march=x86-64' '-mtls-dialect=gnu2' '-dumpdir' 'a.'
 /usr/libexec/gcc/x86_64-redhat-linux/16/collect2 -plugin /usr/libexec/gcc/x86_64-redhat-linux/16/liblto_plugin.so -plugin-opt=/usr/libexec/gcc/x86_64-redhat-linux/16/lto-wrapper -plugin-opt=-fresolution=a.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s_asneeded -plugin-opt=-pass-through=-latomic_asneeded -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s_asneeded --build-id --no-add-needed --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crt1.o /usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/16/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/16 -L/usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/lib/gcc/x86_64-redhat-linux/16/../../.. -L/lib -L/usr/lib a-main.o -lm -lgcc -lgcc_s_asneeded -latomic_asneeded -lc -lgcc -lgcc_s_asneeded /usr/lib/gcc/x86_64-redhat-linux/16/crtend.o /usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crtn.o
COLLECT_GCC_OPTIONS='-std=c99' '-Wall' '-Werror' '-save-temps' '-v' '-foffload-options=-l_GCC_m' '-mtune=generic' '-march=x86-64' '-mtls-dialect=gnu2' '-dumpdir' 'a.'
```

### 1.3 Cписок файлов, полученных в результате компиляции

После успешной компиляции я получил несколько файлов:

| Имя | Размер, Кб | Тип |
|-----|------------|-----|
| main.c | 1.2 | Текстовый |
| a-main.i | 49 | Код после препроцессора |
| a-main.s | 5.1 | Код после ассемблирования |
| a-main.o | 3.6 | Объектный файл (машинный код) |
| a.out | 13 | Исполняемый файл |

### 1.4 Препроцессирование

Команда для выполнения этапа препроцессирования:

```
...
/usr/libexec/gcc/x86_64-redhat-linux/16/cc1 -E -quiet -v main.c -mtune=generic -march=x86-64 -mtls-dialect=gnu2 -std=c99 -Wall -Werror -foffload-options=-l_GCC_m -fpch-preprocess -o a-main.i
...
```

<table>
<tr>
<th colspan="2">Разбор выполнения команды</th>
</tr>
<tr>
<td>Вход</td>
<td>main.c</td>
</tr>
<tr>
<td>Выход</td>
<td>a-main.i</td>
</tr>
<tr>
<td>Назначение</td>
<td>Удаление комментариев, вставка директив, раскрытие макросов, условная компиляция</td>
</tr>
<tr>
<td>Имя утилиты</td>
<td>cc1</td>
</tr>
<tr>
<td>

Способ передачи

параметров
</td>
<td>Через ключи командной строки</td>
</tr>
</table>

### 1.5 Ассемблирование (компиляция)

Команда для выполнения этапа ассемблирования:

```
...
/usr/libexec/gcc/x86_64-redhat-linux/16/cc1 -fpreprocessed a-main.i -quiet -dumpdir a- -dumpbase main.c -dumpbase-ext .c -mtune=generic -march=x86-64 -mtls-dialect=gnu2 -Wall -Werror -std=c99 -version -foffload-options=-l_GCC_m -o a-main.s
...
```

<table>
<tr>
<th colspan="2">Разбор выполнения команды</th>
</tr>
<tr>
<td>Вход</td>
<td>a-main.i</td>
</tr>
<tr>
<td>Выход</td>
<td>a-main.s</td>
</tr>
<tr>
<td>Назначение</td>
<td>Преобразование чистого кода на C в язык ассемблера, для его упрощения</td>
</tr>
<tr>
<td>Имя утилиты</td>
<td>cc1</td>
</tr>
<tr>
<td>

Способ передачи

параметров
</td>
<td>Через ключи командной строки</td>
</tr>
</table>

### 1.6 Трансляция с языка ассемблера в машинный код

Команда для выполнения этапа трансляции:

```
...
as -v --64 -o a-main.o a-main.s
...
```

<table>
<tr>
<th colspan="2">Разбор выполнения команды</th>
</tr>
<tr>
<td>Вход</td>
<td>a-main.s</td>
</tr>
<tr>
<td>Выход</td>
<td>a-main.o</td>
</tr>
<tr>
<td>Назначение</td>
<td>Преобразование программы с языка ассемблера в машинный код</td>
</tr>
<tr>
<td>Имя утилиты</td>
<td>as</td>
</tr>
<tr>
<td>

Способ передачи

параметров
</td>
<td>Через ключи командной строки</td>
</tr>
</table>

### 1.7 Компоновка

Команда для выполнения этапа компоновки:

```
...
 /usr/libexec/gcc/x86_64-redhat-linux/16/collect2 -plugin /usr/libexec/gcc/x86_64-redhat-linux/16/liblto_plugin.so -plugin-opt=/usr/libexec/gcc/x86_64-redhat-linux/16/lto-wrapper -plugin-opt=-fresolution=a.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s_asneeded -plugin-opt=-pass-through=-latomic_asneeded -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s_asneeded --build-id --no-add-needed --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 /usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crt1.o /usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/16/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/16 -L/usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/lib/gcc/x86_64-redhat-linux/16/../../.. -L/lib -L/usr/lib a-main.o -lm -lgcc -lgcc_s_asneeded -latomic_asneeded -lc -lgcc -lgcc_s_asneeded /usr/lib/gcc/x86_64-redhat-linux/16/crtend.o /usr/lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crtn.o
...
```

<table>
<tr>
<th colspan="2">Разбор выполнения команды</th>
</tr>
<tr>
<td>Вход</td>
<td>a-main.o, системные объектные файлы</td>
</tr>
<tr>
<td>Выход</td>
<td>a.out</td>
</tr>
<tr>
<td>Назначение</td>
<td>

Совмещает несколько объектный файлов в 1.

Связывает переменные и функции.

Добавляет дополнительный код.
</td>
</tr>
<tr>
<td>Имя утилиты</td>
<td>collect2</td>
</tr>
<tr>
<td>

Способ передачи

параметров
</td>
<td>Через ключи командной строки и файлы</td>
</tr>
</table>

Список объектных файлов, с которыми компонуется программа

| Имя | Назначение |
|-----|------------|
| a-main.o | Исходный код программы |
| crt1.o | Код запуска программы |
| crti.o | Код инициализации |
| crtbegin.o | Код инициализвции и завершения |
| crtend.o | Код завершения |
| crtn.o | Код завершающей части инициализации |

Список библиотек, с которыми компонуется программа

| Имя | Назначение |
|-----|------------|
| libm | Библиотека содержащая математические функции |
| libgcc | Библиотека необходимая в некоторых операциях gcc |
| libgcc_s | Библиотека содержащая служебные функции |
| labatomic | Поддержка атомарных операций |
| libc | Поддержка ввода/вывода и стандартные функции |

## 2. Компилятор clang

### 2.1 Версия компилятора

```
$ clang --version

clang version 22.1.8 (Fedora 22.1.8-4.fc44)
Target: x86_64-redhat-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
Configuration file: /etc/clang/x86_64-redhat-linux-gnu-clang.cfg
```

### 2.2 Команда для получения исполняемого файла

```
$ clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -lm -save-temps -v main.c

clang version 22.1.8 (Fedora 22.1.8-4.fc44)
Target: x86_64-redhat-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
Configuration file: /etc/clang/x86_64-redhat-linux-gnu-clang.cfg
System configuration file directory: /etc/clang/
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-redhat-linux/16
Selected GCC installation: /usr/bin/../lib/gcc/x86_64-redhat-linux/16
Candidate multilib: .;@m64
Candidate multilib: 32;@m32
Selected multilib: .;@m64
 "/usr/bin/clang-22" -cc1 -triple x86_64-redhat-linux-gnu -E -dumpdir a- -save-temps=cwd -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -v -fcoverage-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -resource-dir /usr/bin/../lib/clang/22 -internal-isystem /usr/bin/../lib/clang/22/include -internal-isystem /usr/local/include -internal-isystem /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../x86_64-redhat-linux/include -internal-externc-isystem /include -internal-externc-isystem /usr/include -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -std=c99 -ferror-limit 19 -fmessage-length=169 -fgnuc-version=4.2.1 -fskip-odr-check-in-gmf -fcolor-diagnostics -faddrsig -fdwarf2-cfi-asm -o main.i -x c main.c
clang -cc1 version 22.1.8 based upon LLVM 22.1.8 default target x86_64-redhat-linux-gnu
ignoring nonexistent directory "/usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../x86_64-redhat-linux/include"
ignoring nonexistent directory "/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/bin/../lib/clang/22/include
 /usr/local/include
 /usr/include
End of search list.
 "/usr/bin/clang-22" -cc1 -triple x86_64-redhat-linux-gnu -emit-llvm-bc -emit-llvm-uselists -dumpdir a- -save-temps=cwd -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -v -fcoverage-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -resource-dir /usr/bin/../lib/clang/22 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -std=c99 -ferror-limit 19 -fmessage-length=169 -fgnuc-version=4.2.1 -fskip-odr-check-in-gmf -fcolor-diagnostics -disable-llvm-passes -faddrsig -fdwarf2-cfi-asm -o main.bc -x cpp-output main.i
clang -cc1 version 22.1.8 based upon LLVM 22.1.8 default target x86_64-redhat-linux-gnu
#include "..." search starts here:
End of search list.
 "/usr/bin/clang-22" -cc1 -triple x86_64-redhat-linux-gnu -S -dumpdir a- -save-temps=cwd -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -v -fcoverage-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -resource-dir /usr/bin/../lib/clang/22 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -std=c99 -ferror-limit 19 -fmessage-length=169 -fgnuc-version=4.2.1 -fskip-odr-check-in-gmf -fcolor-diagnostics -faddrsig -fdwarf2-cfi-asm -o main.s -x ir main.bc
clang -cc1 version 22.1.8 based upon LLVM 22.1.8 default target x86_64-redhat-linux-gnu
 "/usr/bin/clang-22" -cc1as -triple x86_64-redhat-linux-gnu -filetype obj -main-file-name main.c -target-cpu x86-64 -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -dwarf-version=5 -mrelocation-model static -o main.o main.s
 "/usr/bin/ld" --hash-style=gnu --build-id --eh-frame-hdr -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o a.out /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crt1.o /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crti.o /usr/bin/../lib/gcc/x86_64-redhat-linux/16/crtbegin.o -L/usr/bin/../lib/clang/22/lib/x86_64-redhat-linux-gnu -L/usr/bin/../lib/gcc/x86_64-redhat-linux/16 -L/usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64 -L/lib/../lib64 -L/usr/lib64 -L/lib -L/usr/lib -lm main.o -lgcc --as-needed -lgcc_s --no-as-needed -lc -lgcc --as-needed -lgcc_s --no-as-needed /usr/bin/../lib/gcc/x86_64-redhat-linux/16/crtend.o /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crtn.o
```

### 2.3 Список файлов, полученных в результате компиляции

| Имя | Размер, Кб | Тип |
|-----|------------|-----|
| main.c | 1.2 | Текстовый (исходный код) |
| a-main.i | 46 | Код после препроцессора |
| a-main.s | 8.7 | Код после ассемблирования |
| a-main.o | 3.5 | Объектный файл (машинный код) |
| a.out | 13 | Исполняемый файл |

### 2.4 Препроцессирование

```
...
"/usr/bin/clang-22" -cc1 -triple x86_64-redhat-linux-gnu -E -dumpdir a- -save-temps=cwd -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -v -fcoverage-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -resource-dir /usr/bin/../lib/clang/22 -internal-isystem /usr/bin/../lib/clang/22/include -internal-isystem /usr/local/include -internal-isystem /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../x86_64-redhat-linux/include -internal-externc-isystem /include -internal-externc-isystem /usr/include -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -std=c99 -ferror-limit 19 -fmessage-length=169 -fgnuc-version=4.2.1 -fskip-odr-check-in-gmf -fcolor-diagnostics -faddrsig -fdwarf2-cfi-asm -o main.i -x c main.c
...
```

<table>
<tr>
<th colspan="2">Разбор выполнения команды</th>
</tr>
<tr>
<td>Вход</td>
<td>main.c</td>
</tr>
<tr>
<td>Выход</td>
<td>main.i</td>
</tr>
<tr>
<td>Назначение</td>
<td>Удаление комментариев, вставка директив, раскрытие макросов, условная компиляция</td>
</tr>
<tr>
<td>Имя утилиты</td>
<td>clang-22</td>
</tr>
<tr>
<td>Способ передачи параметров</td>
<td>Через ключи командной строки</td>
</tr>
</table>

### 2.5 Генерация промежуточного представления кода

```
...
"/usr/bin/clang-22" -cc1 -triple x86_64-redhat-linux-gnu -emit-llvm-bc -emit-llvm-uselists -dumpdir a- -save-temps=cwd -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -v -fcoverage-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -resource-dir /usr/bin/../lib/clang/22 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -std=c99 -ferror-limit 19 -fmessage-length=169 -fgnuc-version=4.2.1 -fskip-odr-check-in-gmf -fcolor-diagnostics -disable-llvm-passes -faddrsig -fdwarf2-cfi-asm -o main.bc -x cpp-output main.i
...
```

| Разбор выполнения команды |  |
|---------------------------|--|
| Вход | main.i |
| Выход | main.bc |
| Назначение | промежуточное представление кода |
| Имя утилиты | clang-22 |
| Способ передачи параметров | Через ключи командной строки |

### 2.6 Ассемблирование (компиляция)

```
...
 "/usr/bin/clang-22" -cc1 -triple x86_64-redhat-linux-gnu -S -dumpdir a- -save-temps=cwd -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name main.c -mrelocation-model static -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funwind-tables=2 -target-cpu x86-64 -tune-cpu generic -debugger-tuning=gdb -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -v -fcoverage-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -resource-dir /usr/bin/../lib/clang/22 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -std=c99 -ferror-limit 19 -fmessage-length=169 -fgnuc-version=4.2.1 -fskip-odr-check-in-gmf -fcolor-diagnostics -faddrsig -fdwarf2-cfi-asm -o main.s -x ir main.bc
...
```

| Разбор выполнения команды |  |
|---------------------------|--|
| Вход | main.bc |
| Выход | main.o |
| Назначение | Преобразование промежуточного кода в язык ассемблера |
| Имя утилиты | clang-22 |
| Способ передачи параметров | Через ключи командной строки |

### 2.7 Трансляция в машинный код

```
...
 "/usr/bin/clang-22" -cc1as -triple x86_64-redhat-linux-gnu -filetype obj -main-file-name main.c -target-cpu x86-64 -fdebug-compilation-dir=/home/birewon/BMSTU/Proga/ptp-lab2 -dwarf-version=5 -mrelocation-model static -o main.o main.s
...
```

| Разбор выполнения команды |  |
|---------------------------|--|
| Вход | main.s |
| Выход | main.o |
| Назначение | Преобразование программы с языка ассемблера в машинный код |
| Имя утилиты | clang-22 с параметром -cc1as |
| Способ передачи параметров | Через ключи командной строки |

### 2.8 Компоновка

```
...
 "/usr/bin/ld" --hash-style=gnu --build-id --eh-frame-hdr -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o a.out /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crt1.o /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crti.o /usr/bin/../lib/gcc/x86_64-redhat-linux/16/crtbegin.o -L/usr/bin/../lib/clang/22/lib/x86_64-redhat-linux-gnu -L/usr/bin/../lib/gcc/x86_64-redhat-linux/16 -L/usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64 -L/lib/../lib64 -L/usr/lib64 -L/lib -L/usr/lib -lm main.o -lgcc --as-needed -lgcc_s --no-as-needed -lc -lgcc --as-needed -lgcc_s --no-as-needed /usr/bin/../lib/gcc/x86_64-redhat-linux/16/crtend.o /usr/bin/../lib/gcc/x86_64-redhat-linux/16/../../../../lib64/crtn.o
...
```

| Разбор выполнения команды |  |
|---------------------------|--|
| Вход | main.o, системные объектные файлы |
| Выход | a.out |
| Назначение | Совмещает несколько объектный файлов в 1. Связывает переменные и функции. Добавляет дополнительный код. |
| Имя утилиты | ld |
| Способ передачи параметров | Через ключи командной строки и файлы |

| Имя | Назначение |
|-----|------------|
| main.o | Объектный файл |
| crt1.o | Код запуска |
| crti.o | Начальная часть кода инициализации |
| crtbegin.o | Служебные функции для запуска и завершения |
| crtend.o | Служебные функции для завершения |
| crtn.o | Часть кода инициализации |

| Имя в команде | Назначение |
|---------------|------------|
| \-lm | Математическая библиотека |
| \-lgcc | Вспомогательные функции, используемые компилятором gcc |
| \-lgcc_s | Вспомогательная библиотека gcc |
| \-lc | Стандартная библиотека в языке C |

## 3 Дополнительные задания

#### 3.1

```
$ ldd a.out

	linux-vdso.so.1 (0x00007f26ab081000)
	libm.so.6 => /lib64/libm.so.6 (0x00007f26aaf49000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f26aad50000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f26ab083000)
```

#### 3.2

```
as --help
Usage: as [option...] [asmfile...]
Options:
  -a[sub-option...]	  turn on listings
                      	  Sub-options [default hls]:
                      	  c      omit false conditionals
                      	  d      omit debugging directives
                      	  g      include general info
                      	  h      include high-level source
                      	  i      include ginsn and synthesized CFI info
                      	  l      include assembly
                      	  m      include macro expansions
                      	  n      omit forms processing
                      	  s      include symbols
                      	  =FILE  list to FILE (must be last sub-option)
```

```
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -lm -save-temps -v -Wa,-adhln=main.lst main.c
```

#### 3.3

```
ld --help | grep Map
  -Map FILE/DIR               Write a linker map to FILE or DIR/<outputname>.map
```

```
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -lm -save-temps -v -Wl,-Map=main.map main.c
```

#### 3.4

|  | Размер, Кб |
|--|------------|
| g0 | 13 |
| g1 | 14 |
| g2 | 15 |
| g3 | 60 |

