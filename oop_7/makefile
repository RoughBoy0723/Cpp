# 컴파일러 설정
CXX = g++

# 타겟 이름 (최종 실행 파일)
TARGET = Account

# 객체 파일 목록
OBJS = main.o Account.o AccountHandler.o

# 기본 타겟 (Account 실행 파일 생성)
all: $(TARGET)

# Account 실행 파일 생성 규칙
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

# 객체 파일 생성 규칙
main.o: main.cpp Account.h AccountHandler.h
	$(CXX) -c main.cpp -o main.o

Account.o: Account.cpp Account.h
	$(CXX) -c Account.cpp -o Account.o

AccountHandler.o: AccountHandler.cpp AccountHandler.h Account.h
	$(CXX) -c AccountHandler.cpp -o AccountHandler.o

# 클린 규칙 (빌드 결과물 삭제)
clean:
	rm -f $(TARGET) *.o
