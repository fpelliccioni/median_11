# Median of 11 Stats

## Compilation time:

### Non forced inlined version:

- MacBook:      3489.88s user 34.92s system 99% cpu 58:56.72 total  (Inlined anyways)
- Thinkpad:      106.34s user  2.53s system 99% cpu  1:49.44 total
- Thinkstation:   64.13s user  1.04s system 99% cpu  1:05.34 total


### Force inline Version:

- MacBook:       3348.14s user 31.38s system 99% cpu   56:23.28 total
- Thinkpad:      3950.09s user 22.48s system 99% cpu 1:06:29.33 total
- Thinkstation:  1600.24s user  9.63s system 99% cpu   26:52.84 total


## Assembly code size:

### Non forced inlined version:

- MacBook:      11 MiB
- Thinkpad:     38 MiB
- Thinkstation: 38 MiB

### Force inline Version:

- MacBook:      11 MiB
- Thinkpad:      7 MiB
- Thinkstation:  7 MiB

## Executable/binary size:

### Non forced inlined version:

- MacBook:      ?? MiB
- Thinkpad:     ?? MiB
- Thinkstation: 38 MiB

### Force inline Version:

- MacBook:      ?? MiB
- Thinkpad:     ?? MiB
- Thinkstation: ?? MiB

### How the code is compiled:

- In systems with Clang: `clang++ --std=c++17 -O3 <file.cpp>`
- In systems with GCC:   `g++ --std=c++17 -O3 <file.cpp>`

## Platforms:

### Thinkpad

Intel(R) Core(TM) i7-6820HQ CPU @ 2.70GHz, (Skylake-H R0) {Skylake}, 14nm

```
gcc --version
gcc (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4)
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### Thinkstation

AMD Ryzen Threadripper PRO 5995WX 64-Cores, (Chagall A2) [Zen 3], 7nm

```
gcc --version
gcc (GCC) 12.2.1 20221121 (Red Hat 12.2.1-4)
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### MacBook Pro

Intel(R) Core(TM) i9-9980HK CPU @ 2.40GHz


```
clang --version
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: x86_64-apple-darwin22.2.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```



