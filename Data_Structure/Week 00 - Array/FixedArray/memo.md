- 이제부터 md파일을 활용하여 과제를 진행해보도록 하겠다!
<br/>
<br/>
# [ 궁금증 & 해결 ]
- Q0. arr이 존재하지 않을 경우 return 할 때 여태까지 해왔던 것처럼, malloc을 해주고 if(!arr)일 경우 return을 했으나,
malloc함수가 상당히 느린 함수 중 하나라는 것을 알게되고 난 뒤, malloc하기 전 if(size== 0) return 0;을 해 주면 어떤가 더 효율적이지 않은가 생각이 듦. 이렇게 해도 될까, 안된다면 그 이유는 무엇일까?  
  
  
  A0. (승현 생각) if(arr == NULL)을 사용했을 시 '1)size가 0일 때, 2) size는 0이 아니긴 하나 메모리 부족으로 malloc 호출이 실패할 때' 이렇게 두 가지 경우를 잡아주는다는 것을 깨달음.  
    따라서 해왔던대로 malloc해준 뒤 if(arr==NULL) 해주자.  

<br/>

- Q1. 주어진 구조체에서의 size의 자료형은 size_t 였는데, 구현해야하는 함수들의 prototype을 보면 int index임. 어떻게해야하나?  
  
  
  A1.

<br/>



<br/>
<br/>
<br/>
# [ 0. 고정 배열을 생성하는 함수: creatFixedArray ]  
<br/>
## 0.0 prototype
- FixedArray *createFixedArray(size_t size)
<br/>
## 0.1 고려해야 할 점  
  
  
### 0.1.1 전반적인 구현
- malloc함수는 메모리를 할당만 해줄 뿐 초기화는 해주지 않아서 메모리 할당을 받은 포인터 변수의 값은 쓰레기 값들로 채워짐.  
    -> malloc으로 메모리 할당을 해준 변수를 초기화 시켜주는 함수인 memset()사용 또는 메모리 할당과 동시에 NULL 값으로 초기화 시켜주는 함수 사용  
    (처음에 선언할 때만 사용가능한 = {0}을 써서 에러 남)
  
  
### 0.1.2 예외 처리
- size를 받아 malloc 할당해준 배열이 존재하지 않을 경우 return (즉, 받은 size가 0일 경우), 처음에 if(!fixedArray->storage)가 아닌 그냥 if(!fixedArray)라고 쓰는 실수 했었음

[ ?. 구조체 내용을 깨끗히 비우는 함수: clearFixedArray ]

## ?.0 prototype

## 0.1 고려해야 할 점

-struct 구조체이름 변수이름 = { 0, };    // 구조체 변수의 내용을 모두 0으로 초기화
                                      // 단 malloc 함수로 할당한 메모리에는 사용할 수 없음
