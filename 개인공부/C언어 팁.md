---
title: C언어 팁
date: 2024-08-13
tags:
  - "#개인공부"
  - "#C언어"
  - "#코딩"
related notes: "[[개인 공부]]"
Review: 
비고:
---

###### C에서 짝수 판별을 이진수로 하면 빠르다!

    for (i = 0; i < LENGTH; i++) {
        if (~arr[i]&1) {
            printf("%d ", arr[i]);
        }
    }


## C 언어 커리큘럼
진짜로 C++ 공부할때 도움되는거 얘기하보자면

초급:
- C++ 기본기 (template, iterator, threads 까지)
- CMake 다루는 방법
- C++ 17
- 최종: GTA 3 소스코드 보고 공부

중급:
- CPU/mem profiler
- SIMD, OpenMP, MPI, CUDA
- assm, pybind
- 최종: Chromium 소스코드 보고 공부

고급:
- disassembly, godbolt
- 사실 나도 몰라…
- 20년차 C++ 엔지니어도 자기가 초보라는데…
- 내가 뭐라고…