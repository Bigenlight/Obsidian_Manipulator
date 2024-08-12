# import pymysql

# # MySQL 데이터베이스 연결
# db = pymysql.connect(host='127.0.0.1', user='tester2', password='0000', port=3306 ,db='shop', charset='utf8') 

# # 데이터에 접근
# cursor = db.cursor()

# # SQL query 작성
# sql = "select * from test"
# # SQL query 실행

# cursor.execute(sql)

# # db 데이터 가져오기
# res = cursor.fetchall() #모든 행 가져오기
# #cursor.fetchone() # 하나의 행만 가져오기
# #cursor.fetchmany(id) # n개의 데이터 가져오기

# for x in res:
#     print(x)

# # 수정 사항 db에 저장
# db.commit()
# # Database 닫
# db.close()

import mysql.connector
mydb = mysql.connector.connect(
host="localhost",
user="tester2",
passwd="0000",
database="TEST"
)
mc = mydb.cursor()
#mc.execute("ALTER TABLE test AUTO_INCREMENT=1")
mc.execute("SELECT * FROM test")
mr = mc.fetchall()
for x in mr:
    print(x)