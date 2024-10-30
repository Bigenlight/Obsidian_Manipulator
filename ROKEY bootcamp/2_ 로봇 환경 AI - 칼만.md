#RobotAI
[[Robot Ai]]
last modification: 2024-10-30

![[로봇_환경_AI_기초_실습_칼만필터.pdf]]

###### 확률함수
p(x)
x1, x2 같은 경우를 각각 **셀**이라하면
p(x1) = 0.2이면 x1의 경우 확률이 0.2라는 뜻.

### 베이즈 정리
[베이즈 정리를 이해하는 가장 쉬운 방법 - YouTube](https://youtu.be/Y4ecU7NkiEI?si=q3F3fY6KWAjTUSRN)
![[Pasted image 20241030150814.png|400]]

![[Pasted image 20241030150850.png|300]]
![[Pasted image 20241030150905.png]]

![[Pasted image 20241030150948.png|400]]
![[Pasted image 20241030151022.png|500]]

## 칼만 필터
[Why Use Kalman Filters? | Understanding Kalman Filters, Part 1 - YouTube](https://youtu.be/mwn8xhgNpFY?si=cqWrTW4Bm2nYEf5j)
우리가 예측하고자 하는 시스템의 동역학이나 측정값이 가진 불확실성(노이즈, 잡음)을 고려하여, 이 두 데이터의 적절한 균형(최적값)을 찾기 위해 사용.
 즉, 시스템 동역학 모델과 측정 값의 노이즈를 최대한 제거(필터링)하면서, 불완전한 모델 예측 값과 불완전한 측정값 사이의 어딘가에 있는 최적의 시스템 상태를 추정하는 것.