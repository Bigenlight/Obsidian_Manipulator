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