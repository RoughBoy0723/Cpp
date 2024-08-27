# 컴파일러
CXX = g++

# 컴파일러 플래그

# 헤더 파일
HEADERS = Account.h AccountHandler.h BankingCommonDecl.h NormalAccount.h HighCreditAccount.h

# 소스 파일
SOURCES = BankingSystemMain.cpp Account.cpp AccountHandler.cpp

# 오브젝트 파일
OBJECTS = $(SOURCES:.cpp=.o)

# 실행 파일 이름
TARGET = BankingSystem

# 기본 타겟: 실행 파일 만들기
all: $(TARGET)

# 실행 파일을 만들기 위한 규칙
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

# 각 소스 파일에 대해 오브젝트 파일 만들기 규칙
%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@

# clean: 중간 파일과 실행 파일 삭제
clean:
	rm -f $(OBJECTS) $(TARGET)

# make clean 실행 시 오브젝트 파일과 실행 파일을 삭제함
.PHONY: all clean
