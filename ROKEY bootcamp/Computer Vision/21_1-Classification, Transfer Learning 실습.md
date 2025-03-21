#컴퓨터비전 
[[Ai,컴퓨터 비전]]
last modification: 2024-09-11

움... 이걸 어떻게... 공부하지...?
# Classification
오브젝트 디텍션을 다음주에

프로젝트로 배우는 딥러닝 컴퓨터비전 교재 이용

[Site Unreachable](https://campus.programmers.co.kr/app/courses/24550/curriculum/lessons/341929#part-72235)
근데 따로 깃으로 다운로드 할 수 있음

ch1
[Google Colab](https://colab.research.google.com/drive/1W1d0Jb_6Bfslocur98cFHoORYxG9-v-Y?usp=drive_open)
[Site Unreachable](https://colab.research.google.com/drive/1bk3Hr7ou_NypZgd1DiGiFjZAnp3VKjBU#scrollTo=DLSH2qlQp7JU)
ch2
[Site Unreachable](https://colab.research.google.com/drive/1T4JvUjaiZq9YCRrXopmEYCdZxEZFI1Sv)
ch3
[Site Unreachable](https://colab.research.google.com/drive/1zBW7quIesZj5Vm9me9-UjmZIywVDTbOs#scrollTo=ntIfOPzuNvUW)
[Site Unreachable](https://colab.research.google.com/drive/1lBJWo9aEDXTnlmyNj_ZRTr1jVao68R5c#scrollTo=C6fpTUpk_TKf)


# Transfer Learning
ch5
[Site Unreachable](https://colab.research.google.com/drive/1cF8eK2RauRBw7fUoDCOhCOjYcUWQzP8T#scrollTo=kESNVsD5w93-)
###### ch5 코드
```python
import os
import torch
import torch.optim as optim
import torchvision.transforms as transforms
import torch.nn.functional as F
from tqdm import tqdm

from .Model_Class_From_the_Scratch import MODEL_From_Scratch  # 처음부터 모델 학습을 위한 클래스
from .Model_Class_Transfer_Learning_MobileNet import MobileNet  # 전이 학습을 위한 MobileNet 모델 클래스
from .Dataset_Class import PyTorch_Classification_Dataset_Class as Dataset  # 데이터셋 클래스를 임포트

class PyTorch_Classification_Training_Class():
    def __init__(self
                , dataset_dir = "/content/Recycle_Classification_Dataset"  # 데이터셋 경로
                , batch_size = 16  # 배치 사이즈 설정
                , train_ratio = 0.75  # 훈련 데이터 비율 설정
                ):
        # 데이터셋 경로가 존재하지 않으면, GitHub에서 데이터셋을 클론
        if not os.path.isdir(dataset_dir):
            os.system("git clone https://github.com/JinFree/Recycle_Classification_Dataset.git")
            os.system("rm -rf ./Recycle_Classification_Dataset/.git")  # .git 폴더 삭제
            dataset_dir = os.path.join(os.getcwd(), 'Recycle_Classification_Dataset')  # 새로운 경로 설정
        
        # GPU 사용 가능 여부 확인 및 장치 설정
        self.USE_CUDA = torch.cuda.is_available()
        self.DEVICE = torch.device("cuda" if self.USE_CUDA else "cpu")

        # 데이터 변환 설정 (이미지 크기 조정, 랜덤 자르기, 텐서 변환 및 정규화)
        self.transform = transforms.Compose([
                transforms.Resize(256),
                transforms.RandomCrop(224),
                transforms.ToTensor(),
                transforms.Normalize(mean=[0.485, 0.456, 0.406],
                        std=[0.229, 0.224, 0.225]) 
                ])
        
        # 데이터셋 클래스 초기화 및 라벨 맵 저장
        dataset = Dataset(dataset_dir=dataset_dir, transform=self.transform)
        dataset.__save_label_map__()
        self.num_classes = dataset.__num_classes__()  # 클래스 개수 가져오기

        # 훈련 및 테스트 데이터셋 분할
        train_size = int(train_ratio * len(dataset))
        test_size = len(dataset) - train_size
        train_dataset, test_dataset = torch.utils.data.random_split(dataset, [train_size, test_size])

        # DataLoader를 사용하여 데이터셋 로드
        self.train_loader = torch.utils.data.DataLoader(
            train_dataset, 
            batch_size=batch_size, 
            shuffle=True
        )
        self.test_loader = torch.utils.data.DataLoader(
            test_dataset, 
            batch_size=batch_size, 
            shuffle=False
        )
        
        self.model = None  # 모델 초기화
        self.model_str = None  # 모델 파일 이름 초기화
        
    # 네트워크 준비 함수: Scratch에서 학습할지, 전이 학습할지 결정
    def prepare_network(self, is_scratch=True):
        if is_scratch:
            self.model = MODEL_From_Scratch(self.num_classes)  # 처음부터 학습할 경우
            self.model_str = "PyTorch_Training_From_Scratch"
        else:
            self.model = MobileNet(self.num_classes)  # 전이 학습을 사용할 경우
            self.model_str = "PyTorch_Transfer_Learning_MobileNet"
        self.model.to(self.DEVICE)  # 모델을 장치에 할당 (GPU 또는 CPU)
        self.model_str += ".pt"  # 모델 파일 이름에 확장자 추가
    
    # 네트워크 학습 함수
    def training_network(self, learning_rate=0.0001, epochs=10, step_size=3, gamma=0.3):
        # 모델이 준비되지 않았다면, 기본적으로 전이 학습으로 준비
        if self.model is None:
            self.prepare_network(False)
        
        # 옵티마이저와 학습률 스케줄러 설정
        optimizer = optim.Adam(self.model.parameters(), lr=learning_rate)
        scheduler = optim.lr_scheduler.StepLR(optimizer, step_size=step_size, gamma=gamma)
        acc = 0.0  # 최적의 정확도 저장을 위한 변수 초기화

        # 지정한 에포크 수만큼 학습
        for epoch in range(1, epochs + 1):
            self.model.train()  # 모델을 학습 모드로 설정
            for data, target in tqdm(self.train_loader):  # 훈련 데이터에 대해 반복
                data, target = data.to(self.DEVICE), target.to(self.DEVICE)  # 데이터를 장치로 이동
                optimizer.zero_grad()  # 이전의 기울기 초기화
                output = self.model(data)  # 모델을 통한 예측
                loss = F.cross_entropy(output, target)  # 손실 함수 계산
                loss.backward()  # 역전파를 통해 기울기 계산
                optimizer.step()  # 옵티마이저를 통해 가중치 업데이트
            scheduler.step()  # 학습률 스케줄러 업데이트
            
            self.model.eval()  # 모델을 평가 모드로 설정
            test_loss = 0
            correct = 0
            with torch.no_grad():  # 평가 시 기울기 계산 비활성화
                for data, target in tqdm(self.test_loader):  # 테스트 데이터에 대해 반복
                    data, target = data.to(self.DEVICE), target.to(self.DEVICE)  # 데이터를 장치로 이동
                    output = self.model(data)  # 모델을 통한 예측
                    test_loss += F.cross_entropy(output, target, reduction='sum').item()  # 총 손실 계산
                    pred = output.max(1, keepdim=True)[1]  # 가장 높은 확률을 가진 클래스 예측
                    correct += pred.eq(target.view_as(pred)).sum().item()  # 정확도 계산

            # 테스트 손실 및 정확도 출력
            test_loss /= len(self.test_loader.dataset)
            test_accuracy = 100. * correct / len(self.test_loader.dataset)
            print('[{}] Test Loss: {:.4f}, Accuracy: {:.2f}%'.format(epoch, test_loss, test_accuracy))

            # 최적의 모델 저장
            if acc < test_accuracy or epoch == epochs:
                acc = test_accuracy
                torch.save(self.model.state_dict(), self.model_str)
                print("model saved!")

# 메인 함수: 클래스 초기화 및 학습 실행
if __name__ == "__main__":
    training_class = PyTorch_Classification_Training_Class()
    training_class.prepare_network(True)  # 처음부터 학습
    training_class.training_network()  # 네트워크 학습
```


여기부터 보지는 않음
[Google Colab](https://colab.research.google.com/drive/1VvpWq4xByajuc2dFV8b-HKcGvNz45pJq)
ch8


5:56