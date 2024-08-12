#DevOps
[[DevOps 강의]]

![[DevOps프로그래밍_3차.pdf]]

## 웹 - FLASK
Python으로 작성된 오픈 소스 웹 프레임워크
• 코드도 비교적 단순하며 API 서버 구축에 편리함
• 다른 프레임 워크에 비해 비교적 확장하기 용이하고 유연함
[Welcome to Flask — Flask Documentation (2.2.x)](https://flask.palletsprojects.com/en/2.2.x)
### 가상 환경 설정
sudo apt install python3-venv
python3 -m venv webwork
###### 실행
cd webwork/
source ./bin/activate
![[Pasted image 20240812140614.png|300]]
###### 나가기
deactivate

해당 경로에 작업 가능
![[Pasted image 20240812141152.png]]
터미널도 자동으로 가상 환경으로 감

만약 권한이 안된다면 chmod 777 ./경로 이용할 것

#### FLASK 설치
pip install Flask

html : 웹 사이트 프레임
css : 데코레이션
cgi(common gate inteerface) : 동적인 사이트를 위한 코드
#### 웹 코딩

```python
from flask import Flask, render_template
app = Flask(__name__)

@app.route('/') # 웹 주소

def hello_world():
	return 'Hey'
	
if __name__ == '__main__':
	app.run()
```
사이트 ip 주소 복사하여 인터넷 창에 붙여넣기
![[Pasted image 20240812145408.png|400]]
[127.0.0.1:5000](http://127.0.0.1:5000/)

만약 5000을 이미 누가 쓰고 있다면
app.run(port = 10001)
이런 식으로 뒤에 포트를 바꿀 것

##### 폴더 생성
static: css, js 파일들 
templates: html 파일들
이때 폴더 철자가 틀리면 작동 안함.
![[Pasted image 20240812145949.png|200]]
```python
# Test1.py
from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def hello_world():
	return render_template('index.html')

if __name__ == '__main__':
	app.run(debug=True)
```
templates 폴더 안에 index.html 생성
```html
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<title>hi</title>
</head>
<body>
	<h1>hello world</h1>
</body>
</html>
```

#### 변수 넣기
파이썬 파일에서 name 변수를 지정하고
name_ = '최태오'
return render_template('index.html', name=name_)
html 파일에서 {{name}}포함하면 파이썬 코드 값이 들어감
\<h1>hello world {{name}}</h1>
![[Pasted image 20240812152712.png]]

##### 두 웹페이지를 만들어서 서로 왔다 갔다
[[Test1.py]]
[[index.html]]
[[user.html]]
![[Pasted image 20240813001930.png]]