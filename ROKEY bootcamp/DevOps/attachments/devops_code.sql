-- 유저 테이블 생성
DROP TABLE IF EXISTS usertbl;
CREATE TABLE usertbl
(
    userID CHAR(8) NOT NULL,
    name VARCHAR(10) NOT NULL,
    birthYear INT NOT NULL,
    CONSTRAINT PRIMARY KEY PK_usertbl_userID (userID)
);

-- 구매 테이블 생성
CREATE TABLE buytbl
(
    num INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    userid CHAR(8) NOT NULL,
    prodName CHAR(6) NOT NULL,
    groupName CHAR(4) NULL,
    price INT NOT NULL,
    amount SMALLINT NOT NULL,
    FOREIGN KEY(userid) REFERENCES usertbl(userID)
);

-- 데이터 추가
INSERT INTO usertbl VALUES('LSG', '이승기', 1987);
INSERT INTO usertbl VALUES('KBS', '김범수', 1979);
INSERT INTO usertbl VALUES('KKH', '김경호', 1971);

INSERT INTO buytbl VALUES(NULL, 'KBS', '운동화', NULL, 30, 2);
INSERT INTO buytbl VALUES(NULL, 'KBS', '노트북', '전자', 1000, 1);
INSERT INTO buytbl VALUES(NULL, 'KKH', '모니터', '전자', 200, 1);
