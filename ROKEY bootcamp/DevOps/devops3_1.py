import pymysql

# Global variable declarations
conn, cur = None, None
data1, data2, data3, data4 = "", "", "", ""
sql = ""

# Main code
conn = pymysql.connect(host='127.0.0.1', user='tester2', password='0000', db='TEST', charset='utf8')
cur = conn.cursor()

# Drop the table if it exists and recreate it with the correct columns
cur.execute("DROP TABLE IF EXISTS userTable;")
cur.execute('''
    CREATE TABLE userTable (
        id CHAR(4),
        userName CHAR(15),
        email VARCHAR(50),
        birthYear INT
    );
''')

while True:
    data1 = input("사용자 ID ==> ")
    if data1 == "":
        break
    data2 = input("사용자 이름 ==> ")
    data3 = input("사용자 이메일 ==> ")
    data4 = input("사용자 출생년도 ==> ")
    sql = "INSERT INTO userTable (id, userName, email, birthYear) VALUES ('" + data1 + "','" + data2 + "','" + data3 + "','" + data4 + "')"
    cur.execute(sql)

conn.commit()
conn.close()
