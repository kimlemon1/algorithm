// ofstream : 입력용 
// ifstream : 읽기용
// fstream : 입력, 출력 둘 다 가능
// 다 stream으로 처리한다
// 하나의 class로 생각!
// 총 6개 파라미터
// ios::out, ios::in  가장 기본
// ios::out : for writing 
// ios::in : for reading

// text file :
// write : << 으로 stream에 넣는다
// read: getline으로 한줄씩 읽는다
// 특히 while문 안에 넣어서 한 줄씩 끝까지 받기 가능 eof만나면 false 출력한다!

// Binary files
// 파일 object에 파라미터 ios::binary만 추가하면 된다
// file.read(memblock, size) : memblock: 현재 위치, size : 얼마나 읽을지

