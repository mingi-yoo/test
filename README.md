# GCNSim

A GCN Accelerator Simulator with DRAMsim3.

## 1. 기본 구조

### RunSimulator.cpp (메인 함수)

Argument 처리 및 기본적인 모듈 로드, 시뮬레이션 수행

1. IniParser에서 ini 설정 불러옴.
2. DataReader에서 data 불러옴.
3. DRAMInterface를 이용해서 DRAM Simulation 객체 생성
4. 추후 추가할 것!!

###  DRAMInterface.cpp (DRAMsim3 호출 및 활용 인터페이스)

1. 생성자에서 설정파일을 기준으로 DRAMsim3를 호출... 생성자에서 dramsim에 callback function 넣는 것도 이곳에서 이루어짐

2. void updateCycle() {};

3. void DRAMRequest(주소, is_write) {}; => DRAM에 읽기 쓰기 요청

4. bool IsReadComplete() {};

5. unit64_t GetReadData() {}; => 읽어들인 주소 반환

6. ReadCompleteCallback() {}; => dramsim read callback

7. WriteCompleteCallback() {}; => dramsim write callback

   참고) DRAMSIMInterface 내부에는 read_complete 값이 존재해서 이것을 통해 접근 가능

### GlobalBuffer.cpp (전체 버퍼)

```c++
private:
	uint64_t gbsize;
	DRAMInterface *dram;
```

### Accelerator.cpp (accelerator)

```c++
private:
	uint64_t tot_acc;
	DRAMInterface *dram;
```

### AController.cpp (Adjacency Matrix 처리)

용량이 크기 때문에 Global Buffer에 일부 저장하는 방식으로 처리

`EdgeReader`와 `VertexReader`를 활용하여 처리

`XWReader`를 통해서 acceleration 대상 총 집합 완료

AController header

```c++
class AController {
public:
	AController(int id,
				DRAMInterface *dram, 
				DataController *data, 
				GlobalBuffer *gb, 
				Accelerator *acc);
	~AController();
	void RunController();
private:
	int id; // for multi processing
	DRAMInterface *dram;
	DataController *data;
	GlobalBuffer *gb;
	Accelerator *acc;
	VertexReader *vr;
	EdgeReader *er;
	XWReader *xwr;
};
```

AController Constructor

```c++
AController::AController(int id,
						 DRAMInterface *dram, 
						 DataController *data, 
						 GlobalBuffer *gb, 
						 Accelerator *acc) {
	this->id = id;
	this->dram = dram;
	this->data = data;
	this->gb = gb;
	this->acc = acc;
	vr = new VertexReader(id, dramm);
	er = new EdgeReader(id, dram);
	xwr = new XWReader(id, gb, acc);
}
```

### VertexReader (Vertex 읽어들임)

VertexReader.h

```c++
class VertexReader {
public:
	VertexReader(int id, DRAMInterface *dram);
	~VertexReader();
	void ReceiveData(queue<uint64_t> data);
	void Request();
private:
	int id;
	int q_space;
	bool req_need;
	DRAMInterface *dram;
	queue<uint64_t> vq; //save vertex data from DRAM
};
```

### EdgeReader (Edge 읽어들임)

EdgeReader.h

```c++
class EdgeReader {
public:
	EdgeReader(int id, DRAMInterface *dram);
	~EdgeReader();
	void ReceiveData(queue<uint64_t> data);
	void ReceiveData(uint64_t vertex);
private:
	int id;
	uint64_t cur_v;
	uint64_t prev_v;
	DRAMInterface *dram;
	queue<uint64_t> eq; //save edge data from DRAM
};
```

### XWReader (계산된 XW를 읽어들임)

```c++
class XWReader {
public:
	XWReader(int id, GlobalBuffer *gb, Accelerator *acc);
	~XWReader();
private:
	GlobalBuffer *gb;
	Accelerator *acc;
};
```

### XController

x와 w를 읽어들이고 이를 acceleration을 통해서 계산하여 XW를 계산

```c++
class XController {
public:
	XController(int id,
				DRAMInterface *dram,
				DataController *data, 
				GlobalBuffer *gb, 
				XBuffer *xb, 
				Accelerator *acc);
	~XController();
private:
	int id = id;
	DRAMInterface *dram;
	DataController *data;
	GlobalBuffer *gb;
	XBuffer *xb;
	Accelerator *acc;
	XReader *xr;
	WReader *wr;
};
```

### XBuffer

x 크기가 크기 때문에 나누어서 buffer를 통해 이용... dram 연결 필요

```c++
class XBuffer {
public:
	XBuffer(uint64_t xbsize, DRAMInterface *dram);
	~XBuffer();
private:
	int id;
	uint64_t xbsize;
	DRAMInterface *dram;
};
```

### XReader

```c++
class XReader {
public:
	XReader(int id, DRAMInterface *dram);
	~XReader();
private:
	int id;
	DRAMInterface *dram;
	queue<uint64_t> xq; //save x data from DRAM
};
```

### WReader

```c++
class WReader {
public:
	WReader(GlobalBuffer *gb, Accelerator *acc);
	~WReader();
private:
	GlobalBuffer *gb;
	Accelerator *acc;
};
```



## 2. Class Diagram 및 Flow

추후 진행해가면서 추가할 것!



## #. 수정 및 개발 현황

### (7/17)

* .cpp 파일 추가
* 메인함수 (RunSimulator.cpp) 추가
* DRAMInterface.* 약간 수정

### (7/20)

* DataController.h, DataController.cpp 추가
  + 데이터를 컨트롤러에게 분배하는 역할
* Common.h 추가
* Acontroller.cpp 내 RunController 함수 작성중

### (7/22)

* multiprocessing(simulator상에서)을 위한 id 추가
* RunController 계속 작성중
* VertexReader, EdgeReader 데이터 passing 처리중
